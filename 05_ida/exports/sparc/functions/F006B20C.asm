F006B20C: 9de3bf48                 save    %sp, -0xB8, %sp
F006B210: d0062008                 ld      [%i0+8], %o0
F006B214: 94060008                 add     %i0, %o0, %o2
F006B218: d0062004                 ld      [%i0+4], %o0
F006B21C: 9210000a                 mov     %o2, %o1
F006B220: b0060008                 add     %i0, %o0, %i0
F006B224: 80a24018                 cmp     %o1, %i0
F006B228: 3a800067                 bcc,a   locret_F006B3C4
F006B22C: b0102002                 mov     2, %i0
F006B230: d04a4000                 ldsb    [%o1], %o0
F006B234: 80a22000                 cmp     %o0, 0
F006B238: 12bffffb                 bne     loc_F006B224
F006B23C: 92026001                 inc     %o1
F006B240: 9010000a                 mov     %o2, %o0
F006B244: a207bfd8                 add     %fp, var_28, %l1
F006B248: 92100011                 mov     %l1, %o1
F006B24C: 9407bfbc                 add     %fp, var_44, %o2
F006B250: 9607bfb8                 add     %fp, var_48, %o3
F006B254: 4000005e                 call    sub_F006B3CC
F006B258: 9807bfb4                 add     %fp, var_4C, %o4
F006B25C: b0920000                 orcc    %o0, %g0, %i0
F006B260: 12800059                 bne     locret_F006B3C4
F006B264: 01000000                 nop
F006B268: 4000c556                 call    _pmap_create
F006B26C: d007bfb8                 ld      [%fp+var_48], %o0
F006B270: d2066014                 ld      [%i1+0x14], %o1
F006B274: d4066018                 ld      [%i1+0x18], %o2! __len
F006B278: 4000638e                 call    _vm_map_create
F006B27C: 96102001                 mov     1, %o3
F006B280: a4100008                 mov     %o0, %l2
F006B284: a007bfc0                 add     %fp, __b, %l0
F006B288: 90100010                 mov     %l0, %o0! __b
F006B28C: 92102000                 mov     0, %o1! __c
F006B290: 7ffe6c3b                 call    _memset
F006B294: 94102014                 mov     0x14, %o2
F006B298: c027bfc0                 clr     [%fp+__b]
F006B29C: d007bfb4                 ld      [%fp+var_4C], %o0
F006B2A0: 92100012                 mov     %l2, %o1
F006B2A4: d607bfbc                 ld      [%fp+var_44], %o3
F006B2A8: 94100011                 mov     %l1, %o2
F006B2AC: d807bfb8                 ld      [%fp+var_48], %o4
F006B2B0: 9a10001a                 mov     %i2, %o5
F006B2B4: c023a05c                 clr     [%sp+0xB8+var_5C]
F006B2B8: 7ffffd61                 call    sub_F006A83C
F006B2BC: e023a060                 st      %l0, [%sp+0xB8+var_58]
F006B2C0: b0920000                 orcc    %o0, %g0, %i0
F006B2C4: 1280003c                 bne     loc_F006B3B4
F006B2C8: 01000000                 nop
F006B2CC: d004a01c                 ld      [%l2+0x1C], %o0
F006B2D0: 80a22000                 cmp     %o0, 0
F006B2D4: 0480002f                 ble     loc_F006B390
F006B2D8: 90100019                 mov     %i1, %o0
F006B2DC: 92102000                 mov     0, %o1
F006B2E0: d604a010                 ld      [%l2+0x10], %o3
F006B2E4: 94102000                 mov     0, %o2
F006B2E8: d804a00c                 ld      [%l2+0xC], %o4
F006B2EC: a207bfb0                 add     %fp, var_50, %l1
F006B2F0: f402e008                 ld      [%o3+8], %i2
F006B2F4: 9a102000                 mov     0, %o5
F006B2F8: d803200c                 ld      [%o4+0xC], %o4
F006B2FC: 96100011                 mov     %l1, %o3
F006B300: f427bfb0                 st      %i2, [%fp+var_50]
F006B304: a023001a                 sub     %o4, %i2, %l0
F006B308: 400064b2                 call    _vm_map_find
F006B30C: 98100010                 mov     %l0, %o4
F006B310: 80a22000                 cmp     %o0, 0
F006B314: 0280000b                 be      loc_F006B340
F006B318: 90100019                 mov     %i1, %o0
F006B31C: 92102000                 mov     0, %o1
F006B320: 94102000                 mov     0, %o2
F006B324: 96100011                 mov     %l1, %o3
F006B328: 98100010                 mov     %l0, %o4
F006B32C: 400064a9                 call    _vm_map_find
F006B330: 9a102001                 mov     1, %o5
F006B334: 80a22000                 cmp     %o0, 0
F006B338: 3280000e                 bne,a   loc_F006B370
F006B33C: b0102005                 mov     5, %i0
F006B340: 90100019                 mov     %i1, %o0
F006B344: 92100012                 mov     %l2, %o1
F006B348: 96100010                 mov     %l0, %o3
F006B34C: 9810001a                 mov     %i2, %o4
F006B350: d407bfb0                 ld      [%fp+var_50], %o2
F006B354: 9a102000                 mov     0, %o5
F006B358: 400068b6                 call    _vm_map_copy
F006B35C: c023a05c                 clr     [%sp+0xB8+var_5C]
F006B360: 80a22000                 cmp     %o0, 0
F006B364: 02800004                 be      loc_F006B374
F006B368: d207bfb0                 ld      [%fp+var_50], %o1
F006B36C: b0102005                 mov     5, %i0
F006B370: d207bfb0                 ld      [%fp+var_50], %o1
F006B374: 80a2401a                 cmp     %o1, %i2
F006B378: 02800007                 be      loc_F006B394
F006B37C: d007bfc4                 ld      [%fp+var_3C], %o0
F006B380: 9222401a                 sub     %o1, %i2, %o1
F006B384: 90020009                 add     %o0, %o1, %o0
F006B388: 10800003                 ba      loc_F006B394
F006B38C: d027bfc4                 st      %o0, [%fp+var_3C]
F006B390: b0102004                 mov     4, %i0
F006B394: 80a62000                 cmp     %i0, 0
F006B398: 12800007                 bne     loc_F006B3B4
F006B39C: 13100000                 sethi   0x40000000, %o1
F006B3A0: d006e010                 ld      [%i3+0x10], %o0
F006B3A4: 90120009                 bset    %o1, %o0
F006B3A8: d026e010                 st      %o0, [%i3+0x10]
F006B3AC: d007bfc4                 ld      [%fp+var_3C], %o0
F006B3B0: d026e004                 st      %o0, [%i3+4]
F006B3B4: 40006396                 call    _vm_map_deallocate
F006B3B8: 90100012                 mov     %l2, %o0
F006B3BC: 7ffef5ea                 call    _vn_rele
F006B3C0: d007bfb4                 ld      [%fp+var_4C], %o0
F006B3C4: 81c7e008                 ret
F006B3C8: 81e80000                 restore
