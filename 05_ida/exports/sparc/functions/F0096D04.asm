F0096D04: 93480000                 rdhpr   %hpstate, %o1
F0096D08: 960a6f00                 and     %o1, 0xF00, %o3
F0096D0C: 900a2f00                 and     %o0, 0xF00, %o0
F0096D10: 80a2c008                 cmp     %o3, %o0
F0096D14: 06800007                 bl      loc_F0096D30
F0096D18: 942a6f00                 andn    %o1, 0xF00, %o2
F0096D1C: 81c3e008                 retl
F0096D20: 9010000b                 mov     %o3, %o0
