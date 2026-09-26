F00A153C: 9de3bf90                 save    %sp, -0x70, %sp
F00A1540: 153c04f79412a270         set     _pmap_info, %o2
F00A1548: d202a0c8                 ld      [%o2+0xC8], %o1
F00A154C: f227a048                 st      %i1, [%fp+arg_48]
F00A1550: f0060000                 ld      [%i0], %i0
F00A1554: 113c0447                 sethi   %hi(_page_size), %o0
F00A1558: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F00A155C: 92026001                 inc     %o1
F00A1560: 90023fff                 inc     -1, %o0
F00A1564: 808e4008                 btst    %o0, %i1
F00A1568: 02800005                 be      loc_F00A157C
F00A156C: d222a0c8                 st      %o1, [%o2+0xC8]
F00A1570: 113c0463                 sethi   %hi(aSetInvalidpteV), %o0! "set_invalidpte: va not aligned\n"
F00A1574: 7ffdceff                 call    _panic
F00A1578: 90122218                 bset    %lo(aSetInvalidpteV), %o0! "set_invalidpte: va not aligned\n"
F00A157C: d00e200d                 ldub    [%i0+0xD], %o0
F00A1580: 80a22003                 cmp     %o0, 3
F00A1584: 12800007                 bne     loc_F00A15A0
F00A1588: 80a22002                 cmp     %o0, 2
F00A158C: d007a048                 ld      [%fp+arg_48], %o0
F00A1590: d2060000                 ld      [%i0], %o1
F00A1594: 9132200a                 srl     %o0, 10, %o0
F00A1598: 1080000a                 ba      loc_F00A15C0
F00A159C: 900a20fc                 and     %o0, 0xFC, %o0
F00A15A0: 32800006                 bne,a   loc_F00A15B8
F00A15A4: d00fa048                 ldub    [%fp+arg_48], %o0
F00A15A8: d017a048                 lduh    [%fp+arg_48], %o0
F00A15AC: d2060000                 ld      [%i0], %o1
F00A15B0: 10800004                 ba      loc_F00A15C0
F00A15B4: 900a20fc                 and     %o0, 0xFC, %o0
F00A15B8: d2060000                 ld      [%i0], %o1
F00A15BC: 912a2002                 sll     %o0, 2, %o0
F00A15C0: b2024008                 add     %o1, %o0, %i1
F00A15C4: d00e200d                 ldub    [%i0+0xD], %o0
F00A15C8: 80a22003                 cmp     %o0, 3
F00A15CC: 12800006                 bne     loc_F00A15E4
F00A15D0: a0066004                 add     %i1, 4, %l0
F00A15D4: 113c04f7                 sethi   %hi(_pmap_info), %o0
F00A15D8: d0122270                 lduh    [%o0+%lo(_pmap_info)], %o0
F00A15DC: 912a2002                 sll     %o0, 2, %o0
F00A15E0: a0064008                 add     %i1, %o0, %l0
F00A15E4: d20e200f                 ldub    [%i0+0xF], %o1
F00A15E8: d0062008                 ld      [%i0+8], %o0
F00A15EC: 92027fff                 inc     -1, %o1
F00A15F0: 7fffff18                 call    _get_context
F00A15F4: d22e200f                 stb     %o1, [%i0+0xF]
F00A15F8: d20e200d                 ldub    [%i0+0xD], %o1
F00A15FC: 80a26003                 cmp     %o1, 3
F00A1600: 1280000a                 bne     loc_F00A1628
F00A1604: a4100008                 mov     %o0, %l2
F00A1608: d207a048                 ld      [%fp+arg_48], %o1
F00A160C: 90102001                 mov     1, %o0
F00A1610: 9332600c                 srl     %o1, 12, %o1
F00A1614: 95326003                 srl     %o1, 3, %o2
F00A1618: 940aa004                 and     %o2, 4, %o2
F00A161C: 94028018                 add     %o2, %i0, %o2
F00A1620: 1080000c                 ba      loc_F00A1650
F00A1624: 920a601e                 and     %o1, 0x1E, %o1
F00A1628: 80a26002                 cmp     %o1, 2
F00A162C: 1280000e                 bne     loc_F00A1664
F00A1630: d40fa048                 ldub    [%fp+arg_48], %o2
F00A1634: d207a048                 ld      [%fp+arg_48], %o1
F00A1638: 90102001                 mov     1, %o0
F00A163C: 93326012                 srl     %o1, 18, %o1
F00A1640: 95326003                 srl     %o1, 3, %o2
F00A1644: 940aa004                 and     %o2, 4, %o2
F00A1648: 94028018                 add     %o2, %i0, %o2
F00A164C: 920a601f                 and     %o1, 0x1F, %o1
F00A1650: d602a018                 ld      [%o2+0x18], %o3
F00A1654: 912a0009                 sll     %o0, %o1, %o0
F00A1658: 902ac008                 andn    %o3, %o0, %o0
F00A165C: 1080000b                 ba      loc_F00A1688
F00A1660: d022a018                 st      %o0, [%o2+0x18]
F00A1664: 90102001                 mov     1, %o0
F00A1668: 9332a005                 srl     %o2, 5, %o1
F00A166C: 932a6002                 sll     %o1, 2, %o1
F00A1670: 92024018                 add     %o1, %i0, %o1
F00A1674: 940aa01f                 and     %o2, 0x1F, %o2
F00A1678: d6026030                 ld      [%o1+0x30], %o3
F00A167C: 912a000a                 sll     %o0, %o2, %o0
F00A1680: 902ac008                 andn    %o3, %o0, %o0
F00A1684: d0226030                 st      %o0, [%o1+0x30]
F00A1688: 7ffff173                 call    _check_pmap
F00A168C: 90100018                 mov     %i0, %o0
F00A1690: 80a64010                 cmp     %i1, %l0
F00A1694: 1a800013                 bcc     locret_F00A16E0
F00A1698: c027bff4                 clr     [%fp+var_C]
F00A169C: 23000004                 sethi   0x1000, %l1
F00A16A0: d007bff4                 ld      [%fp+var_C], %o0
F00A16A4: d407a048                 ld      [%fp+arg_48], %o2
F00A16A8: 92100019                 mov     %i1, %o1
F00A16AC: d60e200d                 ldub    [%i0+0xD], %o3
F00A16B0: 7fffd036                 call    _mmu_writepte
F00A16B4: 98100012                 mov     %l2, %o4
F00A16B8: d00e200d                 ldub    [%i0+0xD], %o0
F00A16BC: 80a22003                 cmp     %o0, 3
F00A16C0: 12800005                 bne     loc_F00A16D4
F00A16C4: b2066004                 inc     4, %i1
F00A16C8: d007a048                 ld      [%fp+arg_48], %o0
F00A16CC: 90020011                 add     %o0, %l1, %o0
F00A16D0: d027a048                 st      %o0, [%fp+arg_48]
F00A16D4: 80a64010                 cmp     %i1, %l0
F00A16D8: 0abffff3                 bcs     loc_F00A16A4
F00A16DC: d007bff4                 ld      [%fp+var_C], %o0
F00A16E0: 81c7e008                 ret
F00A16E4: 81e80000                 restore
