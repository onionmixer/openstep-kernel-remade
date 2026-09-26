F0096B88: 91480000                 rdhpr   %hpstate, %o0
F0096B8C: 820a2f00                 and     %o0, 0xF00, %g1
F0096B90: 80a06a00                 cmp     %g1, 0xA00
F0096B94: 26800004                 bl,a    loc_F0096BA4
F0096B98: 822a2f00                 andn    %o0, 0xF00, %g1
F0096B9C: 81c3e008                 retl
F0096BA0: 01000000                 nop
F0096BA4: 82106a00                 bset    0xA00, %g1
F0096BA8: 81884000                 saved
F0096BAC: 01000000                 nop
F0096BB0: 81c3e008                 retl
F0096BB4: 01000000                 nop
