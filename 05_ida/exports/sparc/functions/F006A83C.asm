F006A83C: 9de3bf88                 save    %sp, -0x78, %sp
F006A840: ae100018                 mov     %i0, %l7
F006A844: a6102000                 mov     0, %l3
F006A848: 80a76006                 cmp     %i5, 6
F006A84C: 148000d6                 bg      def_F006A8A4! jumptable F006A8A4 default case, case 3
F006A850: e807a060                 ld      [%fp+arg_60], %l4
F006A854: d006a004                 ld      [%i2+4], %o0
F006A858: 133c04d1                 sethi   %hi(dword_F0134764), %o1
F006A85C: d2026364                 ld      [%o1+%lo(dword_F0134764)], %o1
F006A860: 80a20009                 cmp     %o0, %o1
F006A864: 12800007                 bne     loc_F006A880
F006A868: ba076001                 inc     %i5
F006A86C: 4000bc6e                 call    _check_cpu_subtype
F006A870: d006a008                 ld      [%i2+8], %o0
F006A874: 80a22000                 cmp     %o0, 0
F006A878: 32800004                 bne,a   loc_F006A888
F006A87C: d006a00c                 ld      [%i2+0xC], %o0
F006A880: 108000ca                 ba      locret_F006ABA8
F006A884: b0102001                 mov     1, %i0
F006A888: 92023fff                 add     %o0, -1, %o1
F006A88C: 80a26006                 cmp     %o1, 6! switch 7 cases
F006A890: 188000c5                 bgu     def_F006A8A4! jumptable F006A8A4 default case, case 3
F006A894: 113c01aa                 sethi   %hi(jpt_F006A8A4), %o0
F006A898: 901220ac                 bset    %lo(jpt_F006A8A4), %o0
F006A89C: 932a6002                 sll     %o1, 2, %o1
F006A8A0: d0024008                 ld      [%o1+%o0], %o0
F006A8A4: 81c20000                 jmp     %o0! switch jump
F006A8A8: 01000000                 nop
F006A8C8: 80a76001                 cmp     %i5, 1! jumptable F006A8A4 cases 0,1,4
F006A8CC: 0280000d                 be      loc_F006A900
F006A8D0: 90100017                 mov     %l7, %o0
F006A8D4: 108000b5                 ba      locret_F006ABA8
F006A8D8: b0102004                 mov     4, %i0
F006A8DC: 80a76001                 cmp     %i5, 1! jumptable F006A8A4 cases 2,5
F006A8E0: 12800008                 bne     loc_F006A900
F006A8E4: 90100017                 mov     %l7, %o0
F006A8E8: 108000b0                 ba      locret_F006ABA8
F006A8EC: b0102004                 mov     4, %i0
F006A8F0: 80a76002                 cmp     %i5, 2! jumptable F006A8A4 case 6
F006A8F4: 128000ad                 bne     locret_F006ABA8
F006A8F8: b0102004                 mov     4, %i0
F006A8FC: 90100017                 mov     %l7, %o0
F006A900: 92102000                 mov     0, %o1
F006A904: 4000830e                 call    _vnode_pager_setup
F006A908: 94102001                 mov     1, %o2
F006A90C: d406a014                 ld      [%i2+0x14], %o2
F006A910: 9202a01c                 add     %o2, 0x1C, %o1
F006A914: 80a2401c                 cmp     %o1, %i4
F006A918: 1880001a                 bgu     loc_F006A980
F006A91C: aa100008                 mov     %o0, %l5
F006A920: 113c04d0                 sethi   %hi(_page_mask), %o0
F006A924: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F006A928: 9002601c                 add     %o1, 0x1C, %o0
F006A92C: 90028008                 add     %o2, %o0, %o0
F006A930: acaa0009                 andncc  %o0, %o1, %l6
F006A934: 02800013                 be      loc_F006A980
F006A938: 113c04d1                 sethi   %hi(_kernel_map), %o0
F006A93C: c027bff4                 clr     [%fp+var_C]
F006A940: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006A944: 9207bff4                 add     %fp, var_C, %o1
F006A948: 94100016                 mov     %l6, %o2
F006A94C: 96102001                 mov     1, %o3
F006A950: 98100015                 mov     %l5, %o4
F006A954: 40007f74                 call    _vm_allocate_with_pager
F006A958: 9a10001b                 mov     %i3, %o5
F006A95C: b0920000                 orcc    %o0, %g0, %i0
F006A960: 0280000a                 be      loc_F006A988
F006A964: a0102001                 mov     1, %l0
F006A968: 10800090                 ba      locret_F006ABA8
F006A96C: b0102005                 mov     5, %i0
F006A970: d0022340                 ld      [%o0+0x340], %o0
F006A974: 9210000b                 mov     %o3, %o1
F006A978: 40006a72                 call    _vm_map_remove
F006A97C: 94024016                 add     %o1, %l6, %o2
F006A980: 1080008a                 ba      locret_F006ABA8
F006A984: b0102002                 mov     2, %i0
F006A988: e206a010                 ld      [%i2+0x10], %l1
F006A98C: 10800062                 ba      loc_F006AB14
F006A990: a410201c                 mov     0x1C, %l2
F006A994: d006a014                 ld      [%i2+0x14], %o0
F006A998: 9402c012                 add     %o3, %l2, %o2
F006A99C: d202a004                 ld      [%o2+4], %o1
F006A9A0: 9002201c                 inc     0x1C, %o0
F006A9A4: a4048009                 add     %l2, %o1, %l2
F006A9A8: 80a48008                 cmp     %l2, %o0
F006A9AC: 18bffff1                 bgu     loc_F006A970
F006A9B0: 113c04d1                 sethi   -0xFECBC00, %o0
F006A9B4: d0028000                 ld      [%o2], %o0
F006A9B8: 90023fff                 inc     -1, %o0
F006A9BC: 80a2200d                 cmp     %o0, 0xD! switch 14 cases
F006A9C0: 18800051                 bgu     def_F006A9D4! jumptable F006A9D4 default case, cases 1,2,7-12
F006A9C4: 912a2002                 sll     %o0, 2, %o0
F006A9C8: 053c01aa8410a1dc         set     jpt_F006A9D4, %g2
F006A9D0: d0020002                 ld      [%o0+%g2], %o0
F006A9D4: 81c20000                 jmp     %o0! switch jump
F006A9D8: 01000000                 nop
F006AA14: 80a42001                 cmp     %l0, 1! jumptable F006A9D4 case 0
F006AA18: 1280003d                 bne     loc_F006AB0C
F006AA1C: 80a62000                 cmp     %i0, 0
F006AA20: 9010000a                 mov     %o2, %o0
F006AA24: 92100015                 mov     %l5, %o1
F006AA28: 9410001b                 mov     %i3, %o2
F006AA2C: d805c000                 ld      [%l7], %o4
F006AA30: 9610001c                 mov     %i4, %o3
F006AA34: d8032014                 ld      [%o4+0x14], %o4
F006AA38: 9a100019                 mov     %i1, %o5
F006AA3C: 4000005d                 call    sub_F006ABB0
F006AA40: e823a05c                 st      %l4, [%sp+0x78+var_1C]
F006AA44: 10800031                 ba      loc_F006AB08
F006AA48: b0100008                 mov     %o0, %i0
F006AA4C: 80a42002                 cmp     %l0, 2! jumptable F006A9D4 case 3
F006AA50: 1280002f                 bne     loc_F006AB0C
F006AA54: 80a62000                 cmp     %i0, 0
F006AA58: 9010000a                 mov     %o2, %o0
F006AA5C: 4000012a                 call    sub_F006AF04
F006AA60: 92100014                 mov     %l4, %o1
F006AA64: 10800029                 ba      loc_F006AB08
F006AA68: b0100008                 mov     %o0, %i0
F006AA6C: 80a42002                 cmp     %l0, 2! jumptable F006A9D4 case 4
F006AA70: 12800027                 bne     loc_F006AB0C
F006AA74: 80a62000                 cmp     %i0, 0
F006AA78: 9010000a                 mov     %o2, %o0
F006AA7C: 400000f5                 call    sub_F006AE50
F006AA80: 92100014                 mov     %l4, %o1
F006AA84: 10800021                 ba      loc_F006AB08
F006AA88: b0100008                 mov     %o0, %i0
F006AA8C: 80a42001                 cmp     %l0, 1! jumptable F006A9D4 case 5
F006AA90: 1280001f                 bne     loc_F006AB0C
F006AA94: 80a62000                 cmp     %i0, 0
F006AA98: 9010000a                 mov     %o2, %o0
F006AA9C: 92100019                 mov     %i1, %o1
F006AAA0: 400001a4                 call    sub_F006B130
F006AAA4: 9410001d                 mov     %i5, %o2
F006AAA8: 10800018                 ba      loc_F006AB08
F006AAAC: b0100008                 mov     %o0, %i0
F006AAB0: 80a42001                 cmp     %l0, 1! jumptable F006A9D4 case 6
F006AAB4: 12800016                 bne     loc_F006AB0C
F006AAB8: 80a62000                 cmp     %i0, 0
F006AABC: c407a05c                 ld      [%fp+arg_5C], %g2
F006AAC0: 80a0a000                 cmp     %g2, 0
F006AAC4: 02800011                 be      loc_F006AB08
F006AAC8: d207a05c                 ld      [%fp+arg_5C], %o1
F006AACC: 400001cb                 call    sub_F006B1F8
F006AAD0: 9010000a                 mov     %o2, %o0
F006AAD4: 1080000d                 ba      loc_F006AB08
F006AAD8: b0100008                 mov     %o0, %i0
F006AADC: 80a42002                 cmp     %l0, 2! jumptable F006A9D4 case 13
F006AAE0: 1280000b                 bne     loc_F006AB0C
F006AAE4: 80a62000                 cmp     %i0, 0
F006AAE8: 80a76001                 cmp     %i5, 1
F006AAEC: 02800004                 be      loc_F006AAFC
F006AAF0: 80a4e000                 cmp     %l3, 0
F006AAF4: 32800005                 bne,a   loc_F006AB08
F006AAF8: b0102004                 mov     4, %i0
F006AAFC: 10800003                 ba      loc_F006AB08
F006AB00: a610000a                 mov     %o2, %l3
F006AB04: b0102000                 mov     0, %i0! jumptable F006A9D4 default case, cases 1,2,7-12
F006AB08: 80a62000                 cmp     %i0, 0
F006AB0C: 12800007                 bne     loc_F006AB28
F006AB10: 80a62000                 cmp     %i0, 0
F006AB14: a2047fff                 inc     -1, %l1
F006AB18: 80a47fff                 cmp     %l1, -1
F006AB1C: 12bfff9e                 bne     loc_F006A994
F006AB20: d607bff4                 ld      [%fp+var_C], %o3
F006AB24: 80a62000                 cmp     %i0, 0
F006AB28: 12800007                 bne     loc_F006AB44
F006AB2C: 80a62000                 cmp     %i0, 0
F006AB30: a0042001                 inc     %l0
F006AB34: 80a42002                 cmp     %l0, 2
F006AB38: 24bfff95                 ble,a   loc_F006A98C
F006AB3C: e206a010                 ld      [%i2+0x10], %l1
F006AB40: 80a62000                 cmp     %i0, 0
F006AB44: 1280000b                 bne     loc_F006AB70
F006AB48: d207bff4                 ld      [%fp+var_C], %o1
F006AB4C: 80a4e000                 cmp     %l3, 0
F006AB50: 02800008                 be      loc_F006AB70
F006AB54: 90100013                 mov     %l3, %o0
F006AB58: 92100019                 mov     %i1, %o1
F006AB5C: 9410001d                 mov     %i5, %o2
F006AB60: 400001ab                 call    sub_F006B20C
F006AB64: 96100014                 mov     %l4, %o3
F006AB68: b0100008                 mov     %o0, %i0
F006AB6C: d207bff4                 ld      [%fp+var_C], %o1
F006AB70: 113c04d1                 sethi   %hi(_kernel_map), %o0
F006AB74: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006AB78: 400069f2                 call    _vm_map_remove
F006AB7C: 94024016                 add     %o1, %l6, %o2
F006AB80: 80a62000                 cmp     %i0, 0
F006AB84: 12800009                 bne     locret_F006ABA8
F006AB88: 80a76001                 cmp     %i5, 1
F006AB8C: 12800007                 bne     locret_F006ABA8
F006AB90: 01000000                 nop
F006AB94: d005200c                 ld      [%l4+0xC], %o0
F006AB98: 80a22000                 cmp     %o0, 0
F006AB9C: 12800003                 bne     locret_F006ABA8
F006ABA0: 01000000                 nop
F006ABA4: b0102004                 mov     4, %i0! jumptable F006A8A4 default case, case 3
F006ABA8: 81c7e008                 ret
F006ABAC: 81e80000                 restore
