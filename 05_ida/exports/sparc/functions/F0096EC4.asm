F0096EC4: 133fbfff921263d8         set     -0x1000028, %o1
F0096ECC: 94102020                 mov     0x20, %o2 ! ' '
F0096ED0: 94a2a001                 deccc   %o2
F0096ED4: d60a400a                 ldub    [%o1+%o2], %o3
F0096ED8: 12bffffe                 bne     loc_F0096ED0
F0096EDC: d62a000a                 stb     %o3, [%o0+%o2]
F0096EE0: 81c3e008                 retl
F0096EE4: 01000000                 nop
