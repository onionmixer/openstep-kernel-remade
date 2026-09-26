F009E758: 9de3bf90                 save    %sp, -0x70, %sp
F009E75C: f027a044                 st      %i0, [%fp+arg_44]
F009E760: 153c04f79412a270         set     _pmap_info, %o2
F009E768: d002a070                 ld      [%o2+0x70], %o0
F009E76C: 133c04d0                 sethi   %hi(_page_mask), %o1
F009E770: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F009E774: 90022001                 inc     %o0
F009E778: 808e8009                 btst    %o1, %i2
F009E77C: 02800005                 be      loc_F009E790
F009E780: d022a070                 st      %o0, [%o2+0x70]
F009E784: 113c045f                 sethi   %hi(aPmapMovePagePa), %o0! "pmap_move_page: partial machine indepen"...
F009E788: 7ffdda7a                 call    _panic
F009E78C: 90122398                 bset    %lo(aPmapMovePagePa), %o0! "pmap_move_page: partial machine indepen"...
F009E790: d207a044                 ld      [%fp+arg_44], %o1
F009E794: b402401a                 add     %o1, %i2, %i2
F009E798: 80a2401a                 cmp     %o1, %i2
F009E79C: 1a800088                 bcc     locret_F009E9BC
F009E7A0: 2f3c04f0                 sethi   %hi(_kernel_pmap), %l7
F009E7A4: ac102001                 mov     1, %l6
F009E7A8: 2b000100                 sethi   0x40000, %l5
F009E7AC: 29004000                 sethi   0x1000000, %l4
F009E7B0: 273c0447                 sethi   -0xFEEE400, %l3
F009E7B4: d005e100                 ld      [%l7+%lo(_kernel_pmap)], %o0
F009E7B8: 7ffff880                 call    _pmap_page_table_entry
F009E7BC: 94102000                 mov     0, %o2
F009E7C0: b0920000                 orcc    %o0, %g0, %i0
F009E7C4: 32800006                 bne,a   loc_F009E7DC
F009E7C8: d00e200d                 ldub    [%i0+0xD], %o0
F009E7CC: 113c045f                 sethi   %hi(aPmapMovePageFr), %o0! "pmap_move_page: from not mapped"
F009E7D0: 7ffdda68                 call    _panic
F009E7D4: 901223d0                 bset    %lo(aPmapMovePageFr), %o0! "pmap_move_page: from not mapped"
F009E7D8: d00e200d                 ldub    [%i0+0xD], %o0
F009E7DC: 80a22003                 cmp     %o0, 3
F009E7E0: 12800007                 bne     loc_F009E7FC
F009E7E4: 80a22002                 cmp     %o0, 2
F009E7E8: d007a044                 ld      [%fp+arg_44], %o0
F009E7EC: d2060000                 ld      [%i0], %o1
F009E7F0: 9132200a                 srl     %o0, 10, %o0
F009E7F4: 1080000a                 ba      loc_F009E81C
F009E7F8: 900a20fc                 and     %o0, 0xFC, %o0
F009E7FC: 32800006                 bne,a   loc_F009E814
F009E800: d00fa044                 ldub    [%fp+arg_44], %o0
F009E804: d017a044                 lduh    [%fp+arg_44], %o0
F009E808: d2060000                 ld      [%i0], %o1
F009E80C: 10800004                 ba      loc_F009E81C
F009E810: 900a20fc                 and     %o0, 0xFC, %o0
F009E814: d2060000                 ld      [%i0], %o1
F009E818: 912a2002                 sll     %o0, 2, %o0
F009E81C: a0024008                 add     %o1, %o0, %l0
F009E820: d0040000                 ld      [%l0], %o0
F009E824: 900a2003                 and     %o0, 3, %o0
F009E828: 80a22002                 cmp     %o0, 2
F009E82C: 02800004                 be      loc_F009E83C
F009E830: 113c045f                 sethi   %hi(aPmapMovePageNu), %o0! "pmap_move_page: null pte"
F009E834: 7ffdda4f                 call    _panic
F009E838: 901223f0                 bset    %lo(aPmapMovePageNu), %o0! "pmap_move_page: null pte"
F009E83C: d00e200d                 ldub    [%i0+0xD], %o0
F009E840: 80a22003                 cmp     %o0, 3
F009E844: 12800009                 bne     loc_F009E868
F009E848: 80a22002                 cmp     %o0, 2
F009E84C: d007a044                 ld      [%fp+arg_44], %o0
F009E850: 9132200c                 srl     %o0, 12, %o0
F009E854: 93322003                 srl     %o0, 3, %o1
F009E858: 920a6004                 and     %o1, 4, %o1
F009E85C: 92024018                 add     %o1, %i0, %o1
F009E860: 1080000d                 ba      loc_F009E894
F009E864: 900a201e                 and     %o0, 0x1E, %o0
F009E868: 32800007                 bne,a   loc_F009E884
F009E86C: d00fa044                 ldub    [%fp+arg_44], %o0
F009E870: d007a044                 ld      [%fp+arg_44], %o0
F009E874: 91322012                 srl     %o0, 18, %o0
F009E878: 93322003                 srl     %o0, 3, %o1
F009E87C: 10800004                 ba      loc_F009E88C
F009E880: 920a6004                 and     %o1, 4, %o1
F009E884: 93322005                 srl     %o0, 5, %o1
F009E888: 932a6002                 sll     %o1, 2, %o1
F009E88C: 92024018                 add     %o1, %i0, %o1
F009E890: 900a201f                 and     %o0, 0x1F, %o0
F009E894: d2026010                 ld      [%o1+0x10], %o1
F009E898: 912d8008                 sll     %l6, %o0, %o0
F009E89C: a20a4008                 and     %o1, %o0, %l1
F009E8A0: d0040000                 ld      [%l0], %o0
F009E8A4: f00e200d                 ldub    [%i0+0xD], %i0
F009E8A8: 91322002                 srl     %o0, 2, %o0
F009E8AC: 40000b17                 call    _srmmu_to_vm_prot
F009E8B0: 900a2007                 and     %o0, 7, %o0
F009E8B4: 80a62003                 cmp     %i0, 3
F009E8B8: d605e100                 ld      [%l7+0x100], %o3
F009E8BC: 02800009                 be      loc_F009E8E0
F009E8C0: a4100008                 mov     %o0, %l2
F009E8C4: 80a62002                 cmp     %i0, 2
F009E8C8: 12800004                 bne     loc_F009E8D8
F009E8CC: d007a044                 ld      [%fp+arg_44], %o0
F009E8D0: 10800007                 ba      loc_F009E8EC
F009E8D4: 94020015                 add     %o0, %l5, %o2
F009E8D8: 10800005                 ba      loc_F009E8EC
F009E8DC: 94020014                 add     %o0, %l4, %o2
F009E8E0: d207a044                 ld      [%fp+arg_44], %o1
F009E8E4: d004e13c                 ld      [%l3+0x13C], %o0
F009E8E8: 94024008                 add     %o1, %o0, %o2
F009E8EC: d207a044                 ld      [%fp+arg_44], %o1
F009E8F0: 7ffffa23                 call    _pmap_remove
F009E8F4: 9010000b                 mov     %o3, %o0
F009E8F8: d0040000                 ld      [%l0], %o0
F009E8FC: 80a62003                 cmp     %i0, 3
F009E900: d205e100                 ld      [%l7+0x100], %o1
F009E904: 91322008                 srl     %o0, 8, %o0
F009E908: 952a200c                 sll     %o0, 12, %o2
F009E90C: 02800007                 be      loc_F009E928
F009E910: 9b322014                 srl     %o0, 20, %o5
F009E914: 80a62002                 cmp     %i0, 2
F009E918: 12800005                 bne     loc_F009E92C
F009E91C: 19004000                 sethi   0x1000000, %o4
F009E920: 10800003                 ba      loc_F009E92C
F009E924: 19000100                 sethi   0x40000, %o4
F009E928: d804e13c                 ld      [%l3+0x13C], %o4
F009E92C: 90100009                 mov     %o1, %o0
F009E930: d6040000                 ld      [%l0], %o3
F009E934: 92100019                 mov     %i1, %o1
F009E938: 9732e007                 srl     %o3, 7, %o3
F009E93C: 960ae001                 and     %o3, 1, %o3
F009E940: d623a05c                 st      %o3, [%sp+0x70+var_14]
F009E944: e223a060                 st      %l1, [%sp+0x70+var_10]
F009E948: 9610000d                 mov     %o5, %o3
F009E94C: 7ffffec2                 call    _pmap_enter_range
F009E950: 9a100012                 mov     %l2, %o5
F009E954: 80a62003                 cmp     %i0, 3
F009E958: 02800008                 be      loc_F009E978
F009E95C: 80a62002                 cmp     %i0, 2
F009E960: 12800004                 bne     loc_F009E970
F009E964: d007a044                 ld      [%fp+arg_44], %o0
F009E968: 10800007                 ba      loc_F009E984
F009E96C: 90020015                 add     %o0, %l5, %o0
F009E970: 10800005                 ba      loc_F009E984
F009E974: 90020014                 add     %o0, %l4, %o0
F009E978: d007a044                 ld      [%fp+arg_44], %o0
F009E97C: d204e13c                 ld      [%l3+0x13C], %o1
F009E980: 90020009                 add     %o0, %o1, %o0
F009E984: 80a62003                 cmp     %i0, 3
F009E988: 02800007                 be      loc_F009E9A4
F009E98C: d027a044                 st      %o0, [%fp+arg_44]
F009E990: 80a62002                 cmp     %i0, 2
F009E994: 32800006                 bne,a   loc_F009E9AC
F009E998: b2064014                 add     %i1, %l4, %i1
F009E99C: 10800004                 ba      loc_F009E9AC
F009E9A0: b2064015                 add     %i1, %l5, %i1
F009E9A4: d004e13c                 ld      [%l3+0x13C], %o0
F009E9A8: b2064008                 add     %i1, %o0, %i1
F009E9AC: d207a044                 ld      [%fp+arg_44], %o1
F009E9B0: 80a2401a                 cmp     %o1, %i2
F009E9B4: 0abfff81                 bcs     loc_F009E7B8
F009E9B8: d005e100                 ld      [%l7+0x100], %o0
F009E9BC: 81c7e008                 ret
F009E9C0: 81e80000                 restore
