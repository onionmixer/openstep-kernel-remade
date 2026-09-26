F00483B8: 9de3bf90                 save    %sp, -0x70, %sp
F00483BC: e0062030                 ld      [%i0+0x30], %l0
F00483C0: d2042038                 ld      [%l0+0x38], %o1
F00483C4: 80a26000                 cmp     %o1, 0
F00483C8: 12800004                 bne     loc_F00483D8
F00483CC: a2102000                 mov     0, %l1
F00483D0: 1080000b                 ba      loc_F00483FC
F00483D4: b0102000                 mov     0, %i0
F00483D8: 90103fff                 mov     -1, %o0
F00483DC: d0266018                 st      %o0, [%i1+0x18]
F00483E0: 90100009                 mov     %o1, %o0
F00483E4: d402201c                 ld      [%o0+0x1C], %o2
F00483E8: d602a018                 ld      [%o2+0x18], %o3
F00483EC: 92100019                 mov     %i1, %o1
F00483F0: 9fc2c000                 call    %o3
F00483F4: 9410001a                 mov     %i2, %o2
F00483F8: b0100008                 mov     %o0, %i0
F00483FC: 80a62000                 cmp     %i0, 0
F0048400: 1280001b                 bne     locret_F004846C
F0048404: 01000000                 nop
F0048408: d0066028                 ld      [%i1+0x28], %o0
F004840C: 80a23fff                 cmp     %o0, -1
F0048410: 22800007                 be,a    loc_F004842C
F0048414: d0066020                 ld      [%i1+0x20], %o0
F0048418: d0242054                 st      %o0, [%l0+0x54]
F004841C: d006602c                 ld      [%i1+0x2C], %o0
F0048420: a2046001                 inc     %l1
F0048424: d0242058                 st      %o0, [%l0+0x58]
F0048428: d0066020                 ld      [%i1+0x20], %o0
F004842C: 80a23fff                 cmp     %o0, -1
F0048430: 02800007                 be      loc_F004844C
F0048434: 80a46000                 cmp     %l1, 0
F0048438: d024204c                 st      %o0, [%l0+0x4C]
F004843C: d0066024                 ld      [%i1+0x24], %o0
F0048440: a2046001                 inc     %l1
F0048444: d0242050                 st      %o0, [%l0+0x50]
F0048448: 80a46000                 cmp     %l1, 0
F004844C: 02800008                 be      locret_F004846C
F0048450: 01000000                 nop
F0048454: 7fff2ace                 call    _getthetime
F0048458: 9007bff0                 add     %fp, var_10, %o0
F004845C: d007bff0                 ld      [%fp+var_10], %o0
F0048460: d024205c                 st      %o0, [%l0+0x5C]
F0048464: d007bff4                 ld      [%fp+var_C], %o0
F0048468: d0242060                 st      %o0, [%l0+0x60]
F004846C: 81c7e008                 ret
F0048470: 81e80000                 restore
