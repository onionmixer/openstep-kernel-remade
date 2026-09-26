F0096F04: 94100000                 clr     %o2
F0096F08: 940aa003                 and     %o2, 3, %o2
F0096F0C: 952aa00c                 sll     %o2, 12, %o2
F0096F10: 173fbfd09612e004         set     -0x100BFFC, %o3
F0096F18: 9602c00a                 add     %o3, %o2, %o3
F0096F1C: 80924000                 tst     %o1
F0096F20: 32800002                 bne,a   locret_F0096F28
F0096F24: 9602e004                 inc     4, %o3
F0096F28: 81c3e008                 retl
F0096F2C: d022c000                 st      %o0, [%o3]
