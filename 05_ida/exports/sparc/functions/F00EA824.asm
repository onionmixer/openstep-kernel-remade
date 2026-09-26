F00EA824: 9de3bf88                 save    %sp, -0x78, %sp
F00EA828: e0062014                 ld      [%i0+0x14], %l0
F00EA82C: d0062008                 ld      [%i0+8], %o0
F00EA830: 9210001a                 mov     %i2, %o1
F00EA834: 7ffffe77                 call    sub_F00EA210
F00EA838: d4062010                 ld      [%i0+0x10], %o2
F00EA83C: 912a2003                 sll     %o0, 3, %o0
F00EA840: d2040008                 ld      [%l0+%o0], %o1
F00EA844: d227bfe8                 st      %o1, [%fp+var_18]
F00EA848: a0040008                 add     %l0, %o0, %l0
F00EA84C: d0042004                 ld      [%l0+4], %o0
F00EA850: a0924000                 orcc    %o1, %g0, %l0
F00EA854: 12800006                 bne     loc_F00EA86C
F00EA858: d027bfec                 st      %o0, [%fp+var_14]
F00EA85C: 10800011                 ba      locret_F00EA8A0
F00EA860: b0102000                 mov     0, %i0
F00EA864: 1080000f                 ba      locret_F00EA8A0
F00EA868: b0102001                 mov     1, %i0
F00EA86C: 10800008                 ba      loc_F00EA88C
F00EA870: e207bfec                 ld      [%fp+var_14], %l1
F00EA874: 9210001a                 mov     %i2, %o1
F00EA878: 7ffffe9c                 call    sub_F00EA2E8
F00EA87C: d4044000                 ld      [%l1], %o2
F00EA880: 80a22000                 cmp     %o0, 0
F00EA884: 12bffff8                 bne     loc_F00EA864
F00EA888: a2046008                 inc     8, %l1
F00EA88C: a0043fff                 inc     -1, %l0
F00EA890: 80a43fff                 cmp     %l0, -1
F00EA894: 32bffff8                 bne,a   loc_F00EA874
F00EA898: d0062008                 ld      [%i0+8], %o0
F00EA89C: b0102000                 mov     0, %i0
F00EA8A0: 81c7e008                 ret
F00EA8A4: 81e80000                 restore
