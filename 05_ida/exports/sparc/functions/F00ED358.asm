F00ED358: 9de3bf90                 save    %sp, -0x70, %sp
F00ED35C: e2062008                 ld      [%i0+8], %l1
F00ED360: a2047fff                 inc     -1, %l1
F00ED364: 80a47fff                 cmp     %l1, -1
F00ED368: 02800018                 be      locret_F00ED3C8
F00ED36C: e006200c                 ld      [%i0+0xC], %l0
F00ED370: 253c03b7                 sethi   -0xFF12400, %l2
F00ED374: d0040000                 ld      [%l0], %o0
F00ED378: 80a22000                 cmp     %o0, 0
F00ED37C: 0280000f                 be      loc_F00ED3B8
F00ED380: 80a66000                 cmp     %i1, 0
F00ED384: d027bff0                 st      %o0, [%fp+var_10]
F00ED388: d0042004                 ld      [%l0+4], %o0
F00ED38C: 02800005                 be      loc_F00ED3A0
F00ED390: d027bff4                 st      %o0, [%fp+var_C]
F00ED394: d0060000                 ld      [%i0], %o0
F00ED398: 10800003                 ba      loc_F00ED3A4
F00ED39C: d0022008                 ld      [%o0+8], %o0
F00ED3A0: 9014a3ac                 or      %l2, 0x3AC, %o0
F00ED3A4: 9207bff0                 add     %fp, var_10, %o1
F00ED3A8: 7fffffd8                 call    sub_F00ED308
F00ED3AC: d4062010                 ld      [%i0+0x10], %o2
F00ED3B0: c0240000                 clr     [%l0]
F00ED3B4: c0242004                 clr     [%l0+4]
F00ED3B8: a2047fff                 inc     -1, %l1
F00ED3BC: 80a47fff                 cmp     %l1, -1
F00ED3C0: 12bfffed                 bne     loc_F00ED374
F00ED3C4: a0042008                 inc     8, %l0
F00ED3C8: 81c7e008                 ret
F00ED3CC: 81e80000                 restore
