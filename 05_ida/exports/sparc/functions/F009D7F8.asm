F009D7F8: 9de3bf90                 save    %sp, -0x70, %sp
F009D7FC: 113c0464                 sethi   %hi(_physmax), %o0
F009D800: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009D804: 80a60008                 cmp     %i0, %o0
F009D808: 1a8000fd                 bcc     locret_F009DBFC
F009D80C: 01000000                 nop
F009D810: 7fffa2f0                 call    _vm_valid_page
F009D814: 90100018                 mov     %i0, %o0
F009D818: 80a22000                 cmp     %o0, 0
F009D81C: 028000f8                 be      locret_F009DBFC
F009D820: 133c04f7                 sethi   %hi(_pmap_info), %o1
F009D824: 92126270                 bset    %lo(_pmap_info), %o1
F009D828: d0026058                 ld      [%o1+0x58], %o0
F009D82C: 90022001                 inc     %o0
F009D830: 7fffe533                 call    _splvm
F009D834: d0226058                 st      %o0, [%o1+0x58]
F009D838: b2100008                 mov     %o0, %i1
F009D83C: 7fffa2bf                 call    _vm_mem_ppi
F009D840: 90100018                 mov     %i0, %o0
F009D844: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F009D848: 932a2002                 sll     %o0, 2, %o1
F009D84C: 92024008                 add     %o1, %o0, %o1
F009D850: d002a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o0
F009D854: 932a6002                 sll     %o1, 2, %o1
F009D858: a4020009                 add     %o0, %o1, %l2
F009D85C: e604a004                 ld      [%l2+4], %l3
F009D860: 80a4e000                 cmp     %l3, 0
F009D864: 028000e4                 be      loc_F009DBF4
F009D868: a8100012                 mov     %l2, %l4
F009D86C: aa102001                 mov     1, %l5
F009D870: ac102000                 mov     0, %l6
F009D874: ae102000                 mov     0, %l7
F009D878: d004a008                 ld      [%l2+8], %o0
F009D87C: a004e018                 add     %l3, 0x18, %l0
F009D880: 91322008                 srl     %o0, 8, %o0
F009D884: 912a200c                 sll     %o0, 12, %o0
F009D888: d027bff4                 st      %o0, [%fp+var_C]
F009D88C: d0040000                 ld      [%l0], %o0
F009D890: 80a22000                 cmp     %o0, 0
F009D894: 12bffffe                 bne     loc_F009D88C
F009D898: 01000000                 nop
F009D89C: 7fffe583                 call    _simple_lock_try
F009D8A0: 90100010                 mov     %l0, %o0
F009D8A4: 80a22000                 cmp     %o0, 0
F009D8A8: 02bffff9                 be      loc_F009D88C
F009D8AC: 90100013                 mov     %l3, %o0
F009D8B0: d207bff4                 ld      [%fp+var_C], %o1
F009D8B4: 7ffffc41                 call    _pmap_page_table_entry
F009D8B8: 94102000                 mov     0, %o2
F009D8BC: a0920000                 orcc    %o0, %g0, %l0
F009D8C0: 02800019                 be      loc_F009D924
F009D8C4: 113c045f                 sethi   -0xFEE8400, %o0
F009D8C8: d00c200d                 ldub    [%l0+0xD], %o0
F009D8CC: 80a22003                 cmp     %o0, 3
F009D8D0: 12800007                 bne     loc_F009D8EC
F009D8D4: 80a22002                 cmp     %o0, 2
F009D8D8: d007bff4                 ld      [%fp+var_C], %o0
F009D8DC: d2040000                 ld      [%l0], %o1
F009D8E0: 9132200a                 srl     %o0, 10, %o0
F009D8E4: 1080000a                 ba      loc_F009D90C
F009D8E8: 900a20fc                 and     %o0, 0xFC, %o0
F009D8EC: 32800006                 bne,a   loc_F009D904
F009D8F0: d00fbff4                 ldub    [%fp+var_C], %o0
F009D8F4: d017bff4                 lduh    [%fp+var_C], %o0
F009D8F8: d2040000                 ld      [%l0], %o1
F009D8FC: 10800004                 ba      loc_F009D90C
F009D900: 900a20fc                 and     %o0, 0xFC, %o0
F009D904: d2040000                 ld      [%l0], %o1
F009D908: 912a2002                 sll     %o0, 2, %o0
F009D90C: a2024008                 add     %o1, %o0, %l1
F009D910: d0044000                 ld      [%l1], %o0
F009D914: 900a2003                 and     %o0, 3, %o0
F009D918: 80a22002                 cmp     %o0, 2
F009D91C: 02800009                 be      loc_F009D940
F009D920: 113c045f                 sethi   -0xFEE8400, %o0
F009D924: 90122188                 bset    0x188, %o0! char *
F009D928: d407bff4                 ld      [%fp+var_C], %o2
F009D92C: 7ffddb4b                 call    _printf
F009D930: 92100013                 mov     %l3, %o1
F009D934: 113c045f                 sethi   %hi(aPmapRemoveAllP), %o0! "pmap_remove_all: pte null"
F009D938: 7ffdde0e                 call    _panic
F009D93C: 901221a0                 bset    %lo(aPmapRemoveAllP), %o0! "pmap_remove_all: pte null"
F009D940: d00c200d                 ldub    [%l0+0xD], %o0
F009D944: 80a22003                 cmp     %o0, 3
F009D948: 1280000c                 bne     loc_F009D978
F009D94C: d0044000                 ld      [%l1], %o0
F009D950: d207bff4                 ld      [%fp+var_C], %o1
F009D954: 91322008                 srl     %o0, 8, %o0
F009D958: 912a200c                 sll     %o0, 12, %o0
F009D95C: 920a6fff                 and     %o1, 0xFFF, %o1
F009D960: 90020009                 add     %o0, %o1, %o0
F009D964: 80a20018                 cmp     %o0, %i0
F009D968: 1280000d                 bne     loc_F009D99C
F009D96C: 113c045f                 sethi   -0xFEE8400, %o0
F009D970: 1080000e                 ba      loc_F009D9A8
F009D974: d00c200d                 ldub    [%l0+0xD], %o0
F009D978: 133fff00                 sethi   -0x40000, %o1
F009D97C: d407bff4                 ld      [%fp+var_C], %o2
F009D980: 91322008                 srl     %o0, 8, %o0
F009D984: 912a200c                 sll     %o0, 12, %o0
F009D988: 922a8009                 andn    %o2, %o1, %o1
F009D98C: 90020009                 add     %o0, %o1, %o0
F009D990: 80a20018                 cmp     %o0, %i0
F009D994: 02800004                 be      loc_F009D9A4
F009D998: 113c045f                 sethi   -0xFEE8400, %o0! char *
F009D99C: 7ffdddf5                 call    _panic
F009D9A0: 901221c0                 bset    0x1C0, %o0
F009D9A4: d00c200d                 ldub    [%l0+0xD], %o0
F009D9A8: 80a22003                 cmp     %o0, 3
F009D9AC: 12800009                 bne     loc_F009D9D0
F009D9B0: 80a22002                 cmp     %o0, 2
F009D9B4: d007bff4                 ld      [%fp+var_C], %o0
F009D9B8: 9132200c                 srl     %o0, 12, %o0
F009D9BC: 93322003                 srl     %o0, 3, %o1
F009D9C0: 920a6004                 and     %o1, 4, %o1
F009D9C4: 92024010                 add     %o1, %l0, %o1
F009D9C8: 1080000a                 ba      loc_F009D9F0
F009D9CC: 900a201e                 and     %o0, 0x1E, %o0
F009D9D0: 1280000f                 bne     loc_F009DA0C
F009D9D4: d00fbff4                 ldub    [%fp+var_C], %o0
F009D9D8: d007bff4                 ld      [%fp+var_C], %o0
F009D9DC: 91322012                 srl     %o0, 18, %o0
F009D9E0: 93322003                 srl     %o0, 3, %o1
F009D9E4: 920a6004                 and     %o1, 4, %o1
F009D9E8: 92024010                 add     %o1, %l0, %o1
F009D9EC: 900a201f                 and     %o0, 0x1F, %o0
F009D9F0: d2026010                 ld      [%o1+0x10], %o1
F009D9F4: 912d4008                 sll     %l5, %o0, %o0
F009D9F8: 808a4008                 btst    %o0, %o1
F009D9FC: 3280000e                 bne,a   loc_F009DA34
F009DA00: 113c045f                 sethi   -0xFEE8400, %o0
F009DA04: 1080000f                 ba      loc_F009DA40
F009DA08: d2048000                 ld      [%l2], %o1
F009DA0C: 93322005                 srl     %o0, 5, %o1
F009DA10: 932a6002                 sll     %o1, 2, %o1
F009DA14: 92024010                 add     %o1, %l0, %o1
F009DA18: 900a201f                 and     %o0, 0x1F, %o0
F009DA1C: d2026010                 ld      [%o1+0x10], %o1
F009DA20: 912d4008                 sll     %l5, %o0, %o0
F009DA24: 808a4008                 btst    %o0, %o1
F009DA28: 22800006                 be,a    loc_F009DA40
F009DA2C: d2048000                 ld      [%l2], %o1
F009DA30: 113c045f                 sethi   -0xFEE8400, %o0! char *
F009DA34: 7ffdddcf                 call    _panic
F009DA38: 901221e8                 bset    0x1E8, %o0
F009DA3C: d2048000                 ld      [%l2], %o1
F009DA40: 80a26000                 cmp     %o1, 0
F009DA44: 2280000d                 be,a    loc_F009DA78
F009DA48: c024a004                 clr     [%l2+4]
F009DA4C: d0024000                 ld      [%o1], %o0
F009DA50: d0248000                 st      %o0, [%l2]
F009DA54: d0026004                 ld      [%o1+4], %o0
F009DA58: d024a004                 st      %o0, [%l2+4]
F009DA5C: d4026008                 ld      [%o1+8], %o2
F009DA60: 113c04f7                 sethi   %hi(_pv_entry_zone), %o0
F009DA64: d0022388                 ld      [%o0+%lo(_pv_entry_zone)], %o0
F009DA68: 7fff6dda                 call    _zfree
F009DA6C: d424a008                 st      %o2, [%l2+8]
F009DA70: 10800003                 ba      loc_F009DA7C
F009DA74: 113c04f7                 sethi   -0xFEC2400, %o0
F009DA78: 113c04f7                 sethi   -0xFEC2400, %o0
F009DA7C: d6122270                 lduh    [%o0+0x270], %o3
F009DA80: 9092c000                 orcc    %o3, %g0, %o0
F009DA84: 04800037                 ble     loc_F009DB60
F009DA88: 9602ffff                 inc     -1, %o3
F009DA8C: d407bff4                 ld      [%fp+var_C], %o2
F009DA90: 9332a00c                 srl     %o2, 12, %o1
F009DA94: 91326003                 srl     %o1, 3, %o0
F009DA98: 900a2004                 and     %o0, 4, %o0
F009DA9C: 86020010                 add     %o0, %l0, %g3
F009DAA0: 920a601e                 and     %o1, 0x1E, %o1
F009DAA4: 852d4009                 sll     %l5, %o1, %g2
F009DAA8: 9532a012                 srl     %o2, 18, %o2
F009DAAC: 9132a003                 srl     %o2, 3, %o0
F009DAB0: 900a2004                 and     %o0, 4, %o0
F009DAB4: 9a020010                 add     %o0, %l0, %o5
F009DAB8: 940aa01f                 and     %o2, 0x1F, %o2
F009DABC: d20fbff4                 ldub    [%fp+var_C], %o1
F009DAC0: 992d400a                 sll     %l5, %o2, %o4
F009DAC4: 91326005                 srl     %o1, 5, %o0
F009DAC8: 912a2002                 sll     %o0, 2, %o0
F009DACC: 94020010                 add     %o0, %l0, %o2
F009DAD0: 920a601f                 and     %o1, 0x1F, %o1
F009DAD4: 932d4009                 sll     %l5, %o1, %o1
F009DAD8: d0044000                 ld      [%l1], %o0
F009DADC: 808a2040                 btst    0x40, %o0 ! '@'
F009DAE0: 32800019                 bne,a   loc_F009DB44
F009DAE4: ac102001                 mov     1, %l6
F009DAE8: d00c200d                 ldub    [%l0+0xD], %o0
F009DAEC: 80a22003                 cmp     %o0, 3
F009DAF0: 12800008                 bne     loc_F009DB10
F009DAF4: 80a22002                 cmp     %o0, 2
F009DAF8: d000e018                 ld      [%g3+0x18], %o0
F009DAFC: 808a0002                 btst    %g2, %o0
F009DB00: 32800010                 bne,a   loc_F009DB40
F009DB04: ac102001                 mov     1, %l6
F009DB08: 1080000f                 ba      loc_F009DB44
F009DB0C: d0044000                 ld      [%l1], %o0
F009DB10: 32800008                 bne,a   loc_F009DB30
F009DB14: d002a030                 ld      [%o2+0x30], %o0
F009DB18: d0036018                 ld      [%o5+0x18], %o0
F009DB1C: 808a000c                 btst    %o4, %o0
F009DB20: 32800008                 bne,a   loc_F009DB40
F009DB24: ac102001                 mov     1, %l6
F009DB28: 10800007                 ba      loc_F009DB44
F009DB2C: d0044000                 ld      [%l1], %o0
F009DB30: 808a0009                 btst    %o1, %o0
F009DB34: 22800004                 be,a    loc_F009DB44
F009DB38: d0044000                 ld      [%l1], %o0
F009DB3C: ac102001                 mov     1, %l6
F009DB40: d0044000                 ld      [%l1], %o0
F009DB44: 808a2020                 btst    0x20, %o0 ! ' '
F009DB48: 32800002                 bne,a   loc_F009DB50
F009DB4C: ae102001                 mov     1, %l7
F009DB50: a2046004                 inc     4, %l1
F009DB54: 9092c000                 orcc    %o3, %g0, %o0
F009DB58: 14bfffe0                 bg      loc_F009DAD8
F009DB5C: 9602ffff                 inc     -1, %o3
F009DB60: e027bff0                 st      %l0, [%fp+var_10]
F009DB64: d207bff4                 ld      [%fp+var_C], %o1
F009DB68: 40000e75                 call    _set_invalidpte
F009DB6C: 9007bff0                 add     %fp, var_10, %o0
F009DB70: 80a5a000                 cmp     %l6, 0
F009DB74: 0280000b                 be      loc_F009DBA0
F009DB78: 80a5e000                 cmp     %l7, 0
F009DB7C: 7fffa234                 call    _vm_phys_to_vm_page
F009DB80: 90100018                 mov     %i0, %o0
F009DB84: d202201c                 ld      [%o0+0x1C], %o1
F009DB88: 920a7bff                 and     %o1, -0x401, %o1
F009DB8C: d222201c                 st      %o1, [%o0+0x1C]
F009DB90: d00d2010                 ldub    [%l4+0x10], %o0
F009DB94: 90122001                 bset    1, %o0
F009DB98: d02d2010                 stb     %o0, [%l4+0x10]
F009DB9C: 80a5e000                 cmp     %l7, 0
F009DBA0: 22800006                 be,a    loc_F009DBB8
F009DBA4: d00c200f                 ldub    [%l0+0xF], %o0
F009DBA8: d00d2010                 ldub    [%l4+0x10], %o0
F009DBAC: 90122002                 bset    2, %o0
F009DBB0: d02d2010                 stb     %o0, [%l4+0x10]
F009DBB4: d00c200f                 ldub    [%l0+0xF], %o0
F009DBB8: 80a22000                 cmp     %o0, 0
F009DBBC: 12800005                 bne     loc_F009DBD0
F009DBC0: 90100013                 mov     %l3, %o0
F009DBC4: 40001473                 call    _pmap_dealloc_seg_entry
F009DBC8: 90100010                 mov     %l0, %o0
F009DBCC: 90100013                 mov     %l3, %o0
F009DBD0: 94102001                 mov     1, %o2
F009DBD4: d207bff4                 ld      [%fp+var_C], %o1
F009DBD8: 7ffff93f                 call    _pmap_deallocate_mappings
F009DBDC: 96102000                 mov     0, %o3
F009DBE0: c024e018                 clr     [%l3+0x18]
F009DBE4: e604a004                 ld      [%l2+4], %l3
F009DBE8: 80a4e000                 cmp     %l3, 0
F009DBEC: 12bfff22                 bne     loc_F009D874
F009DBF0: ac102000                 mov     0, %l6
F009DBF4: 7fffe44c                 call    _splx
F009DBF8: 90100019                 mov     %i1, %o0
F009DBFC: 81c7e008                 ret
F009DC00: 81e80000                 restore
