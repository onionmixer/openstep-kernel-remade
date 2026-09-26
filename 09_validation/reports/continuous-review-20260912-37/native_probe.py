"""Synthetic high-segment QEMU IDT probe; no kernel handler/frame injection.

All image layout, machine-code fixups, addresses and expected values use Python.
The copied FS store/IRETD opcodes are checked against the original Mach-O bytes.
"""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
QEMU = Path('/usr/bin/qemu-system-i386')
BASE, HW = 0xc0000000, 0x1000
PD, GDT, IDT, PT, UPT = 0x1000, 0x2000, 0x3000, 0x4000, 0x8000
ENTRY, HANDLER, FATAL = 0x100000, 0x101000, 0x102000
STACK, RECORD, RESULT, POINTER, POSTFLAGS = 0x180000, 0x190000, 0x190100, 0x198000, 0x198004
DATA, USER = 0x200000, 0x600100
PTE = UPT + ((USER >> 12) & 0x3ff) * 4
GDTR, IDTR = 0x2f00, 0x2f10


def u32(value):
    return struct.pack('<I', value & 0xffffffff)


def original(address, size):
    raw = (ROOT / '03_original/x86/binaries/mach_kernel').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    header = struct.unpack_from('<7I', raw)
    assert header[0] == 0xfeedface
    pos = 28
    for _ in range(header[4]):
        command, length = struct.unpack_from('<2I', raw, pos)
        if command == 1:
            vmaddr, _, fileoff, filesize = struct.unpack_from('<4I', raw, pos + 24)
            if vmaddr <= address and address + size <= vmaddr + filesize:
                start = fileoff + address - vmaddr
                return raw[start:start + size]
        pos += length
    raise AssertionError('original address not backed by file')


class Code:
    def __init__(self, base):
        self.base, self.raw, self.labels, self.fixups = base, bytearray(), {}, []
    def emit(self, data):
        self.raw.extend(bytes.fromhex(data) if isinstance(data, str) else data)
    def label(self, name):
        assert name not in self.labels
        self.labels[name] = self.base + len(self.raw)
    def call(self, label):
        self.emit('e8')
        self.fixups.append((len(self.raw), label))
        self.emit(bytes(4))
    def finish(self):
        for offset, label in self.fixups:
            delta = self.labels[label] - (self.base + offset + 4)
            struct.pack_into('<i', self.raw, offset, delta)
        return bytes(self.raw)
    def imm(self, opcode, value):
        self.emit(opcode)
        self.emit(u32(value))
    def store_imm(self, address, value):
        self.emit('c705')
        self.emit(u32(address) + u32(value))
    def load_eax(self, address):
        self.imm('a1', address)
    def store_eax(self, address):
        self.imm('a3', address)


def descriptor(base, access):
    limit = 0xfffff
    return struct.pack('<HHBBBB', limit & 0xffff, base & 0xffff, base >> 16 & 0xff,
                       access, 0xc0 | (limit >> 16), base >> 24)


