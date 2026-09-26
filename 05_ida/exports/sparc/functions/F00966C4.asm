F00966C4: 1900700098132100         set     0x1C00100, %o4
F00966CC: 1b0070009a136200         set     0x1C00200, %o5
F00966D4: 94102010                 mov     0x10, %o2
F00966D8: 972a200c                 sll     %o0, 12, %o3
F00966DC: d4bb0040                 stda    %o2, [%o4]2
F00966E0: d4bb4040                 stda    %o2, [%o5]2
F00966E4: 9602e020                 inc     0x20, %o3 ! ' '
F00966E8: 808aefff                 btst    0xFFF, %o3
F00966EC: 12bffffc                 bne     loc_F00966DC
F00966F0: 01000000                 nop
F00966F4: 81c3e008                 retl
F00966F8: 90100000                 clr     %o0
