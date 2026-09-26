F00EA8A8: 9de3bf88                 save    %sp, -0x78, %sp
F00EA8AC: e0062014                 ld      [%i0+0x14], %l0
F00EA8B0: d0062008                 ld      [%i0+8], %o0
F00EA8B4: 9210001a                 mov     %i2, %o1
F00EA8B8: 7ffffe56                 call    sub_F00EA210
F00EA8BC: d4062010                 ld      [%i0+0x10], %o2
F00EA8C0: 912a2003                 sll     %o0, 3, %o0
F00EA8C4: d2040008                 ld      [%l0+%o0], %o1
F00EA8C8: d227bfe8                 st      %o1, [%fp+var_18]
F00EA8CC: a0040008                 add     %l0, %o0, %l0
F00EA8D0: d0042004                 ld      [%l0+4], %o0
F00EA8D4: a0924000                 orcc    %o1, %g0, %l0
F00EA8D8: 12800004                 bne     loc_F00EA8E8
F00EA8DC: d027bfec                 st      %o0, [%fp+var_14]
F00EA8E0: 10800010                 ba      locret_F00EA920
F00EA8E4: b0102000                 mov     0, %i0
F00EA8E8: 10800009                 ba      loc_F00EA90C
F00EA8EC: e207bfec                 ld      [%fp+var_14], %l1
F00EA8F0: 9210001a                 mov     %i2, %o1
F00EA8F4: 7ffffe7d                 call    sub_F00EA2E8
F00EA8F8: d4044000                 ld      [%l1], %o2
F00EA8FC: 80a22000                 cmp     %o0, 0
F00EA900: 32800008                 bne,a   locret_F00EA920
F00EA904: f0046004                 ld      [%l1+4], %i0
F00EA908: a2046008                 inc     8, %l1
F00EA90C: a0043fff                 inc     -1, %l0
F00EA910: 80a43fff                 cmp     %l0, -1
F00EA914: 32bffff7                 bne,a   loc_F00EA8F0
F00EA918: d0062008                 ld      [%i0+8], %o0
F00EA91C: b0102000                 mov     0, %i0
F00EA920: 81c7e008                 ret
F00EA924: 81e80000                 restore
