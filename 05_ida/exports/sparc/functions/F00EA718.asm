F00EA718: 9de3bf90                 save    %sp, -0x70, %sp
F00EA71C: e2062010                 ld      [%i0+0x10], %l1
F00EA720: 1080000a                 ba      loc_F00EA748
F00EA724: e0062014                 ld      [%i0+0x14], %l0
F00EA728: 80a22000                 cmp     %o0, 0
F00EA72C: 22800005                 be,a    loc_F00EA740
F00EA730: c0240000                 clr     [%l0]
F00EA734: 7ffdf6f3                 call    _free
F00EA738: d0042004                 ld      [%l0+4], %o0
F00EA73C: c0240000                 clr     [%l0]
F00EA740: c0242004                 clr     [%l0+4]
F00EA744: a0042008                 inc     8, %l0
F00EA748: a2047fff                 inc     -1, %l1
F00EA74C: 80a47fff                 cmp     %l1, -1
F00EA750: 32bffff6                 bne,a   loc_F00EA728
F00EA754: d0040000                 ld      [%l0], %o0
F00EA758: c0262004                 clr     [%i0+4]
F00EA75C: 81c7e008                 ret
F00EA760: 81e80000                 restore
