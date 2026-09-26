F009093C: 9de3bf90                 save    %sp, -0x70, %sp
F0090940: d207a05c                 ld      [%fp+arg_5C], %o1
F0090944: 80a26000                 cmp     %o1, 0
F0090948: 02800007                 be      loc_F0090964
F009094C: 90100018                 mov     %i0, %o0! id
F0090950: 80a26001                 cmp     %o1, 1
F0090954: 02800005                 be      loc_F0090968
F0090958: a8102001                 mov     1, %l4
F009095C: 10800003                 ba      loc_F0090968
F0090960: a8102000                 mov     0, %l4
F0090964: a8102002                 mov     2, %l4
F0090968: 133c0504                 sethi   %hi(paDevicedescript_1), %o1
F009096C: d2026158                 ld      [%o1+%lo(paDevicedescript_1)], %o1! SEL
F0090970: 400183c0                 call    _objc_msgSend
F0090974: a0102000                 mov     0, %l0
F0090978: 133c0504                 sethi   %hi(paResourcesforke), %o1
F009097C: 153c0448                 sethi   %hi(aMemoryMaps_1), %o2! "Memory Maps"
F0090980: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F0090984: 400183bb                 call    _objc_msgSend
F0090988: 9412a1b0                 bset    %lo(aMemoryMaps_1), %o2! "Memory Maps"
F009098C: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F0090990: a2100008                 mov     %o0, %l1
F0090994: 400183b7                 call    _objc_msgSend
F0090998: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F009099C: b0100008                 mov     %o0, %i0
F00909A0: 80a40018                 cmp     %l0, %i0
F00909A4: 1680001c                 bge     loc_F0090A14
F00909A8: 90100011                 mov     %l1, %o0! id
F00909AC: 2d3c0504                 sethi   -0xFEBF000, %l6
F00909B0: 2b3c0504                 sethi   -0xFEBF000, %l5
F00909B4: a607bff0                 add     %fp, var_10, %l3
F00909B8: a406801b                 add     %i2, %i3, %l2
F00909BC: d205a0c8                 ld      [%l6+0xC8], %o1! SEL
F00909C0: 400183ac                 call    _objc_msgSend
F00909C4: 94100010                 mov     %l0, %o2
F00909C8: d2056058                 ld      [%l5+0x58], %o1! SEL
F00909CC: e623a040                 st      %l3, [%sp+0x70+var_30]
F00909D0: 400183a8                 call    _objc_msgSend
F00909D4: 01000000                 nop
F00909D8: 00000008                 illtrap
F00909DC: d207bff0                 ld      [%fp+var_10], %o1
F00909E0: 80a2401a                 cmp     %o1, %i2
F00909E4: 38800008                 bgu,a   loc_F0090A04
F00909E8: a0042001                 inc     %l0
F00909EC: d007bff4                 ld      [%fp+var_C], %o0
F00909F0: 90024008                 add     %o1, %o0, %o0
F00909F4: 80a20012                 cmp     %o0, %l2
F00909F8: 1a800007                 bcc     loc_F0090A14
F00909FC: 80a40018                 cmp     %l0, %i0
F0090A00: a0042001                 inc     %l0
F0090A04: 80a40018                 cmp     %l0, %i0
F0090A08: 06bfffed                 bl      loc_F00909BC
F0090A0C: 90100011                 mov     %l1, %o0
F0090A10: 80a40018                 cmp     %l0, %i0
F0090A14: 12800004                 bne     loc_F0090A24
F0090A18: 80a76000                 cmp     %i5, 0
F0090A1C: 10800040                 ba      locret_F0090B1C
F0090A20: b0103d3f                 mov     -0x2C1, %i0
F0090A24: 02800004                 be      loc_F0090A34
F0090A28: 113c04d0                 sethi   -0xFECC000, %o0
F0090A2C: 10800005                 ba      loc_F0090A40
F0090A30: d0066014                 ld      [%i1+0x14], %o0
F0090A34: d00220d8                 ld      [%o0+0xD8], %o0
F0090A38: d2070000                 ld      [%i4], %o1
F0090A3C: 902a4008                 andn    %o1, %o0, %o0
F0090A40: d0270000                 st      %o0, [%i4]
F0090A44: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0090A48: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0090A4C: 80a64008                 cmp     %i1, %o0
F0090A50: 1280000c                 bne     loc_F0090A80
F0090A54: 90100019                 mov     %i1, %o0
F0090A58: 80a76000                 cmp     %i5, 0
F0090A5C: 1280000a                 bne     loc_F0090A84
F0090A60: 92102000                 mov     0, %o1
F0090A64: d2070000                 ld      [%i4], %o1
F0090A68: 110003ff901223ff         set     0xFFFFF, %o0
F0090A70: 80a24008                 cmp     %o1, %o0
F0090A74: 0880002a                 bleu    locret_F0090B1C
F0090A78: b0102000                 mov     0, %i0
F0090A7C: 90100019                 mov     %i1, %o0
F0090A80: 92102000                 mov     0, %o1
F0090A84: 94102000                 mov     0, %o2
F0090A88: 9610001c                 mov     %i4, %o3
F0090A8C: 9810001b                 mov     %i3, %o4
F0090A90: 7fffced0                 call    _vm_map_find
F0090A94: 9a10001d                 mov     %i5, %o5
F0090A98: 80a22000                 cmp     %o0, 0
F0090A9C: 12800020                 bne     locret_F0090B1C
F0090AA0: b0103d25                 mov     -0x2DB, %i0
F0090AA4: 90100019                 mov     %i1, %o0
F0090AA8: 213c04d0                 sethi   %hi(_page_mask), %l0
F0090AAC: d20420d8                 ld      [%l0+%lo(_page_mask)], %o1
F0090AB0: 96102002                 mov     2, %o3
F0090AB4: f8070000                 ld      [%i4], %i4
F0090AB8: 94380009                 xnor    %g0, %o1, %o2
F0090ABC: b80f000a                 and     %i4, %o2, %i4
F0090AC0: 9206c009                 add     %i3, %o1, %o1
F0090AC4: b60a400a                 and     %o1, %o2, %i3
F0090AC8: 9210001c                 mov     %i4, %o1
F0090ACC: 7fffd083                 call    _vm_map_inherit
F0090AD0: 9407001b                 add     %i4, %i3, %o2
F0090AD4: d00420d8                 ld      [%l0+%lo(_page_mask)], %o0
F0090AD8: 80a6e000                 cmp     %i3, 0
F0090ADC: 0280000f                 be      loc_F0090B18
F0090AE0: b42e8008                 bclr    %o0, %i2
F0090AE4: 213c0447                 sethi   -0xFEEE400, %l0
F0090AE8: 9210001c                 mov     %i4, %o1
F0090AEC: 9410001a                 mov     %i2, %o2
F0090AF0: 96102003                 mov     3, %o3
F0090AF4: 98102001                 mov     1, %o4
F0090AF8: d0066024                 ld      [%i1+0x24], %o0
F0090AFC: 40003677                 call    _pmap_enter_cache_spec
F0090B00: 9a100014                 mov     %l4, %o5
F0090B04: d004213c                 ld      [%l0+0x13C], %o0
F0090B08: b8070008                 add     %i4, %o0, %i4
F0090B0C: b6a6c008                 subcc   %i3, %o0, %i3
F0090B10: 12bffff6                 bne     loc_F0090AE8
F0090B14: b4068008                 add     %i2, %o0, %i2
F0090B18: b0102000                 mov     0, %i0
F0090B1C: 81c7e008                 ret
F0090B20: 81e80000                 restore
