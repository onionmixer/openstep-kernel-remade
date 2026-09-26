F0096BB8: 91480000                 rdhpr   %hpstate, %o0
F0096BBC: 820a2f00                 and     %o0, 0xF00, %g1
F0096BC0: 80a06900                 cmp     %g1, 0x900
F0096BC4: 26800004                 bl,a    loc_F0096BD4
F0096BC8: 822a2f00                 andn    %o0, 0xF00, %g1
F0096BCC: 81c3e008                 retl
F0096BD0: 01000000                 nop
F0096BD4: 82106900                 bset    0x900, %g1
F0096BD8: 81884000                 saved
F0096BDC: 01000000                 nop
F0096BE0: 81c3e008                 retl
F0096BE4: 01000000                 nop
