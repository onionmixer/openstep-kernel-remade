F00A1988: 9de3bf90                 save    %sp, -0x70, %sp
F00A198C: 153c04f79412a270         set     _pmap_info, %o2
F00A1994: d202a0d4                 ld      [%o2+0xD4], %o1
F00A1998: f227a048                 st      %i1, [%fp+arg_48]
F00A199C: e0060000                 ld      [%i0], %l0
F00A19A0: 113c0447                 sethi   %hi(_page_size), %o0
F00A19A4: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F00A19A8: 92026001                 inc     %o1
F00A19AC: 90023fff                 inc     -1, %o0
F00A19B0: 808e4008                 btst    %o0, %i1
F00A19B4: 02800005                 be      loc_F00A19C8
F00A19B8: d222a0d4                 st      %o1, [%o2+0xD4]
F00A19BC: 113c0463                 sethi   %hi(aSetPteModrefVa), %o0! "set_pte_modref: va not aligned\n"
F00A19C0: 7ffdcdec                 call    _panic
F00A19C4: 90122278                 bset    %lo(aSetPteModrefVa), %o0! "set_pte_modref: va not aligned\n"
F00A19C8: d00c200d                 ldub    [%l0+0xD], %o0
F00A19CC: 80a22003                 cmp     %o0, 3
F00A19D0: 12800007                 bne     loc_F00A19EC
F00A19D4: 80a22002                 cmp     %o0, 2
F00A19D8: d007a048                 ld      [%fp+arg_48], %o0
F00A19DC: d2040000                 ld      [%l0], %o1
F00A19E0: 9132200a                 srl     %o0, 10, %o0
F00A19E4: 1080000a                 ba      loc_F00A1A0C
F00A19E8: 900a20fc                 and     %o0, 0xFC, %o0
F00A19EC: 32800006                 bne,a   loc_F00A1A04
F00A19F0: d00fa048                 ldub    [%fp+arg_48], %o0
F00A19F4: d017a048                 lduh    [%fp+arg_48], %o0
F00A19F8: d2040000                 ld      [%l0], %o1
F00A19FC: 10800004                 ba      loc_F00A1A0C
F00A1A00: 900a20fc                 and     %o0, 0xFC, %o0
F00A1A04: d2040000                 ld      [%l0], %o1
F00A1A08: 912a2002                 sll     %o0, 2, %o0
F00A1A0C: b2024008                 add     %o1, %o0, %i1
F00A1A10: d00c200d                 ldub    [%l0+0xD], %o0
F00A1A14: 80a22003                 cmp     %o0, 3
F00A1A18: 12800006                 bne     loc_F00A1A30
F00A1A1C: a2066004                 add     %i1, 4, %l1
F00A1A20: 113c04f7                 sethi   %hi(_pmap_info), %o0
F00A1A24: d0122270                 lduh    [%o0+%lo(_pmap_info)], %o0
F00A1A28: 912a2002                 sll     %o0, 2, %o0
F00A1A2C: a2064008                 add     %i1, %o0, %l1
F00A1A30: d0042008                 ld      [%l0+8], %o0
F00A1A34: 7ffffe07                 call    _get_context
F00A1A38: b0102000                 mov     0, %i0
F00A1A3C: a4100008                 mov     %o0, %l2
F00A1A40: 7ffff085                 call    _check_pmap
F00A1A44: 90100010                 mov     %l0, %o0
F00A1A48: 80a64011                 cmp     %i1, %l1
F00A1A4C: 1a80002c                 bcc     locret_F00A1AFC
F00A1A50: 27000004                 sethi   0x1000, %l3
F00A1A54: d0064000                 ld      [%i1], %o0
F00A1A58: 80a6a000                 cmp     %i2, 0
F00A1A5C: 02800009                 be      loc_F00A1A80
F00A1A60: d027bff4                 st      %o0, [%fp+var_C]
F00A1A64: 80a6e000                 cmp     %i3, 0
F00A1A68: 02800005                 be      loc_F00A1A7C
F00A1A6C: 900a3f9f                 and     %o0, -0x61, %o0
F00A1A70: d027bff4                 st      %o0, [%fp+var_C]
F00A1A74: 10800012                 ba      loc_F00A1ABC
F00A1A78: b0102001                 mov     1, %i0
F00A1A7C: 80a6a000                 cmp     %i2, 0
F00A1A80: 02800005                 be      loc_F00A1A94
F00A1A84: d007bff4                 ld      [%fp+var_C], %o0
F00A1A88: b0102001                 mov     1, %i0
F00A1A8C: 1080000b                 ba      loc_F00A1AB8
F00A1A90: 900a3fbf                 and     %o0, -0x41, %o0
F00A1A94: 80a6e000                 cmp     %i3, 0
F00A1A98: 02800009                 be      loc_F00A1ABC
F00A1A9C: d207bff4                 ld      [%fp+var_C], %o1
F00A1AA0: 900a7fdf                 and     %o1, -0x21, %o0
F00A1AA4: 808a6040                 btst    0x40, %o1 ! '@'
F00A1AA8: 02800005                 be      loc_F00A1ABC
F00A1AAC: d027bff4                 st      %o0, [%fp+var_C]
F00A1AB0: b0102002                 mov     2, %i0
F00A1AB4: 900a7f9f                 and     %o1, -0x61, %o0
F00A1AB8: d027bff4                 st      %o0, [%fp+var_C]
F00A1ABC: d007bff4                 ld      [%fp+var_C], %o0
F00A1AC0: d407a048                 ld      [%fp+arg_48], %o2
F00A1AC4: 92100019                 mov     %i1, %o1
F00A1AC8: d60c200d                 ldub    [%l0+0xD], %o3
F00A1ACC: 7fffcf2f                 call    _mmu_writepte
F00A1AD0: 98100012                 mov     %l2, %o4
F00A1AD4: d00c200d                 ldub    [%l0+0xD], %o0
F00A1AD8: 80a22003                 cmp     %o0, 3
F00A1ADC: 12800005                 bne     loc_F00A1AF0
F00A1AE0: b2066004                 inc     4, %i1
F00A1AE4: d007a048                 ld      [%fp+arg_48], %o0
F00A1AE8: 90020013                 add     %o0, %l3, %o0
F00A1AEC: d027a048                 st      %o0, [%fp+arg_48]
F00A1AF0: 80a64011                 cmp     %i1, %l1
F00A1AF4: 2abfffd9                 bcs,a   loc_F00A1A58
F00A1AF8: d0064000                 ld      [%i1], %o0
F00A1AFC: 81c7e008                 ret
F00A1B00: 81e80000                 restore
