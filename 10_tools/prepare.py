#!/usr/bin/env python3
"""Preserve local inputs and inventory a thin 32-bit Mach-O; no disassembler needed."""
import argparse
import csv
import hashlib
import json
import platform
import re
import shutil
import struct
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
WORKSPACE = ROOT.parent
EXPECTED = "33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890"
INPUTS = [
    ("kernel", "ref/openstep/ps2/mach_kernel", "03_original/x86/binaries/mach_kernel"),
    ("same_kernel", "openstep-matrox-remade/reference/original-binaries/mach_kernel.OS42-20260819", "03_original/x86/binaries/mach_kernel"),
    ("ida_snapshot", "ref/openstep/ps2/mach_kernel.i64", "05_ida/snapshots/ps2-mach_kernel.i64"),
    ("ida_snapshot", "openstep-matrox-remade/reference/original-binaries/mach_kernel.OS42-20260819.i64", "05_ida/snapshots/matrox-mach_kernel.i64"),
]


def sha256(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def write_json(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")


def tsv(path, fields, rows):
    with path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fields, delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def layout():
    directories = [
        "01_resources/upstream", "01_resources/archives", "01_resources/manifests",
        "01_resources/local_mirrors", "04_ghidra/projects", "04_ghidra/notes",
        "05_ida/snapshots", "05_ida/databases", "05_ida/notes",
        "06_reconstruction/evidence", "07_kernel/src/common", "07_kernel/include",
        "07_kernel/config", "08_build/configs", "08_build/toolchains", "08_build/logs",
        "08_build/artifacts", "09_validation/static", "09_validation/boot",
        "09_validation/regression", "09_validation/images", "09_validation/reports",
    ]
    for arch in ("x86", "sparc", "future_arch"):
        directories.extend([
            f"03_original/{arch}/binaries", f"03_original/{arch}/inventory",
            f"04_ghidra/exports/{arch}", f"05_ida/exports/{arch}",
            f"07_kernel/src/arch/{arch}",
        ])
    for name in directories:
        directory = ROOT / name
        directory.mkdir(parents=True, exist_ok=True)
        (directory / ".gitkeep").touch(exist_ok=True)
    for name in ("headers", "makefiles", "nextdev-doc"):
        link = ROOT / "01_resources/local_mirrors" / name
        target = Path("../../../ref/openstep") / name
        if not link.is_symlink() and not link.exists():
            link.symlink_to(target, target_is_directory=True)
        elif not link.is_symlink() or link.readlink() != target:
            raise ValueError(f"Existing local mirror differs: {link}")


def preserve():
    rows = []
    for kind, source, destination in INPUTS:
        src, dst = WORKSPACE / source, ROOT / destination
        before = src.stat()
        digest = sha256(src)
        if kind in ("kernel", "same_kernel") and digest != EXPECTED:
            raise ValueError(f"Baseline hash changed: {source}")
        if dst.exists():
            if sha256(dst) != digest:
                raise ValueError(f"Refusing to overwrite a different snapshot: {destination}")
        else:
            # Exclusive create; never overwrite snapshots, including partial prior attempts.
            with src.open("rb") as reader, dst.open("xb") as writer:
                shutil.copyfileobj(reader, writer)
        after = src.stat()
        stable = (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns)
        if not stable or sha256(src) != digest or sha256(dst) != digest:
            raise ValueError(f"Input changed during copy; inspect snapshot: {source}")
        rows.append(dict(kind=kind, source=source, destination=destination,
                         sha256=digest, size=after.st_size,
                         database_input_verified=False if kind == "ida_snapshot" else None))
    write_json(ROOT / "03_original/manifest.json", {"schema": 1, "files": rows})
    return rows


def parse_macho(path):
    data = path.read_bytes()
    if data[:4] == b"\xce\xfa\xed\xfe":
        endian = "<"
    elif data[:4] == b"\xfe\xed\xfa\xce":
        endian = ">"
    else:
        raise ValueError("Expected thin 32-bit Mach-O; fat/64-bit input needs a separate importer")

    def unpack(fmt, offset):
        size = struct.calcsize(endian + fmt)
        if offset < 0 or offset + size > len(data):
            raise ValueError(f"Out-of-bounds structure at {offset}")
        return struct.unpack_from(endian + fmt, data, offset)

    def cstr(raw):
        return raw.split(b"\0", 1)[0].decode("utf-8", "replace")

    _, cpu, subtype, filetype, ncmds, sizeofcmds, flags = unpack("IiiIIII", 0)
    command_end = 28 + sizeofcmds
    if command_end > len(data):
        raise ValueError("Truncated load commands")
    commands, segments, sections, symtabs = [], [], [], []
    offset = 28
    for _ in range(ncmds):
        cmd, size = unpack("II", offset)
        if size < 8 or size % 4 or offset + size > command_end:
            raise ValueError("Invalid load command size")
        commands.append(dict(command=cmd, offset=offset, size=size))
        if cmd == 1:  # LC_SEGMENT
            if size < 56:
                raise ValueError("Truncated segment command")
            name, va, vmsize, fileoff, filesize, maxprot, initprot, count, segflags = unpack("16sIIIIiiII", offset + 8)
            if fileoff + filesize > len(data) or 56 + count * 68 > size:
                raise ValueError("Segment outside file or malformed section list")
            segments.append(dict(name=cstr(name), address=hex(va), size=vmsize,
                                 file_offset=fileoff, file_size=filesize,
                                 max_protection=maxprot, initial_protection=initprot, flags=segflags))
            for index in range(count):
                sname, sgname, addr, ssize, soff, align, reloff, nreloc, sflags, r1, r2 = unpack("16s16sIIIIIIIII", offset + 56 + index * 68)
                sections.append(dict(index=len(sections) + 1, segment=cstr(sgname), name=cstr(sname),
                                     address=hex(addr), size=ssize, file_offset=soff,
                                     alignment_exponent=align, relocation_offset=reloff,
                                     relocation_count=nreloc, flags=hex(sflags)))
        elif cmd == 2:  # LC_SYMTAB
            if size < 24:
                raise ValueError("Truncated symbol table command")
            symtabs.append(unpack("IIII", offset + 8))
        offset += size
    if offset != command_end:
        raise ValueError("Load command count/size mismatch")
    symbols = []
    for symoff, count, stroff, strsize in symtabs:
        if symoff + count * 12 > len(data) or stroff + strsize > len(data):
            raise ValueError("Symbol/string table outside file")
        strings = data[stroff:stroff + strsize]
        for index in range(count):
            strx, ntype, sect, desc, value = unpack("IBBHI", symoff + index * 12)
            if strx >= strsize or strings.find(b"\0", strx) == -1:
                raise ValueError("Invalid symbol name offset")
            debug = bool(ntype & 0xe0)
            defined_external = not debug and bool(ntype & 1) and (ntype & 0x0e) != 0
            symbols.append(dict(index=len(symbols), value=hex(value), name=cstr(strings[strx:]),
                                type=hex(ntype), section=sect, description=desc,
                                debug=int(debug), defined_external=int(defined_external)))
    text = [dict(file_offset=hex(match.start()), text=match.group().decode("ascii"))
            for match in re.finditer(rb"[\x20-\x7e]{8,}", data)]
    report = dict(schema=1, sha256=sha256(path), file_size=len(data),
                  endian="little" if endian == "<" else "big", bits=32,
                  cpu_type=cpu, cpu_subtype=subtype, filetype=filetype, flags=flags,
                  command_count=ncmds, commands_size=sizeofcmds, commands=commands,
                  segments=segments, sections=sections, nlist_count=len(symbols),
                  defined_external_symbol_count=sum(s["defined_external"] for s in symbols),
                  version_strings=[s for s in text if "NeXT Mach 4.2:" in s["text"]],
                  caveat="nlist entries are not function boundaries; no decompilation performed")
    return report, symbols, text


def verify():
    manifest = json.loads((ROOT / "03_original/manifest.json").read_text())
    for row in manifest["files"]:
        if sha256(ROOT / row["destination"]) != row["sha256"]:
            raise ValueError(f"Snapshot hash mismatch: {row['destination']}")
        src = WORKSPACE / row["source"]
        if sha256(src) != row["sha256"]:
            raise ValueError(f"Source changed since snapshot: {row['source']}")
    report, symbols, strings = parse_macho(ROOT / "03_original/x86/binaries/mach_kernel")
    saved = json.loads((ROOT / "03_original/x86/inventory/macho.json").read_text())
    if report != saved:
        raise ValueError("Saved Mach-O inventory differs from current parse")
    for name, expected in (("symbols.tsv", symbols), ("strings.tsv", strings)):
        with (ROOT / "03_original/x86/inventory" / name).open(newline="") as stream:
            actual = list(csv.DictReader(stream, delimiter="\t"))
        if actual != [{k: str(v) for k, v in row.items()} for row in expected]:
            raise ValueError(f"Saved {name} differs from current parse")
    print(f"PASS: {len(manifest['files'])} input records, snapshot/source hashes and Mach-O inventories")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--verify", action="store_true")
    args = parser.parse_args()
    if args.verify:
        verify()
        return
    layout()
    preserve()
    report, symbols, strings = parse_macho(ROOT / "03_original/x86/binaries/mach_kernel")
    out = ROOT / "03_original/x86/inventory"
    write_json(out / "macho.json", report)
    tsv(out / "symbols.tsv", ["index", "value", "name", "type", "section", "description", "debug", "defined_external"], symbols)
    tsv(out / "strings.tsv", ["file_offset", "text"], strings)
    write_json(ROOT / "08_build/environment.json", dict(
        captured_utc=datetime.now(timezone.utc).isoformat(), host=platform.platform(),
        tools={name: shutil.which(name) for name in (
            "git", "curl", "python3", "make", "gcc", "clang", "as", "ld", "mig",
            "llvm-objdump", "qemu-system-i386", "qemu-system-sparc", "qemu-system-m68k",
            "sparc-linux-gnu-gcc", "m68k-linux-gnu-gcc", "analyzeHeadless", "ida", "idat")},
        target_build_verified=False))
    verify()
    print(json.dumps({k: report[k] for k in ("cpu_type", "cpu_subtype", "nlist_count", "defined_external_symbol_count", "version_strings")}, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
