F00EA69C: 9de3bf90                 save    %sp, -0x70, %sp
F00EA6A0: e6062010                 ld      [%i0+0x10], %l3
F00EA6A4: 10800016                 ba      loc_F00EA6FC
F00EA6A8: e4062014                 ld      [%i0+0x14], %l2
F00EA6AC: 80a22000                 cmp     %o0, 0
F00EA6B0: 22800013                 be,a    loc_F00EA6FC
F00EA6B4: a404a008                 inc     8, %l2
F00EA6B8: a0023fff                 add     %o0, -1, %l0
F00EA6BC: 80a43fff                 cmp     %l0, -1
F00EA6C0: 0280000a                 be      loc_F00EA6E8
F00EA6C4: e204a004                 ld      [%l2+4], %l1
F00EA6C8: 9fc68000                 call    %i2
F00EA6CC: d0044000                 ld      [%l1], %o0
F00EA6D0: 9fc6c000                 call    %i3
F00EA6D4: d0046004                 ld      [%l1+4], %o0! void *
F00EA6D8: a0043fff                 inc     -1, %l0
F00EA6DC: 80a43fff                 cmp     %l0, -1
F00EA6E0: 12bffffa                 bne     loc_F00EA6C8
F00EA6E4: a2046008                 inc     8, %l1
F00EA6E8: 7ffdf706                 call    _free
F00EA6EC: d004a004                 ld      [%l2+4], %o0
F00EA6F0: c0248000                 clr     [%l2]
F00EA6F4: c024a004                 clr     [%l2+4]
F00EA6F8: a404a008                 inc     8, %l2
F00EA6FC: a604ffff                 inc     -1, %l3
F00EA700: 80a4ffff                 cmp     %l3, -1
F00EA704: 32bfffea                 bne,a   loc_F00EA6AC
F00EA708: d0048000                 ld      [%l2], %o0
F00EA70C: c0262004                 clr     [%i0+4]
F00EA710: 81c7e008                 ret
F00EA714: 81e80000                 restore
