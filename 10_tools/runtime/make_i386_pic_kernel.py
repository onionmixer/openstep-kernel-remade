#!/usr/bin/env python3
"""Make the PIC-fixed copy of the i386 analysis-baseline kernel for QEMU.

usage: make_i386_pic_kernel.py [--in INPUT] OUT

Input: 03_original/x86/binaries/mach_kernel (mk-183.34.4), never modified, or
with --in (plan 405) another file that must have the same SHA-256 (e.g. the
kernel linked from 07_kernel, run s6p402-ln1/s6p404-ln1).  OUT may not be the
input or the baseline file (also through symbolic or hard links).
The baseline's _intr_handler (0x18c85c) returns from a spurious IRQ15 without an
EOI, so the master PIC's IRQ2 in-service bit stays set and QEMU's IDE
interrupts lock up (seen: 02_plan/EMULATION_PLATFORM_PLAN.md, "첫 부팅 결과").
Same 12-byte change as the OPENSTEP_BOOTCD fix of the 1997 kernel:
  0x18c88e  7d 0f  -> 7d 13             jge to the jmp (spurious IRQ7: no EOI)
  0x18c89f  inc [0x1f7a18]; jmp 0x18c9d0; nop nop
         -> mov al,0x62; out 0x20,al; jmp 0x18c9d0; nop x4
                                        (spurious IRQ15: specific EOI IRQ2 to master)
File offset = VA - __TEXT vmaddr + __TEXT fileoff, read from the header.
Writes OUT only if the original bytes, the change count and the result hash match.
"""
import hashlib, os, struct, sys

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
SRC = os.path.join(REPO, '03_original/x86/binaries/mach_kernel')
SRC_SHA256 = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
OUT_SHA256 = '304cb696924f4e389c8365371d386bfa8ea0fa56ea8aac4bb4fc546dc735250f'
PATCHES = [
    (0x18c88e, bytes.fromhex('7d0f'), bytes.fromhex('7d13')),
    (0x18c89f, bytes.fromhex('ff05187a1f00' 'e926010000' '9090'),
               bytes.fromhex('b062' 'e620' 'e928010000' '90909090')),
]


def text_segment(d):
    need = lambda c, m: c or sys.exit('STOP: ' + m)
    need(d[:4] == b'\xce\xfa\xed\xfe', 'not a little-endian Mach-O')
    off, n = 28, struct.unpack('<I', d[16:20])[0]
    for _ in range(n):
        cmd, size = struct.unpack('<2I', d[off:off + 8])
        if cmd == 1 and d[off + 8:off + 24].split(b'\0')[0] == b'__TEXT':
            vmaddr, vmsize, fileoff, filesize = struct.unpack('<4I', d[off + 24:off + 40])
            return vmaddr, vmsize, fileoff
        off += size
    sys.exit('STOP: no __TEXT')


def main():
    args = sys.argv[1:]
    src = SRC
    if len(args) == 3 and args[0] == '--in':
        src, args = args[1], args[2:]
    if len(args) != 1:
        sys.exit(__doc__)
    out_path = args[0]
    for p in {src, SRC}:   # plan 405: never write over the input or the baseline
        if os.path.realpath(out_path) == os.path.realpath(p) or \
                (os.path.exists(out_path) and os.path.samefile(out_path, p)):
            sys.exit('STOP: OUT is the input or the baseline file')
    d = open(src, 'rb').read()
    if hashlib.sha256(d).hexdigest() != SRC_SHA256:
        sys.exit('STOP: baseline hash differs')
    vmaddr, vmsize, fileoff = text_segment(d)
    out = bytearray(d)
    for va, old, new in PATCHES:
        if not (vmaddr <= va and va + len(old) <= vmaddr + vmsize) or len(old) != len(new):
            sys.exit('STOP: patch 0x%x outside __TEXT or length mismatch' % va)
        k = va - vmaddr + fileoff
        if bytes(out[k:k + len(old)]) != old:
            sys.exit('STOP: original bytes at 0x%x differ' % va)
        out[k:k + len(new)] = new
    changed = sum(1 for x, y in zip(d, out) if x != y)
    h = hashlib.sha256(out).hexdigest()
    if changed != 12 or h != OUT_SHA256:
        sys.exit('STOP: result differs (changed %d, sha256 %s)' % (changed, h))
    with open(out_path, 'wb') as o:
        o.write(out)
    print('%s  %d bytes, 12 bytes changed, sha256 %s (input %s)' % (out_path, len(out), h, src))


if __name__ == '__main__':
    main()
