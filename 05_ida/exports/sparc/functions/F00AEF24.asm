F00AEF24: 9de3bf98                 save    %sp, -0x68, %sp
F00AEF28: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AEF2C: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AEF30: 80a22000                 cmp     %o0, 0
F00AEF34: 02800004                 be      loc_F00AEF44
F00AEF38: 80a22002                 cmp     %o0, 2
F00AEF3C: 12800009                 bne     loc_F00AEF60
F00AEF40: 113c000c                 sethi   -0xFFFD000, %o0
F00AEF44: 113c000c                 sethi   %hi(_romp), %o0
F00AEF48: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AEF4C: d002204c                 ld      [%o0+0x4C], %o0
F00AEF50: d00a0000                 ldub    [%o0], %o0
F00AEF54: 80a00008                 cmp     %g0, %o0
F00AEF58: 1080000a                 ba      locret_F00AEF80
F00AEF5C: b0603fff                 subc    %g0, -1, %i0
F00AEF60: d0022030                 ld      [%o0+0x30], %o0
F00AEF64: d0022094                 ld      [%o0+0x94], %o0
F00AEF68: 400001f5                 call    _prom_getphandle
F00AEF6C: d0020000                 ld      [%o0], %o0
F00AEF70: 133c0470                 sethi   %hi(aDisplay_0), %o1! "display"
F00AEF74: 7fffffbc                 call    _prom_devicetype
F00AEF78: 92126178                 bset    %lo(aDisplay_0), %o1! "display"
F00AEF7C: b0100008                 mov     %o0, %i0
F00AEF80: 81c7e008                 ret
F00AEF84: 81e80000                 restore
