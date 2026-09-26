F0095A48: 940a3000                 and     %o0, -0x1000, %o2
F0095A4C: 9612a400                 or      %o2, 0x400, %o3
F0095A50: d082c060                 lda     [%o3]3, %o0
F0095A54: 80a22000                 cmp     %o0, 0
F0095A58: 02800017                 be      locret_F0095AB4
F0095A5C: 9612a200                 or      %o2, 0x200, %o3
F0095A60: d082c060                 lda     [%o3]3, %o0
F0095A64: 960a2003                 and     %o0, 3, %o3
F0095A68: 80a2e002                 cmp     %o3, 2
F0095A6C: 12800006                 bne     loc_F0095A84
F0095A70: 9732a00c                 srl     %o2, 12, %o3
F0095A74: 960aefff                 and     %o3, 0xFFF, %o3
F0095A78: 972ae008                 sll     %o3, 8, %o3
F0095A7C: 1080000e                 ba      locret_F0095AB4
F0095A80: 9002000b                 add     %o0, %o3, %o0
F0095A84: 9612a100                 or      %o2, 0x100, %o3
F0095A88: d082c060                 lda     [%o3]3, %o0
F0095A8C: 960a2003                 and     %o0, 3, %o3
F0095A90: 80a2e002                 cmp     %o3, 2
F0095A94: 12800006                 bne     loc_F0095AAC
F0095A98: 9732a00c                 srl     %o2, 12, %o3
F0095A9C: 960ae03f                 and     %o3, 0x3F, %o3
F0095AA0: 972ae008                 sll     %o3, 8, %o3
F0095AA4: 10800004                 ba      locret_F0095AB4
F0095AA8: 9002000b                 add     %o0, %o3, %o0
F0095AAC: 9612a000                 or      %o2, 0, %o3
F0095AB0: d082c060                 lda     [%o3]3, %o0
F0095AB4: 81c3e008                 retl
F0095AB8: 01000000                 nop
