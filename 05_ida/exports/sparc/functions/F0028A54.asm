F0028A54: 9de3bf78                 save    %sp, -0x88, %sp
F0028A58: e007a05c                 ld      [%fp+arg_5C], %l0
F0028A5C: 80a62001                 cmp     %i0, 1
F0028A60: 12800009                 bne     loc_F0028A84
F0028A64: e207a060                 ld      [%fp+arg_60], %l1
F0028A68: d0066024                 ld      [%i1+0x24], %o0
F0028A6C: d002200c                 ld      [%o0+0xC], %o0
F0028A70: 808a2001                 btst    1, %o0
F0028A74: 22800005                 be,a    loc_F0028A88
F0028A78: f427bfd8                 st      %i2, [%fp+var_28]
F0028A7C: 10800038                 ba      locret_F0028B5C
F0028A80: b010201e                 mov     0x1E, %i0
F0028A84: f427bfd8                 st      %i2, [%fp+var_28]
F0028A88: f627bfdc                 st      %i3, [%fp+var_24]
F0028A8C: 9007bfd8                 add     %fp, var_28, %o0
F0028A90: d027bfe0                 st      %o0, [%fp+var_20]
F0028A94: 90102001                 mov     1, %o0
F0028A98: d027bfe4                 st      %o0, [%fp+var_1C]
F0028A9C: f83fbfe8                 std     %i4, [%fp+var_18]
F0028AA0: f627bff4                 st      %i3, [%fp+var_C]
F0028AA4: d0066028                 ld      [%i1+0x28], %o0
F0028AA8: 80a22001                 cmp     %o0, 1
F0028AAC: 12800018                 bne     loc_F0028B0C
F0028AB0: 113c04cf                 sethi   -0xFECC400, %o0
F0028AB4: 353c04cf                 sethi   %hi(_active_u), %i2
F0028AB8: d006a1d8                 ld      [%i2+%lo(_active_u)], %o0
F0028ABC: d0020000                 ld      [%o0], %o0
F0028AC0: d2022014                 ld      [%o0+0x14], %o1
F0028AC4: 11000010                 sethi   0x4000, %o0
F0028AC8: 808a4008                 btst    %o0, %o1
F0028ACC: 12800010                 bne     loc_F0028B0C
F0028AD0: 113c04cf                 sethi   -0xFECC400, %o0
F0028AD4: 40010e08                 call    _map_vnode
F0028AD8: 90100019                 mov     %i1, %o0
F0028ADC: 90100019                 mov     %i1, %o0
F0028AE0: d606a1d8                 ld      [%i2+%lo(_active_u)], %o3
F0028AE4: 9207bfe0                 add     %fp, var_20, %o1
F0028AE8: d802e01c                 ld      [%o3+0x1C], %o4
F0028AEC: 94100018                 mov     %i0, %o2
F0028AF0: 40011083                 call    _mfs_io
F0028AF4: 96100010                 mov     %l0, %o3
F0028AF8: b0100008                 mov     %o0, %i0
F0028AFC: 40010e4c                 call    _unmap_vnode
F0028B00: 90100019                 mov     %i1, %o0
F0028B04: 1080000d                 ba      loc_F0028B38
F0028B08: 80a46000                 cmp     %l1, 0
F0028B0C: d20221d8                 ld      [%o0+0x1D8], %o1
F0028B10: d802601c                 ld      [%o1+0x1C], %o4
F0028B14: 90100019                 mov     %i1, %o0
F0028B18: d602201c                 ld      [%o0+0x1C], %o3
F0028B1C: 94100018                 mov     %i0, %o2
F0028B20: da02e008                 ld      [%o3+8], %o5
F0028B24: 9207bfe0                 add     %fp, var_20, %o1
F0028B28: 9fc34000                 call    %o5
F0028B2C: 96100010                 mov     %l0, %o3
F0028B30: b0100008                 mov     %o0, %i0
F0028B34: 80a46000                 cmp     %l1, 0
F0028B38: 02800004                 be      loc_F0028B48
F0028B3C: d007bff4                 ld      [%fp+var_C], %o0
F0028B40: 10800007                 ba      locret_F0028B5C
F0028B44: d0244000                 st      %o0, [%l1]
F0028B48: 80a22000                 cmp     %o0, 0
F0028B4C: 02800004                 be      locret_F0028B5C
F0028B50: 80a62000                 cmp     %i0, 0
F0028B54: 22800002                 be,a    locret_F0028B5C
F0028B58: b0102005                 mov     5, %i0
F0028B5C: 81c7e008                 ret
F0028B60: 81e80000                 restore
