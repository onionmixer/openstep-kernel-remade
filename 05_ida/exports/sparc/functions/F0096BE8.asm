F0096BE8: 91480000                 rdhpr   %hpstate, %o0
F0096BEC: 820a2f00                 and     %o0, 0xF00, %g1
F0096BF0: 80a06800                 cmp     %g1, 0x800
F0096BF4: 26800004                 bl,a    loc_F0096C04
F0096BF8: 822a2f00                 andn    %o0, 0xF00, %g1
F0096BFC: 81c3e008                 retl
F0096C00: 01000000                 nop
F0096C04: 82106800                 bset    0x800, %g1
F0096C08: 81884000                 saved
F0096C0C: 01000000                 nop
F0096C10: 81c3e008                 retl
F0096C14: 01000000                 nop
