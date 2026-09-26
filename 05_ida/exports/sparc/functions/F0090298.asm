F0090298: 9de3bf98                 save    %sp, -0x68, %sp
F009029C: 80a62000                 cmp     %i0, 0
F00902A0: 12800004                 bne     loc_F00902B0
F00902A4: a0102000                 mov     0, %l0
F00902A8: 10800013                 ba      locret_F00902F4
F00902AC: b0102000                 mov     0, %i0
F00902B0: d0060000                 ld      [%i0], %o0
F00902B4: 80a22000                 cmp     %o0, 0
F00902B8: 12bffffe                 bne     loc_F00902B0
F00902BC: 01000000                 nop
F00902C0: 40001afa                 call    _simple_lock_try
F00902C4: 90100018                 mov     %i0, %o0
F00902C8: 80a22000                 cmp     %o0, 0
F00902CC: 02bffff9                 be      loc_F00902B0
F00902D0: 1100003f                 sethi   0xFC00, %o0
F00902D4: d2062008                 ld      [%i0+8], %o1
F00902D8: 901223ff                 bset    0x3FF, %o0
F00902DC: 920a4008                 and     %o1, %o0, %o1
F00902E0: 80a2600c                 cmp     %o1, 0xC
F00902E4: 22800002                 be,a    loc_F00902EC
F00902E8: e0062014                 ld      [%i0+0x14], %l0
F00902EC: c0260000                 clr     [%i0]
F00902F0: b0100010                 mov     %l0, %i0
F00902F4: 81c7e008                 ret
F00902F8: 81e80000                 restore
