F0096B3C: 91480000                 rdhpr   %hpstate, %o0
F0096B40: 820a2f00                 and     %o0, 0xF00, %g1
F0096B44: 80a06d00                 cmp     %g1, 0xD00
F0096B48: 26800004                 bl,a    loc_F0096B58
F0096B4C: 822a2f00                 andn    %o0, 0xF00, %g1
F0096B50: 81c3e008                 retl
F0096B54: 01000000                 nop
F0096B58: 82106d00                 bset    0xD00, %g1
F0096B5C: 81884000                 saved
F0096B60: 01000000                 nop
F0096B64: 81c3e008                 retl
F0096B68: 01000000                 nop
