"""Fixed diagnostic inputs and preserved original image; no reconstructed C."""
import hashlib
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260912-38'
BINARY = ROOT / '03_original/x86/binaries/mach_kernel'
SHA = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
RAW = BINARY.read_bytes()
assert hashlib.sha256(RAW).hexdigest() == SHA
SEGMENTS = []
position = 28
for _ in range(struct.unpack_from('<I', RAW, 16)[0]):
    command, size = struct.unpack_from('<II', RAW, position)
    if command == 1:
        name, va, vs, offset, fs = struct.unpack_from('<16sIIII', RAW, position + 8)
        if name.rstrip(b'\0') in (b'__TEXT', b'__DATA', b'__OBJC'):
            assert 0x100000 <= va and va + vs <= 0x300000
            SEGMENTS.append((va, vs, offset, fs))
    position += size

ENTRY, DECISION, STOP = 0x191144, 0x1912f6, 0x500f80
STACK, PMAP, DIRECTORY, EXT = 0x500f00, 0x610000, 0x600000, 0x620000
SECTION = 0x800000  # Aligned synthetic 8 MiB section; paired PDEs are data, not paging.
PDE = DIRECTORY + (SECTION >> 22) * 4
TICK, LAST, ACTIVE, FREE_PT, FREE_PD = 0x1f653c, 0x1e773c, 0x1f7ac8, 0x1f7ad8, 0x1f7aa8
CALLEE = {'ebx': 0x12341111, 'esi': 0x23452222, 'edi': 0x34563333, 'ebp': 0x45674444}


def original(address, size):
    for va, vs, offset, fs in SEGMENTS:
        if va <= address and address + size <= va + fs:
            return RAW[offset + address - va:offset + address - va + size]
    raise AssertionError(('not file backed', hex(address), size))


def preserve():
    checkpoint = json.loads((PRIOR / 'checkpoint.json').read_text())
    for row in checkpoint['files']:
        p = PRIOR / row['path']
        assert p.stat().st_size == row['size'] and hashlib.sha256(p.read_bytes()).hexdigest() == row['sha256'], p
    return hashlib.sha256((PRIOR / 'checkpoint.json').read_bytes()).hexdigest()


def matrix(smoke=False):
    rows = []
    def add(last, tick, age=0, wired=0, pde=0x700003, active=True, kind='boundary', second_pde=0x710003):
        rows.append(dict(last=last, tick=tick, age=age, wired=wired, pde=pde,
                         second_pde=second_pde, active=active, kind=kind))
    if not smoke:
        for delta in (1,2,7,8,15,16,23,24,31,32,39,40,255,256,257,511,512,513):
            for age in range(256):
                add(0x1000, 0x1000 + delta, age, kind='all_age_bytes')
    for last, tick in ((0,0),(0,3),(0,0xffffffff),(1,1),(1,2),(1,3),
        (0xfffffffe,0),(0xffffffff,0),(0xffffffff,1),(0x7fffffff,0x80000000),
        (1,0),(9,0),(41,0),(0x100001,1),(1,0x80000001),(1,0x80000000)):
        for age in (0,8,255):
            add(last,tick,age)
        add(last,tick,active=False,kind='empty_active')
    for delta in (0,1,2,8,32,256,257):
        for wired in (0,1,0xffff):
            for pde in (0x700000,0x700003,0x700020,0x700023):
                for age in (0,8,255):
                    add(0x1000,0x1000+delta,age,wired,pde,kind='flags_and_widths')
    for delta in (1,40):
        for age in (0,8):
            for pde in (0x700003,0x700023):
                for second in (0x710003,0x710023):
                    add(0x1000,0x1000+delta,age,pde=pde,second_pde=second,kind='PDE_pair_sample')
    return rows
