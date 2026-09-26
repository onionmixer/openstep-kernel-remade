F0020AA4: 9de3bf98                 save    %sp, -0x68, %sp
F0020AA8: d0162014                 lduh    [%i0+0x14], %o0
F0020AAC: 808a2001                 btst    1, %o0
F0020AB0: 02800008                 be      loc_F0020AD0
F0020AB4: 113c042f                 sethi   %hi(aSbflush), %o0! "sbflush"
F0020AB8: 7fffd1ae                 call    _panic
F0020ABC: 901220b0                 bset    %lo(aSbflush), %o0! "sbflush"
F0020AC0: 10800005                 ba      loc_F0020AD4
F0020AC4: d0162004                 lduh    [%i0+4], %o0
F0020AC8: 40000016                 call    _sbdrop
F0020ACC: 90100018                 mov     %i0, %o0
F0020AD0: d0162004                 lduh    [%i0+4], %o0
F0020AD4: 80a22000                 cmp     %o0, 0
F0020AD8: 32bffffc                 bne,a   loc_F0020AC8
F0020ADC: d2160000                 lduh    [%i0], %o1
F0020AE0: d0160000                 lduh    [%i0], %o0
F0020AE4: 80a22000                 cmp     %o0, 0
F0020AE8: 1280000a                 bne     loc_F0020B10
F0020AEC: 113c042f                 sethi   -0xFEF4400, %o0
F0020AF0: d0162004                 lduh    [%i0+4], %o0
F0020AF4: 80a22000                 cmp     %o0, 0
F0020AF8: 12800006                 bne     loc_F0020B10
F0020AFC: 113c042f                 sethi   -0xFEF4400, %o0
F0020B00: d006200c                 ld      [%i0+0xC], %o0
F0020B04: 80a22000                 cmp     %o0, 0
F0020B08: 02800004                 be      locret_F0020B18
F0020B0C: 113c042f                 sethi   -0xFEF4400, %o0! char *
F0020B10: 7fffd198                 call    _panic
F0020B14: 901220b8                 bset    0xB8, %o0
F0020B18: 81c7e008                 ret
F0020B1C: 81e80000                 restore
