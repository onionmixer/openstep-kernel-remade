F00A16E8: 9de3bf90                 save    %sp, -0x70, %sp
F00A16EC: 153c04f79412a270         set     _pmap_info, %o2
F00A16F4: d202a0cc                 ld      [%o2+0xCC], %o1
F00A16F8: f227a048                 st      %i1, [%fp+arg_48]
F00A16FC: f0060000                 ld      [%i0], %i0
F00A1700: 113c0447                 sethi   %hi(_page_size), %o0
F00A1704: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F00A1708: 92026001                 inc     %o1
F00A170C: 90023fff                 inc     -1, %o0
F00A1710: 808e4008                 btst    %o0, %i1
F00A1714: 02800005                 be      loc_F00A1728
F00A1718: d222a0cc                 st      %o1, [%o2+0xCC]
F00A171C: 113c0463                 sethi   %hi(aUpdatePteVaNot), %o0! "update_pte: va not aligned\n"
F00A1720: 7ffdce94                 call    _panic
F00A1724: 90122238                 bset    %lo(aUpdatePteVaNot), %o0! "update_pte: va not aligned\n"
F00A1728: d00e200d                 ldub    [%i0+0xD], %o0
F00A172C: 80a22003                 cmp     %o0, 3
F00A1730: 12800007                 bne     loc_F00A174C
F00A1734: 80a22002                 cmp     %o0, 2
F00A1738: d007a048                 ld      [%fp+arg_48], %o0
F00A173C: d2060000                 ld      [%i0], %o1
F00A1740: 9132200a                 srl     %o0, 10, %o0
F00A1744: 1080000a                 ba      loc_F00A176C
F00A1748: 900a20fc                 and     %o0, 0xFC, %o0
F00A174C: 32800006                 bne,a   loc_F00A1764
F00A1750: d00fa048                 ldub    [%fp+arg_48], %o0
F00A1754: d017a048                 lduh    [%fp+arg_48], %o0
F00A1758: d2060000                 ld      [%i0], %o1
F00A175C: 10800004                 ba      loc_F00A176C
F00A1760: 900a20fc                 and     %o0, 0xFC, %o0
F00A1764: d2060000                 ld      [%i0], %o1
F00A1768: 912a2002                 sll     %o0, 2, %o0
F00A176C: b2024008                 add     %o1, %o0, %i1
F00A1770: d00e200d                 ldub    [%i0+0xD], %o0
F00A1774: 80a22003                 cmp     %o0, 3
F00A1778: 12800006                 bne     loc_F00A1790
F00A177C: a0066004                 add     %i1, 4, %l0
F00A1780: 113c04f7                 sethi   %hi(_pmap_info), %o0
F00A1784: d0122270                 lduh    [%o0+%lo(_pmap_info)], %o0
F00A1788: 912a2002                 sll     %o0, 2, %o0
F00A178C: a0064008                 add     %i1, %o0, %l0
F00A1790: 7ffffeb0                 call    _get_context
F00A1794: d0062008                 ld      [%i0+8], %o0
F00A1798: a4100008                 mov     %o0, %l2
F00A179C: 7ffff12e                 call    _check_pmap
F00A17A0: 90100018                 mov     %i0, %o0
F00A17A4: 80a64010                 cmp     %i1, %l0
F00A17A8: 1a80001a                 bcc     locret_F00A1810
F00A17AC: 900ea007                 and     %i2, 7, %o0
F00A17B0: a32a2002                 sll     %o0, 2, %l1
F00A17B4: 900ee001                 and     %i3, 1, %o0
F00A17B8: b52a2007                 sll     %o0, 7, %i2
F00A17BC: 37000004                 sethi   0x1000, %i3
F00A17C0: d0064000                 ld      [%i1], %o0
F00A17C4: 92100019                 mov     %i1, %o1
F00A17C8: d407a048                 ld      [%fp+arg_48], %o2
F00A17CC: 900a3f63                 and     %o0, -0x9D, %o0
F00A17D0: 90120011                 bset    %l1, %o0
F00A17D4: 9012001a                 bset    %i2, %o0
F00A17D8: d027bff4                 st      %o0, [%fp+var_C]
F00A17DC: d60e200d                 ldub    [%i0+0xD], %o3
F00A17E0: 7fffcfea                 call    _mmu_writepte
F00A17E4: 98100012                 mov     %l2, %o4
F00A17E8: d00e200d                 ldub    [%i0+0xD], %o0
F00A17EC: 80a22003                 cmp     %o0, 3
F00A17F0: 12800005                 bne     loc_F00A1804
F00A17F4: b2066004                 inc     4, %i1
F00A17F8: d007a048                 ld      [%fp+arg_48], %o0
F00A17FC: 9002001b                 add     %o0, %i3, %o0
F00A1800: d027a048                 st      %o0, [%fp+arg_48]
F00A1804: 80a64010                 cmp     %i1, %l0
F00A1808: 2abfffef                 bcs,a   loc_F00A17C4
F00A180C: d0064000                 ld      [%i1], %o0
F00A1810: 81c7e008                 ret
F00A1814: 81e80000                 restore
