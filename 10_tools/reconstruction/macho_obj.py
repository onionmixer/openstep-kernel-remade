#!/usr/bin/env python3
"""Reader for NeXT Mach-O relocatable objects (MH_OBJECT), i386 little-endian first.

Reads the header, the LC_SEGMENT sections, LC_SYMTAB symbols and every
section's relocation entries (plain and scattered).  Written from the Mach-O
structure layout; its output is cross-checked against llvm-objdump
(10_tools/reconstruction/check_macho_obj.py) before it is used as evidence.

  macho_obj.py FILE.o      print a JSON summary
"""
import json, struct, sys

MH_MAGIC = 0xfeedface
LC_SEGMENT, LC_SYMTAB = 1, 2
N_TYPE, N_EXT, N_STAB = 0x0e, 0x01, 0xe0
N_UNDF, N_ABS, N_SECT = 0x0, 0x2, 0xe
R_SCATTERED = 0x80000000
RELOC_TYPES_I386 = {0: 'VANILLA', 1: 'PAIR', 2: 'SECTDIFF', 3: 'PB_LA_PTR', 4: 'LOCAL_SECTDIFF'}


class MachOError(Exception):
    pass


def read(path):
    d = open(path, 'rb').read()
    return parse(d)


def parse(d):
    if len(d) < 28:
        raise MachOError('short file')
    magic = struct.unpack('<I', d[:4])[0]
    if magic == MH_MAGIC:
        e = '<'
    elif struct.unpack('>I', d[:4])[0] == MH_MAGIC:
        e = '>'
    else:
        raise MachOError('not a 32-bit Mach-O')
    magic, cputype, cpusub, filetype, ncmds, sizeofcmds, flags = struct.unpack(e + '7I', d[:28])
    obj = dict(endian='little' if e == '<' else 'big', cputype=cputype, cpusubtype=cpusub,
               filetype=filetype, ncmds=ncmds, flags=flags, sections=[], symbols=[])
    off = 28
    symtab = None
    for _ in range(ncmds):
        cmd, size = struct.unpack(e + '2I', d[off:off + 8])
        if size < 8 or off + size > 28 + sizeofcmds:
            raise MachOError('bad load command size at %d' % off)
        if cmd == LC_SEGMENT:
            nsects = struct.unpack(e + 'I', d[off + 48:off + 52])[0]
            for k in range(nsects):
                s = off + 56 + 68 * k
                sect, seg = d[s:s + 16], d[s + 16:s + 32]
                addr, ssize, soff, align, reloff, nreloc, sflags = struct.unpack(e + '7I', d[s + 32:s + 60])
                obj['sections'].append(dict(
                    index=len(obj['sections']) + 1, sectname=sect.split(b'\0')[0].decode('latin1'),
                    segname=seg.split(b'\0')[0].decode('latin1'), addr=addr, size=ssize, offset=soff,
                    align=align, reloff=reloff, nreloc=nreloc, flags=sflags,
                    relocs=relocs(d, e, reloff, nreloc)))
        elif cmd == LC_SYMTAB:
            symtab = struct.unpack(e + '4I', d[off + 8:off + 24])
        off += size
    if symtab:
        symoff, nsyms, stroff, strsize = symtab
        for i in range(nsyms):
            p = symoff + 12 * i
            strx, ntype, nsect, ndesc, value = struct.unpack(e + 'IBBhI', d[p:p + 12])
            name = d[stroff + strx:d.index(b'\0', stroff + strx)].decode('latin1') if strx else ''
            obj['symbols'].append(dict(index=i, name=name, type=ntype, sect=nsect, desc=ndesc,
                                       value=value, ext=bool(ntype & N_EXT),
                                       kind=('COMMON' if (ntype & N_TYPE) == N_UNDF and ntype & N_EXT and value
                                             else {N_UNDF: 'UNDF', N_ABS: 'ABS', N_SECT: 'SECT'}.get(ntype & N_TYPE, 'OTHER')),
                                       stab=bool(ntype & N_STAB)))
    return obj


def relocs(d, e, off, n):
    out = []
    for i in range(n):
        w0, w1 = struct.unpack(e + '2I', d[off + 8 * i:off + 8 * i + 8])
        if w0 & R_SCATTERED:
            # scattered_relocation_info, little-endian bit order:
            # r_address:24 r_type:4 r_length:2 r_pcrel:1 r_scattered:1 ; r_value
            if e != '<':
                raise MachOError('big-endian scattered relocations not implemented yet')
            out.append(dict(scattered=True, address=w0 & 0xffffff, type=(w0 >> 24) & 0xf,
                            length=(w0 >> 28) & 3, pcrel=bool((w0 >> 30) & 1), value=w1))
        else:
            # relocation_info, little-endian: r_symbolnum:24 r_pcrel:1 r_length:2 r_extern:1 r_type:4
            if e != '<':
                raise MachOError('big-endian relocations not implemented yet')
            out.append(dict(scattered=False, address=w0, symbolnum=w1 & 0xffffff,
                            pcrel=bool((w1 >> 24) & 1), length=(w1 >> 25) & 3,
                            extern=bool((w1 >> 27) & 1), type=(w1 >> 28) & 0xf))
    return out


if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    print(json.dumps(read(sys.argv[1]), indent=1))
