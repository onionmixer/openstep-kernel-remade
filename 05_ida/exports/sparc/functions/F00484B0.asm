F00484B0: 9de3bf98                 save    %sp, -0x68, %sp
F00484B4: d0062030                 ld      [%i0+0x30], %o0
F00484B8: 92100019                 mov     %i1, %o1
F00484BC: d0022038                 ld      [%o0+0x38], %o0
F00484C0: 80a22000                 cmp     %o0, 0
F00484C4: 12800004                 bne     loc_F00484D4
F00484C8: 9410001a                 mov     %i2, %o2
F00484CC: 10800007                 ba      locret_F00484E8
F00484D0: b0102002                 mov     2, %i0
F00484D4: d602601c                 ld      [%o1+0x1C], %o3
F00484D8: d802e02c                 ld      [%o3+0x2C], %o4
F00484DC: 9fc30000                 call    %o4
F00484E0: 9610001b                 mov     %i3, %o3
F00484E4: b0100008                 mov     %o0, %i0
F00484E8: 81c7e008                 ret
F00484EC: 81e80000                 restore
