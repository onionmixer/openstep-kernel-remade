F0096C48: 91480000                 rdhpr   %hpstate, %o0
F0096C4C: 820a2f00                 and     %o0, 0xF00, %g1
F0096C50: 80a06400                 cmp     %g1, 0x400
F0096C54: 26800004                 bl,a    loc_F0096C64
F0096C58: 822a2f00                 andn    %o0, 0xF00, %g1
F0096C5C: 81c3e008                 retl
F0096C60: 01000000                 nop
F0096C64: 82106400                 bset    0x400, %g1
F0096C68: 81884000                 saved
F0096C6C: 01000000                 nop
F0096C70: 81c3e008                 retl
F0096C74: 01000000                 nop
