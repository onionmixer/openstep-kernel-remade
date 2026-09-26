F00653E0: 9de3bf98                 save    %sp, -0x68, %sp
F00653E4: 80a62000                 cmp     %i0, 0
F00653E8: 0280001c                 be      locret_F0065458
F00653EC: a0102000                 mov     0, %l0
F00653F0: 80a63fff                 cmp     %i0, -1
F00653F4: 02800019                 be      locret_F0065458
F00653F8: 01000000                 nop
F00653FC: d0060000                 ld      [%i0], %o0
F0065400: 80a22000                 cmp     %o0, 0
F0065404: 12bffffe                 bne     loc_F00653FC
F0065408: 01000000                 nop
F006540C: 4000c6a7                 call    _simple_lock_try
F0065410: 90100018                 mov     %i0, %o0
F0065414: 80a22000                 cmp     %o0, 0
F0065418: 02bffff9                 be      loc_F00653FC
F006541C: 01000000                 nop
F0065420: d2062008                 ld      [%i0+8], %o1
F0065424: 80a26000                 cmp     %o1, 0
F0065428: 1680000b                 bge     loc_F0065454
F006542C: 01000000                 nop
F0065430: 1100003f901223ff         set     0xFFFF, %o0
F0065438: 900a4008                 and     %o1, %o0, %o0
F006543C: 80a22006                 cmp     %o0, 6
F0065440: 12800005                 bne     loc_F0065454
F0065444: 01000000                 nop
F0065448: e0062014                 ld      [%i0+0x14], %l0
F006544C: 40002754                 call    _pset_reference
F0065450: 90100010                 mov     %l0, %o0
F0065454: c0260000                 clr     [%i0]
F0065458: 81c7e008                 ret
F006545C: 91e80010                 restore %g0, %l0, %o0