def images(flags):
    assert flags in (2, 0x202, 0x402, 0x602)
    assert original(0x189d1b, 3) == bytes.fromhex('648819')
    assert original(0x186d7c, 1) == bytes.fromhex('cf')
    ram = bytearray(UPT + HW)
    for selector, base, access in ((8, BASE, 0x9b), (0x10, BASE, 0x93), (0x18, 0, 0x9b), (0x20, 0, 0x93), (0x50, 0, 0x93)):
        ram[GDT + selector:GDT + selector + 8] = descriptor(base, access)
    gdt_limit = 0x50 + 8 - 1
    struct.pack_into('<HI', ram, GDTR, gdt_limit, BASE + GDT)
    struct.pack_into('<HI', ram, IDTR, 256 * 8 - 1, BASE + IDT)
    for vector in range(256):
        offset = HANDLER if vector == 14 else FATAL
        ram[IDT + vector * 8:IDT + (vector + 1) * 8] = struct.pack('<HHBBH', offset & 0xffff, 8, 0, 0x8f, offset >> 16)
    for address, value in ((PD, PT | 3), (PD + (BASE >> 22) * 4, PT | 3), (PD + (USER >> 22) * 4, UPT | 7)):
        struct.pack_into('<I', ram, address, value)
    for i in range(HW // 4):
        struct.pack_into('<I', ram, PT + i * 4, i * HW | 3)
    assert struct.unpack_from('<I', ram, PTE)[0] == 0
    rom = bytearray([0xff]) * 0x10000
    boot = bytes.fromhex('fa31c08ed88ed0bc0070b0ffe621e6a1b080e6702e0f011600010f20c06683c8010f22c066ea') + u32(ENTRY) + struct.pack('<H', 0x18)
    rom[:len(boot)] = boot
    struct.pack_into('<HI', rom, 0x100, gdt_limit, GDT)
    rom[0xfff0:0xfff5] = bytes.fromhex('ea000000f0')
    c = Code(ENTRY)
    c.emit('66b820008ed88ec08ed0')
    c.imm('bc', STACK)
    c.imm('b8', PD); c.emit('0f22d8')
    c.imm('b8', 0x80000011); c.emit('0f22c0')
    c.emit('ea')
    far_offset = len(c.raw)
    c.emit(bytes(4) + struct.pack('<H', 8))
    c.label('high')
    struct.pack_into('<I', c.raw, far_offset, c.labels['high'])
    c.emit('66b810008ed88ec08ed066b850008ee08ee8')
    c.emit('0f0115'); c.emit(u32(GDTR))
    c.emit('0f011d'); c.emit(u32(IDTR))
    c.store_imm(POINTER, RECORD)
    for i, payload in enumerate((0xe4, 0xf5)):
        if i:
            c.store_imm(PTE, 0)
            c.imm('b9', USER)
            c.emit('640f0139')  # INVLPG FS:[ECX], not the high DS alias.
        c.imm('bb', payload)
        c.imm('68', flags); c.emit('9d')
        c.call('fault')
        c.load_eax(DATA + (USER & (HW - 1)) - 1); c.store_eax(RESULT + i * 16)
        c.load_eax(POSTFLAGS); c.store_eax(RESULT + i * 16 + 4)
        c.load_eax(PTE); c.store_eax(RESULT + i * 16 + 8)
        c.emit('89e0'); c.store_eax(RESULT + i * 16 + 12)
    c.emit('fc66bae900')
    for address, count in ((RECORD, 2 * 32), (RESULT, 2 * 16)):
        c.imm('be', address); c.imm('b9', count); c.emit('f36e')
    c.imm('b8', 0x10); c.emit('66baf400effaf4')
    c.label('fault')
    c.imm('b9', USER)
    c.label('store')
    c.emit(original(0x189d1b, 3))
    c.emit('9c58'); c.store_eax(POSTFLAGS); c.emit('c3')
    code = bytearray(FATAL - ENTRY + HW)
    program = c.finish()
    assert len(program) < HANDLER - ENTRY
    code[:len(program)] = program
    h = Code(HANDLER)
    h.emit('609c588b3d'); h.emit(u32(POINTER)); h.emit('894718')
    h.emit('c707'); h.emit(u32(14))
    h.emit('8d4424208947040f20d089471c8d7424208d7f08')
    h.imm('b9', 4); h.emit('fcf3a58d7f08893d'); h.emit(u32(POINTER))
    h.store_imm(PTE, DATA | 7)
    h.emit('6183c404'); h.emit(original(0x186d7c, 1))
    handler = h.finish()
    assert len(handler) < FATAL - HANDLER
    code[HANDLER - ENTRY:HANDLER - ENTRY + len(handler)] = handler
    fatal = bytes.fromhex('66bae900b0ee') + bytes.fromhex('ee') + b'\xb8' + u32(0x20) + bytes.fromhex('66baf400effaf4')
    code[FATAL - ENTRY:FATAL - ENTRY + len(fatal)] = fatal
    info = {'flags': flags, 'geometry': {k: globals()[k] for k in ('BASE','HW','PD','GDT','IDT','PT','UPT','ENTRY','HANDLER','FATAL','STACK','RECORD','RESULT','POINTER','POSTFLAGS','DATA','USER','PTE','GDTR','IDTR')},
        'labels': c.labels, 'code_lengths': {'boot': len(boot), 'program': len(program), 'handler': len(handler), 'fatal': len(fatal)},
        'original_opcodes': {'0x189d1b': original(0x189d1b, 3).hex(), '0x186d7c': original(0x186d7c, 1).hex()}}
    return {'bios.bin': bytes(rom), 'tables.bin': bytes(ram), 'code.bin': bytes(code), 'data.bin': bytes([0x55]) * HW}, info


def decode(raw, info):
    assert len(raw) == 2 * 32 + 2 * 16, ('incomplete output', len(raw), raw.hex())
    names = ('gate_marker', 'entry_esp', 'error', 'saved_eip', 'saved_cs', 'saved_eflags', 'handler_pushfd', 'cr2')
    frames = [dict(zip(names, struct.unpack_from('<8I', raw, i * 32))) for i in range(2)]
    results = [dict(zip(('sentinel_window', 'post_store_pushfd', 'user_pte', 'returned_esp'), struct.unpack_from('<4I', raw, 2 * 32 + i * 16))) for i in range(2)]
    for frame in frames:
        assert frame == {'gate_marker': 14, 'entry_esp': STACK - 4 - 4 * 4, 'error': 2,
            'saved_eip': info['labels']['store'], 'saved_cs': 8, 'saved_eflags': info['flags'] | (1 << 16),
            'handler_pushfd': info['flags'], 'cr2': USER}, frame
    for result, payload in zip(results, (0xe4, 0xf5)):
        assert result == {'sentinel_window': int.from_bytes(bytes((0x55, payload, 0x55, 0x55)), 'little'),
            'post_store_pushfd': info['flags'], 'user_pte': DATA | 0x67, 'returned_esp': STACK}, result
    return {'frames': frames, 'results': results}


def main():
    versions = subprocess.run([str(QEMU), '--version'], capture_output=True, text=True, check=True).stdout
    cases = []
    for flags in ((2,) if '--single' in sys.argv else (2, 0x202, 0x402, 0x602)):
        directory = HERE / ('case-' + format(flags, 'x'))
        directory.mkdir(exist_ok=True)
        files, info = images(flags)
        for name, raw in files.items():
            (directory / name).write_bytes(raw)
        output, trace = directory / 'output.bin', directory / 'qemu.log'
        command = [str(QEMU), '-machine', 'pc-i440fx-6.2,accel=tcg', '-cpu', 'qemu32', '-smp', '1', '-m', '16M',
            '-nodefaults', '-no-user-config', '-display', 'none', '-serial', 'none', '-monitor', 'none', '-nic', 'none', '-no-reboot',
            '-bios', str(directory / 'bios.bin'), '-chardev', 'file,id=diag,path=' + str(output),
            '-device', 'isa-debugcon,iobase=0xe9,chardev=diag', '-device', 'isa-debug-exit,iobase=0xf4,iosize=4',
            '-d', 'int,cpu_reset', '-D', str(trace)]
        for name, address in (('tables.bin', 0), ('code.bin', ENTRY), ('data.bin', DATA)):
            command += ['-device', 'loader,file=' + str(directory / name) + ',addr=' + hex(address) + ',force-raw=on']
        result = subprocess.run(command, capture_output=True, timeout=30)
        info.update(command=command, returncode=result.returncode, stdout=result.stdout.decode(errors='replace'), stderr=result.stderr.decode(errors='replace'))
        (directory / 'run.json').write_text(json.dumps(info, indent=2) + '\n')
        assert result.returncode == (0x10 << 1) | 1, info
        raw = output.read_bytes()
        record, strict_failure = None, None
        try:
            record = decode(raw, info)
        except AssertionError as error:
            if '--collect-diagnostics' not in sys.argv:
                raise
            strict_failure = repr(error)
        cases.append(dict(info, observations=record, raw_output_hex=raw.hex(),
            strict_contract_passed=strict_failure is None, strict_failure=strict_failure,
            hashes={p.name: hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(directory.iterdir()) if p.is_file()}))
        print(json.dumps({'flags': flags, 'strict_contract_passed': strict_failure is None, 'strict_failure': strict_failure}), flush=True)
    out = {'qemu_version': versions, 'qemu_sha256': hashlib.sha256(QEMU.read_bytes()).hexdigest(), 'cases': cases,
        'scope': 'synthetic QEMU CPU-model native IDT delivery; relocated identical store/IRETD opcodes only',
        'openstep_handler_executed': False, 'actual_gc_fault_reentry_verified': False, 'physical_cpu_verified': False,
        'all_strict_contracts_passed': all(c['strict_contract_passed'] for c in cases),
        'whole_goal_complete': False}
    (HERE / 'native-probe.json').write_text(json.dumps(out, indent=2) + '\n')


if __name__ == '__main__':
    main()
