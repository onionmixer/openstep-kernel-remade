F006528C: 9de3bf98                 save    %sp, -0x68, %sp
F0065290: 80a62000                 cmp     %i0, 0
F0065294: 02800019                 be      locret_F00652F8
F0065298: a0102000                 mov     0, %l0
F006529C: 80a63fff                 cmp     %i0, -1
F00652A0: 02800016                 be      locret_F00652F8
F00652A4: 01000000                 nop
F00652A8: d0060000                 ld      [%i0], %o0
F00652AC: 80a22000                 cmp     %o0, 0
F00652B0: 12bffffe                 bne     loc_F00652A8
F00652B4: 01000000                 nop
F00652B8: 4000c6fc                 call    _simple_lock_try
F00652BC: 90100018                 mov     %i0, %o0
F00652C0: 80a22000                 cmp     %o0, 0
F00652C4: 02bffff9                 be      loc_F00652A8
F00652C8: 01000000                 nop
F00652CC: d2062008                 ld      [%i0+8], %o1
F00652D0: 80a26000                 cmp     %o1, 0
F00652D4: 16800008                 bge     loc_F00652F4
F00652D8: 1100003f                 sethi   0xFC00, %o0
F00652DC: 901223ff                 bset    0x3FF, %o0
F00652E0: 900a4008                 and     %o1, %o0, %o0
F00652E4: 90023ffd                 inc     -3, %o0
F00652E8: 80a22001                 cmp     %o0, 1
F00652EC: 28800002                 bleu,a  loc_F00652F4
F00652F0: e0062014                 ld      [%i0+0x14], %l0
F00652F4: c0260000                 clr     [%i0]
F00652F8: 81c7e008                 ret
F00652FC: 91e80010                 restore %g0, %l0, %o0
