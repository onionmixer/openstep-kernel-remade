F0096C94: 91480000                 rdhpr   %hpstate, %o0
F0096C98: 820a2f00                 and     %o0, 0xF00, %g1
F0096C9C: 80a06100                 cmp     %g1, 0x100
F0096CA0: 26800004                 bl,a    loc_F0096CB0
F0096CA4: 822a2f00                 andn    %o0, 0xF00, %g1
F0096CA8: 81c3e008                 retl
F0096CAC: 01000000                 nop
F0096CB0: 82106100                 bset    0x100, %g1
F0096CB4: 81884000                 saved
F0096CB8: 01000000                 nop
F0096CBC: 81c3e008                 retl
F0096CC0: 01000000                 nop
