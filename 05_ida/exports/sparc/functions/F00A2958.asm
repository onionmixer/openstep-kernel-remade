F00A2958: 9de3bf88                 save    %sp, -0x78, %sp
F00A295C: ae100018                 mov     %i0, %l7
F00A2960: ba10001a                 mov     %i2, %i5
F00A2964: 153c04f79412a270         set     _pmap_info, %o2
F00A296C: d002a0f4                 ld      [%o2+0xF4], %o0
F00A2970: 133c04f0                 sethi   %hi(_kernel_pmap), %o1
F00A2974: d2026100                 ld      [%o1+%lo(_kernel_pmap)], %o1
F00A2978: 90022001                 inc     %o0
F00A297C: 80a5c009                 cmp     %l7, %o1
F00A2980: 02800007                 be      loc_F00A299C
F00A2984: d022a0f4                 st      %o0, [%o2+0xF4]
F00A2988: 113bffff901223ff         set     -0x10000001, %o0
F00A2990: 80a64008                 cmp     %i1, %o0
F00A2994: 08800009                 bleu    loc_F00A29B8
F00A2998: 133c04f7                 sethi   -0xFEC2400, %o1
F00A299C: 90100017                 mov     %l7, %o0
F00A29A0: 92100019                 mov     %i1, %o1
F00A29A4: 7fffff46                 call    _pmap_alloc_kseg_entry
F00A29A8: 9410001d                 mov     %i5, %o2
F00A29AC: 108000f7                 ba      locret_F00A2D88
F00A29B0: b0100008                 mov     %o0, %i0
F00A29B4: 133c04f7                 sethi   -0xFEC2400, %o1
F00A29B8: d00263e8                 ld      [%o1+0x3E8], %o0
F00A29BC: 80a22000                 cmp     %o0, 0
F00A29C0: 02800038                 be      loc_F00A2AA0
F00A29C4: 901263e8                 or      %o1, 0x3E8, %o0
F00A29C8: 7ffffa90                 call    _del_first_pool
F00A29CC: 90023ff8                 inc     -8, %o0
F00A29D0: a4920000                 orcc    %o0, %g0, %l2
F00A29D4: 02800007                 be      loc_F00A29F0
F00A29D8: 113c0464                 sethi   -0xFEE7000, %o0
F00A29DC: d014a01e                 lduh    [%l2+0x1E], %o0
F00A29E0: 80a22000                 cmp     %o0, 0
F00A29E4: 32800006                 bne,a   loc_F00A29FC
F00A29E8: f004a018                 ld      [%l2+0x18], %i0
F00A29EC: 113c0464                 sethi   -0xFEE7000, %o0! char *
F00A29F0: 7ffdc9e0                 call    _panic
F00A29F4: 901220f8                 bset    0xF8, %o0
F00A29F8: f004a018                 ld      [%l2+0x18], %i0
F00A29FC: d014a01e                 lduh    [%l2+0x1E], %o0
F00A2A00: e614a01c                 lduh    [%l2+0x1C], %l3
F00A2A04: 90023fff                 inc     -1, %o0
F00A2A08: a604ffff                 inc     -1, %l3
F00A2A0C: 80a4ffff                 cmp     %l3, -1
F00A2A10: 028000de                 be      locret_F00A2D88
F00A2A14: d034a01e                 sth     %o0, [%l2+0x1E]
F00A2A18: 153c04f7                 sethi   -0xFEC2400, %o2
F00A2A1C: 133c04f7                 sethi   -0xFEC2400, %o1
F00A2A20: 113c04f7a2122270         set     _pmap_info, %l1
F00A2A28: a006200d                 add     %i0, 0xD, %l0
F00A2A2C: d0043ffb                 ld      [%l0-5], %o0
F00A2A30: 80a22000                 cmp     %o0, 0
F00A2A34: 32800016                 bne,a   loc_F00A2A8C
F00A2A38: a0042028                 inc     0x28, %l0 ! '('
F00A2A3C: ee243ffb                 st      %l7, [%l0-5]
F00A2A40: c02c2002                 clrb    [%l0+2]
F00A2A44: c0242003                 clr     [%l0+3]
F00A2A48: c0242007                 clr     [%l0+7]
F00A2A4C: c024200b                 clr     [%l0+0xB]
F00A2A50: c024200f                 clr     [%l0+0xF]
F00A2A54: c0242013                 clr     [%l0+0x13]
F00A2A58: f2242017                 st      %i1, [%l0+0x17]
F00A2A5C: d014a01e                 lduh    [%l2+0x1E], %o0
F00A2A60: 80a22000                 cmp     %o0, 0
F00A2A64: 12800003                 bne     loc_F00A2A70
F00A2A68: 901263e0                 or      %o1, 0x3E0, %o0
F00A2A6C: 9012a3c0                 or      %o2, 0x3C0, %o0
F00A2A70: 7ffffa53                 call    _add_pool
F00A2A74: 92100012                 mov     %l2, %o1
F00A2A78: fa2c0000                 stb     %i5, [%l0]
F00A2A7C: d0046018                 ld      [%l1+0x18], %o0
F00A2A80: 90022001                 inc     %o0
F00A2A84: 108000c1                 ba      locret_F00A2D88
F00A2A88: d0246018                 st      %o0, [%l1+0x18]
F00A2A8C: a604ffff                 inc     -1, %l3
F00A2A90: 80a4ffff                 cmp     %l3, -1
F00A2A94: 12bfffe6                 bne     loc_F00A2A2C
F00A2A98: b0062028                 inc     0x28, %i0 ! '('
F00A2A9C: 308000bb                 ba,a    locret_F00A2D88
F00A2AA0: 133c04f7                 sethi   %hi(dword_F013DFD8), %o1
F00A2AA4: d00263d8                 ld      [%o1+%lo(dword_F013DFD8)], %o0
F00A2AA8: 80a22000                 cmp     %o0, 0
F00A2AAC: 02800061                 be      loc_F00A2C30
F00A2AB0: 901263d8                 or      %o1, %lo(dword_F013DFD8), %o0
F00A2AB4: 7ffffa55                 call    _del_first_pool
F00A2AB8: 90023ff8                 inc     -8, %o0
F00A2ABC: a4920000                 orcc    %o0, %g0, %l2
F00A2AC0: 32800006                 bne,a   loc_F00A2AD8
F00A2AC4: c024a008                 clr     [%l2+8]
F00A2AC8: 113c0464                 sethi   %hi(aPmapAllocSegEn_1), %o0! "pmap_alloc_seg_entry: seg_free.count wr"...
F00A2ACC: 7ffdc9a9                 call    _panic
F00A2AD0: 90122128                 bset    %lo(aPmapAllocSegEn_1), %o0! "pmap_alloc_seg_entry: seg_free.count wr"...
F00A2AD4: c024a008                 clr     [%l2+8]
F00A2AD8: 133c0447                 sethi   %hi(_page_size), %o1
F00A2ADC: d402613c                 ld      [%o1+%lo(_page_size)], %o2
F00A2AE0: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00A2AE4: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00A2AE8: 7fff8347                 call    _kmem_alloc_wired
F00A2AEC: 9204a008                 add     %l2, 8, %o1
F00A2AF0: 80a22000                 cmp     %o0, 0
F00A2AF4: 02800004                 be      loc_F00A2B04
F00A2AF8: 113c0464                 sethi   %hi(aPmapAllocSegEn_2), %o0! "pmap_alloc_seg_entry: no memory"
F00A2AFC: 7ffdc99d                 call    _panic
F00A2B00: 90122158                 bset    %lo(aPmapAllocSegEn_2), %o0! "pmap_alloc_seg_entry: no memory"
F00A2B04: 233c04f0                 sethi   %hi(_kernel_pmap), %l1
F00A2B08: d0046100                 ld      [%l1+%lo(_kernel_pmap)], %o0
F00A2B0C: 7ffff0de                 call    _pmap_resident_extract
F00A2B10: d204a008                 ld      [%l2+8], %o1
F00A2B14: 94100008                 mov     %o0, %o2
F00A2B18: 113c045d                 sethi   %hi(_mxcc), %o0
F00A2B1C: d00222d4                 ld      [%o0+%lo(_mxcc)], %o0
F00A2B20: 80a22000                 cmp     %o0, 0
F00A2B24: 1280000a                 bne     loc_F00A2B4C
F00A2B28: d424a004                 st      %o2, [%l2+4]
F00A2B2C: 96102001                 mov     1, %o3
F00A2B30: 98102007                 mov     7, %o4
F00A2B34: d204a008                 ld      [%l2+8], %o1
F00A2B38: 9a102000                 mov     0, %o5
F00A2B3C: d0046100                 ld      [%l1+%lo(_kernel_pmap)], %o0
F00A2B40: d623a05c                 st      %o3, [%sp+0x78+var_1C]
F00A2B44: 7fffecfd                 call    _pmap_enter_dev
F00A2B48: 96102000                 mov     0, %o3
F00A2B4C: 7fff8dfb                 call    _vm_mem_ppi
F00A2B50: d004a004                 ld      [%l2+4], %o0
F00A2B54: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F00A2B58: 932a2002                 sll     %o0, 2, %o1
F00A2B5C: d602a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o3
F00A2B60: 92024008                 add     %o1, %o0, %o1
F00A2B64: d0046100                 ld      [%l1+0x100], %o0
F00A2B68: 952a6002                 sll     %o1, 2, %o2
F00A2B6C: a002c00a                 add     %o3, %o2, %l0
F00A2B70: d2042004                 ld      [%l0+4], %o1
F00A2B74: 80a24008                 cmp     %o1, %o0
F00A2B78: 1280000d                 bne     loc_F00A2BAC
F00A2B7C: 113c0464                 sethi   -0xFEE7000, %o0
F00A2B80: d0042008                 ld      [%l0+8], %o0
F00A2B84: d204a008                 ld      [%l2+8], %o1
F00A2B88: 91322008                 srl     %o0, 8, %o0
F00A2B8C: 912a200c                 sll     %o0, 12, %o0
F00A2B90: 80a20009                 cmp     %o0, %o1
F00A2B94: 12800006                 bne     loc_F00A2BAC
F00A2B98: 113c0464                 sethi   -0xFEE7000, %o0
F00A2B9C: d002c00a                 ld      [%o3+%o2], %o0
F00A2BA0: 80a22000                 cmp     %o0, 0
F00A2BA4: 02800004                 be      loc_F00A2BB4
F00A2BA8: 113c0464                 sethi   -0xFEE7000, %o0! char *
F00A2BAC: 7ffdc971                 call    _panic
F00A2BB0: 90122178                 bset    0x178, %o0
F00A2BB4: e0248000                 st      %l0, [%l2]
F00A2BB8: e424200c                 st      %l2, [%l0+0xC]
F00A2BBC: d014a01e                 lduh    [%l2+0x1E], %o0
F00A2BC0: 153c04f7                 sethi   %hi(word_F013DE74), %o2
F00A2BC4: f004a018                 ld      [%l2+0x18], %i0
F00A2BC8: 90023fff                 inc     -1, %o0
F00A2BCC: d034a01e                 sth     %o0, [%l2+0x1E]
F00A2BD0: d012a274                 lduh    [%o2+%lo(word_F013DE74)], %o0
F00A2BD4: a2102000                 mov     0, %l1
F00A2BD8: 80a44008                 cmp     %l1, %o0
F00A2BDC: 16800009                 bge     loc_F00A2C00
F00A2BE0: d204a008                 ld      [%l2+8], %o1
F00A2BE4: d2260000                 st      %o1, [%i0]
F00A2BE8: 92026100                 inc     0x100, %o1
F00A2BEC: a2046001                 inc     %l1
F00A2BF0: d012a274                 lduh    [%o2+0x274], %o0
F00A2BF4: 80a44008                 cmp     %l1, %o0
F00A2BF8: 06bffffb                 bl      loc_F00A2BE4
F00A2BFC: b0062028                 inc     0x28, %i0 ! '('
F00A2C00: 173c04f79612e270         set     _pmap_info, %o3
F00A2C08: 113c04f7                 sethi   %hi(_seg_semi_active), %o0
F00A2C0C: d812e004                 lduh    [%o3+4], %o4
F00A2C10: 901223e0                 bset    %lo(_seg_semi_active), %o0
F00A2C14: d402e01c                 ld      [%o3+0x1C], %o2
F00A2C18: 92100012                 mov     %l2, %o1
F00A2C1C: 9402800c                 add     %o2, %o4, %o2
F00A2C20: 7ffff9e7                 call    _add_pool
F00A2C24: d422e01c                 st      %o2, [%o3+0x1C]
F00A2C28: 10bfff64                 ba      loc_F00A29B8
F00A2C2C: 133c04f7                 sethi   -0xFEC2400, %o1
F00A2C30: c027bff4                 clr     [%fp+var_C]
F00A2C34: 133c0447                 sethi   %hi(_page_size), %o1
F00A2C38: d402613c                 ld      [%o1+%lo(_page_size)], %o2
F00A2C3C: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00A2C40: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00A2C44: 7fff82f0                 call    _kmem_alloc_wired
F00A2C48: 9207bff4                 add     %fp, var_C, %o1
F00A2C4C: 80a22000                 cmp     %o0, 0
F00A2C50: 02800004                 be      loc_F00A2C60
F00A2C54: 113c0464                 sethi   %hi(aPmapAllocSegEn_3), %o0! "pmap_alloc_seg_entry: no memory"
F00A2C58: 7ffdc946                 call    _panic
F00A2C5C: 901221a8                 bset    %lo(aPmapAllocSegEn_3), %o0! "pmap_alloc_seg_entry: no memory"
F00A2C60: aa102000                 mov     0, %l5
F00A2C64: 133c04f7                 sethi   %hi(word_F013DE78), %o1! size_t
F00A2C68: d0126278                 lduh    [%o1+%lo(word_F013DE78)], %o0
F00A2C6C: a6102000                 mov     0, %l3
F00A2C70: 80a54008                 cmp     %l5, %o0
F00A2C74: 1680002c                 bge     loc_F00A2D24
F00A2C78: f007bff4                 ld      [%fp+var_C], %i0
F00A2C7C: 393c04f7                 sethi   -0xFEC2400, %i4
F00A2C80: 2d3c04f7                 sethi   -0xFEC2400, %l6
F00A2C84: 373c04f7                 sethi   -0xFEC2400, %i3
F00A2C88: b4100009                 mov     %o1, %i2
F00A2C8C: 7fff5910                 call    _zalloc
F00A2C90: d0072380                 ld      [%i4+0x380], %o0! void *
F00A2C94: a4100008                 mov     %o0, %l2
F00A2C98: 7fffc870                 call    _bzero
F00A2C9C: 92102020                 mov     0x20, %o1 ! ' '! size_t
F00A2CA0: f024a018                 st      %i0, [%l2+0x18]
F00A2CA4: d015a274                 lduh    [%l6+0x274], %o0
F00A2CA8: d034a01c                 sth     %o0, [%l2+0x1C]
F00A2CAC: d015a274                 lduh    [%l6+0x274], %o0
F00A2CB0: d034a01e                 sth     %o0, [%l2+0x1E]
F00A2CB4: d015a274                 lduh    [%l6+0x274], %o0
F00A2CB8: a2102000                 mov     0, %l1
F00A2CBC: 80a44008                 cmp     %l1, %o0
F00A2CC0: 36800011                 bge,a   loc_F00A2D04
F00A2CC4: ea24a014                 st      %l5, [%l2+0x14]
F00A2CC8: 293c04f7                 sethi   -0xFEC2400, %l4
F00A2CCC: a006200e                 add     %i0, 0xE, %l0
F00A2CD0: 90100018                 mov     %i0, %o0! void *
F00A2CD4: 7fffc861                 call    _bzero
F00A2CD8: 92102028                 mov     0x28, %o1 ! '('
F00A2CDC: e4243ff6                 st      %l2, [%l0-0xA]
F00A2CE0: c02c3fff                 clrb    [%l0-1]
F00A2CE4: e22c0000                 stb     %l1, [%l0]
F00A2CE8: a0042028                 inc     0x28, %l0 ! '('
F00A2CEC: d0152274                 lduh    [%l4+0x274], %o0
F00A2CF0: a2046001                 inc     %l1
F00A2CF4: 80a44008                 cmp     %l1, %o0
F00A2CF8: 06bffff6                 bl      loc_F00A2CD0
F00A2CFC: b0062028                 inc     0x28, %i0 ! '('
F00A2D00: ea24a014                 st      %l5, [%l2+0x14]
F00A2D04: 9016e3d0                 or      %i3, 0x3D0, %o0
F00A2D08: 7ffff9ad                 call    _add_pool
F00A2D0C: 92100012                 mov     %l2, %o1
F00A2D10: d016a278                 lduh    [%i2+0x278], %o0
F00A2D14: a604e001                 inc     %l3
F00A2D18: 80a4c008                 cmp     %l3, %o0
F00A2D1C: 06bfffdc                 bl      loc_F00A2C8C
F00A2D20: aa100012                 mov     %l2, %l5
F00A2D24: 153c04f79412a270         set     _pmap_info, %o2
F00A2D2C: d612a008                 lduh    [%o2+8], %o3
F00A2D30: d202a020                 ld      [%o2+0x20], %o1
F00A2D34: 113c04f7                 sethi   %hi(_garbage_zone), %o0
F00A2D38: d0022220                 ld      [%o0+%lo(_garbage_zone)], %o0
F00A2D3C: 9202400b                 add     %o1, %o3, %o1
F00A2D40: 7fff58e3                 call    _zalloc
F00A2D44: d222a020                 st      %o1, [%o2+0x20]
F00A2D48: 94100008                 mov     %o0, %o2
F00A2D4C: ea22a008                 st      %l5, [%o2+8]
F00A2D50: 113c04f7                 sethi   %hi(dword_F013DE1C), %o0
F00A2D54: d202221c                 ld      [%o0+%lo(dword_F013DE1C)], %o1
F00A2D58: 9612221c                 or      %o0, %lo(dword_F013DE1C), %o3
F00A2D5C: 9002fffc                 add     %o3, -4, %o0
F00A2D60: 80a24008                 cmp     %o1, %o0
F00A2D64: 32800003                 bne,a   loc_F00A2D70
F00A2D68: d4224000                 st      %o2, [%o1]
F00A2D6C: d422fffc                 st      %o2, [%o3-4]
F00A2D70: d222a004                 st      %o1, [%o2+4]
F00A2D74: 113c04f790122218         set     _garbage, %o0
F00A2D7C: d0228000                 st      %o0, [%o2]
F00A2D80: 10bfff0d                 ba      loc_F00A29B4
F00A2D84: d4222004                 st      %o2, [%o0+4]
F00A2D88: 81c7e008                 ret
F00A2D8C: 81e80000                 restore
