F009F230: 9de3bf90                 save    %sp, -0x70, %sp
F009F234: 153c04f79412a270         set     _pmap_info, %o2
F009F23C: d202a08c                 ld      [%o2+0x8C], %o1
F009F240: 90100018                 mov     %i0, %o0
F009F244: 92026001                 inc     %o1
F009F248: 7fff9c3c                 call    _vm_mem_ppi
F009F24C: d222a08c                 st      %o1, [%o2+0x8C]
F009F250: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F009F254: 932a2002                 sll     %o0, 2, %o1
F009F258: 92024008                 add     %o1, %o0, %o1
F009F25C: d002a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o0
F009F260: 932a6002                 sll     %o1, 2, %o1
F009F264: a0020009                 add     %o0, %o1, %l0
F009F268: d00c2010                 ldub    [%l0+0x10], %o0
F009F26C: 900a0019                 and     %o0, %i1, %o0
F009F270: 80a20019                 cmp     %o0, %i1
F009F274: 12800008                 bne     loc_F009F294
F009F278: b0102001                 mov     1, %i0
F009F27C: 3080008b                 ba,a    locret_F009F4A8
F009F280: c0246018                 clr     [%l1+0x18]
F009F284: 7fffdea8                 call    _splx
F009F288: 90100014                 mov     %l4, %o0
F009F28C: 10800087                 ba      locret_F009F4A8
F009F290: b0102001                 mov     1, %i0
F009F294: 7fffde9a                 call    _splvm
F009F298: a4100010                 mov     %l0, %l2
F009F29C: e204a004                 ld      [%l2+4], %l1
F009F2A0: 80a46000                 cmp     %l1, 0
F009F2A4: 0280007e                 be      loc_F009F49C
F009F2A8: a8100008                 mov     %o0, %l4
F009F2AC: a6102001                 mov     1, %l3
F009F2B0: d004a008                 ld      [%l2+8], %o0
F009F2B4: b0046018                 add     %l1, 0x18, %i0
F009F2B8: 91322008                 srl     %o0, 8, %o0
F009F2BC: 912a200c                 sll     %o0, 12, %o0
F009F2C0: d027bff4                 st      %o0, [%fp+var_C]
F009F2C4: d0060000                 ld      [%i0], %o0
F009F2C8: 80a22000                 cmp     %o0, 0
F009F2CC: 12bffffe                 bne     loc_F009F2C4
F009F2D0: 01000000                 nop
F009F2D4: 7fffdef5                 call    _simple_lock_try
F009F2D8: 90100018                 mov     %i0, %o0
F009F2DC: 80a22000                 cmp     %o0, 0
F009F2E0: 02bffff9                 be      loc_F009F2C4
F009F2E4: 90100011                 mov     %l1, %o0
F009F2E8: d207bff4                 ld      [%fp+var_C], %o1
F009F2EC: 7ffff5b3                 call    _pmap_page_table_entry
F009F2F0: 94102000                 mov     0, %o2
F009F2F4: 96920000                 orcc    %o0, %g0, %o3
F009F2F8: 02800060                 be      loc_F009F478
F009F2FC: 01000000                 nop
F009F300: d00ae00d                 ldub    [%o3+0xD], %o0
F009F304: 80a22003                 cmp     %o0, 3
F009F308: 12800007                 bne     loc_F009F324
F009F30C: 80a22002                 cmp     %o0, 2
F009F310: d007bff4                 ld      [%fp+var_C], %o0
F009F314: d202c000                 ld      [%o3], %o1
F009F318: 9132200a                 srl     %o0, 10, %o0
F009F31C: 1080000a                 ba      loc_F009F344
F009F320: 900a20fc                 and     %o0, 0xFC, %o0
F009F324: 32800006                 bne,a   loc_F009F33C
F009F328: d00fbff4                 ldub    [%fp+var_C], %o0
F009F32C: d017bff4                 lduh    [%fp+var_C], %o0
F009F330: d202c000                 ld      [%o3], %o1
F009F334: 10800004                 ba      loc_F009F344
F009F338: 900a20fc                 and     %o0, 0xFC, %o0
F009F33C: d202c000                 ld      [%o3], %o1
F009F340: 912a2002                 sll     %o0, 2, %o0
F009F344: 94024008                 add     %o1, %o0, %o2
F009F348: d0028000                 ld      [%o2], %o0
F009F34C: 900a2003                 and     %o0, 3, %o0
F009F350: 80a22002                 cmp     %o0, 2
F009F354: 12800049                 bne     loc_F009F478
F009F358: 01000000                 nop
F009F35C: d00ae00d                 ldub    [%o3+0xD], %o0
F009F360: 80a22003                 cmp     %o0, 3
F009F364: 12800037                 bne     loc_F009F440
F009F368: 9802a004                 add     %o2, 4, %o4
F009F36C: 113c04f7                 sethi   %hi(_pmap_info), %o0
F009F370: d0122270                 lduh    [%o0+%lo(_pmap_info)], %o0
F009F374: 912a2002                 sll     %o0, 2, %o0
F009F378: 10800032                 ba      loc_F009F440
F009F37C: 98028008                 add     %o2, %o0, %o4
F009F380: 808a2040                 btst    0x40, %o0 ! '@'
F009F384: 32800026                 bne,a   loc_F009F41C
F009F388: d00c2010                 ldub    [%l0+0x10], %o0
F009F38C: d00ae00d                 ldub    [%o3+0xD], %o0
F009F390: 80a22003                 cmp     %o0, 3
F009F394: 12800009                 bne     loc_F009F3B8
F009F398: 80a22002                 cmp     %o0, 2
F009F39C: d007bff4                 ld      [%fp+var_C], %o0
F009F3A0: 9132200c                 srl     %o0, 12, %o0
F009F3A4: 93322003                 srl     %o0, 3, %o1
F009F3A8: 920a6004                 and     %o1, 4, %o1
F009F3AC: 9202400b                 add     %o1, %o3, %o1
F009F3B0: 1080000a                 ba      loc_F009F3D8
F009F3B4: 900a201e                 and     %o0, 0x1E, %o0
F009F3B8: 1280000f                 bne     loc_F009F3F4
F009F3BC: d00fbff4                 ldub    [%fp+var_C], %o0
F009F3C0: d007bff4                 ld      [%fp+var_C], %o0
F009F3C4: 91322012                 srl     %o0, 18, %o0
F009F3C8: 93322003                 srl     %o0, 3, %o1
F009F3CC: 920a6004                 and     %o1, 4, %o1
F009F3D0: 9202400b                 add     %o1, %o3, %o1
F009F3D4: 900a201f                 and     %o0, 0x1F, %o0
F009F3D8: d2026018                 ld      [%o1+0x18], %o1
F009F3DC: 912cc008                 sll     %l3, %o0, %o0
F009F3E0: 808a4008                 btst    %o0, %o1
F009F3E4: 3280000e                 bne,a   loc_F009F41C
F009F3E8: d00c2010                 ldub    [%l0+0x10], %o0
F009F3EC: 1080000f                 ba      loc_F009F428
F009F3F0: d0028000                 ld      [%o2], %o0
F009F3F4: 93322005                 srl     %o0, 5, %o1
F009F3F8: 932a6002                 sll     %o1, 2, %o1
F009F3FC: 9202400b                 add     %o1, %o3, %o1
F009F400: 900a201f                 and     %o0, 0x1F, %o0
F009F404: d2026030                 ld      [%o1+0x30], %o1
F009F408: 912cc008                 sll     %l3, %o0, %o0
F009F40C: 808a4008                 btst    %o0, %o1
F009F410: 22800006                 be,a    loc_F009F428
F009F414: d0028000                 ld      [%o2], %o0
F009F418: d00c2010                 ldub    [%l0+0x10], %o0
F009F41C: 90122001                 bset    1, %o0
F009F420: d02c2010                 stb     %o0, [%l0+0x10]
F009F424: d0028000                 ld      [%o2], %o0
F009F428: 808a2020                 btst    0x20, %o0 ! ' '
F009F42C: 02800005                 be      loc_F009F440
F009F430: 9402a004                 inc     4, %o2
F009F434: d00c2010                 ldub    [%l0+0x10], %o0
F009F438: 90122002                 bset    2, %o0
F009F43C: d02c2010                 stb     %o0, [%l0+0x10]
F009F440: 80a2800c                 cmp     %o2, %o4
F009F444: 2abfffcf                 bcs,a   loc_F009F380
F009F448: d0028000                 ld      [%o2], %o0
F009F44C: d00ae00d                 ldub    [%o3+0xD], %o0
F009F450: 80a22003                 cmp     %o0, 3
F009F454: 02800004                 be      loc_F009F464
F009F458: 113c0460                 sethi   %hi(aPmapCheckPageA), %o0! "pmap_check_page_attrib: pte not in leve"...
F009F45C: 7ffdd745                 call    _panic
F009F460: 90122030                 bset    %lo(aPmapCheckPageA), %o0! "pmap_check_page_attrib: pte not in leve"...
F009F464: d00c2010                 ldub    [%l0+0x10], %o0
F009F468: 900a0019                 and     %o0, %i1, %o0
F009F46C: 80a20019                 cmp     %o0, %i1
F009F470: 02bfff84                 be      loc_F009F280
F009F474: 01000000                 nop
F009F478: c0246018                 clr     [%l1+0x18]
F009F47C: e4048000                 ld      [%l2], %l2
F009F480: 80a4a000                 cmp     %l2, 0
F009F484: 02800006                 be      loc_F009F49C
F009F488: 01000000                 nop
F009F48C: e204a004                 ld      [%l2+4], %l1
F009F490: 80a46000                 cmp     %l1, 0
F009F494: 32bfff88                 bne,a   loc_F009F2B4
F009F498: d004a008                 ld      [%l2+8], %o0
F009F49C: 7fffde22                 call    _splx
F009F4A0: 90100014                 mov     %l4, %o0
F009F4A4: b0102000                 mov     0, %i0
F009F4A8: 81c7e008                 ret
F009F4AC: 81e80000                 restore
