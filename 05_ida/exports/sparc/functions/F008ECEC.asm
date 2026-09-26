F008ECEC: 9de3bf98                 save    %sp, -0x68, %sp
F008ECF0: 40002015                 call    _curipl
F008ECF4: f0062014                 ld      [%i0+0x14], %i0
F008ECF8: 80a2200a                 cmp     %o0, 0xA
F008ECFC: 14800030                 bg      locret_F008EDBC
F008ED00: 01000000                 nop
F008ED04: 7ffff716                 call    _KernLockAcquire
F008ED08: d0062030                 ld      [%i0+0x30], %o0
F008ED0C: d4062060                 ld      [%i0+0x60], %o2
F008ED10: 11300000                 sethi   -0x40000000, %o0
F008ED14: 808a8008                 btst    %o0, %o2
F008ED18: 02800005                 be      loc_F008ED2C
F008ED1C: 13200000                 sethi   0x80000000, %o1
F008ED20: 7ffff720                 call    _KernLockRelease
F008ED24: d0062030                 ld      [%i0+0x30], %o0
F008ED28: 30800025                 ba,a    locret_F008EDBC
F008ED2C: 92128009                 bset    %o2, %o1
F008ED30: d0062030                 ld      [%i0+0x30], %o0
F008ED34: 7ffff71b                 call    _KernLockRelease
F008ED38: d2262060                 st      %o1, [%i0+0x60]
F008ED3C: 113c0448                 sethi   %hi(dword_F0112054), %o0
F008ED40: d2022054                 ld      [%o0+%lo(dword_F0112054)], %o1
F008ED44: d2262014                 st      %o1, [%i0+0x14]
F008ED48: 90122054                 bset    %lo(dword_F0112054), %o0
F008ED4C: d2022004                 ld      [%o0+4], %o1
F008ED50: d2262018                 st      %o1, [%i0+0x18]
F008ED54: d2022008                 ld      [%o0+8], %o1
F008ED58: d226201c                 st      %o1, [%i0+0x1C]
F008ED5C: d202200c                 ld      [%o0+0xC], %o1
F008ED60: d2262020                 st      %o1, [%i0+0x20]
F008ED64: d2022010                 ld      [%o0+0x10], %o1
F008ED68: 90100018                 mov     %i0, %o0
F008ED6C: d2262024                 st      %o1, [%i0+0x24]
F008ED70: d206202c                 ld      [%i0+0x2C], %o1
F008ED74: f4262028                 st      %i2, [%i0+0x28]
F008ED78: 7fff268d                 call    _ipc_mqueue_send_interrupt
F008ED7C: d226201c                 st      %o1, [%i0+0x1C]
F008ED80: 80a22000                 cmp     %o0, 0
F008ED84: 0280000e                 be      locret_F008EDBC
F008ED88: 01000000                 nop
F008ED8C: 7ffff6f4                 call    _KernLockAcquire
F008ED90: d0062030                 ld      [%i0+0x30], %o0
F008ED94: d2062060                 ld      [%i0+0x60], %o1
F008ED98: 15200000                 sethi   0x80000000, %o2
F008ED9C: d0062030                 ld      [%i0+0x30], %o0
F008EDA0: 942a400a                 andn    %o1, %o2, %o2
F008EDA4: 13100000                 sethi   0x40000000, %o1
F008EDA8: 94128009                 bset    %o1, %o2
F008EDAC: 7ffff6fd                 call    _KernLockRelease
F008EDB0: d4262060                 st      %o2, [%i0+0x60]
F008EDB4: 7fffa04f                 call    _calloutEntryDispatch
F008EDB8: 90062038                 add     %i0, 0x38, %o0 ! '8'
F008EDBC: 81c7e008                 ret
F008EDC0: 81e80000                 restore
