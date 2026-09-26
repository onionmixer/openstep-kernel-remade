F0087680: 9de3bf98                 save    %sp, -0x68, %sp
F0087684: 113c0447                 sethi   %hi(_vm_object_collapse_allowed), %o0
F0087688: d002207c                 ld      [%o0+%lo(_vm_object_collapse_allowed)], %o0
F008768C: 80a22000                 cmp     %o0, 0
F0087690: 028000c3                 be      locret_F008799C
F0087694: 2b3c04f0                 sethi   -0xFEC4000, %l5
F0087698: 2f3c04f6ac15e030         set     _vm_object_list, %l6
F00876A0: 80a62000                 cmp     %i0, 0
F00876A4: 028000be                 be      locret_F008799C
F00876A8: 01000000                 nop
F00876AC: d0162044                 lduh    [%i0+0x44], %o0
F00876B0: 80a22000                 cmp     %o0, 0
F00876B4: 128000ba                 bne     locret_F008799C
F00876B8: 01000000                 nop
F00876BC: d0062028                 ld      [%i0+0x28], %o0
F00876C0: 80a22000                 cmp     %o0, 0
F00876C4: 128000b6                 bne     locret_F008799C
F00876C8: 01000000                 nop
F00876CC: e2062020                 ld      [%i0+0x20], %l1
F00876D0: 80a46000                 cmp     %l1, 0
F00876D4: 028000b2                 be      locret_F008799C
F00876D8: a0046010                 add     %l1, 0x10, %l0
F00876DC: d0040000                 ld      [%l0], %o0
F00876E0: 80a22000                 cmp     %o0, 0
F00876E4: 12bffffe                 bne     loc_F00876DC
F00876E8: 01000000                 nop
F00876EC: 40003def                 call    _simple_lock_try
F00876F0: 90100010                 mov     %l0, %o0
F00876F4: 80a22000                 cmp     %o0, 0
F00876F8: 02bffff9                 be      loc_F00876DC
F00876FC: 133fffc2                 sethi   -0xF800, %o1
F0087700: d0046044                 ld      [%l1+0x44], %o0
F0087704: 900a0009                 and     %o0, %o1, %o0
F0087708: 80a22800                 cmp     %o0, 0x800
F008770C: 1280000a                 bne     loc_F0087734
F0087710: 01000000                 nop
F0087714: d0046020                 ld      [%l1+0x20], %o0
F0087718: 80a22000                 cmp     %o0, 0
F008771C: 22800008                 be,a    loc_F008773C
F0087720: e6062024                 ld      [%i0+0x24], %l3
F0087724: d002201c                 ld      [%o0+0x1C], %o0
F0087728: 80a22000                 cmp     %o0, 0
F008772C: 22800004                 be,a    loc_F008773C
F0087730: e6062024                 ld      [%i0+0x24], %l3
F0087734: c0246010                 clr     [%l1+0x10]
F0087738: 30800099                 ba,a    locret_F008799C
F008773C: d0546018                 ldsh    [%l1+0x18], %o0
F0087740: 80a22001                 cmp     %o0, 1
F0087744: 1280006e                 bne     loc_F00878FC
F0087748: e8062014                 ld      [%i0+0x14], %l4
F008774C: 1080002c                 ba      loc_F00877FC
F0087750: d0044000                 ld      [%l1], %o0
F0087754: d004a018                 ld      [%l2+0x18], %o0
F0087758: 80a20013                 cmp     %o0, %l3
F008775C: 0a800005                 bcs     loc_F0087770
F0087760: a0220013                 sub     %o0, %l3, %l0
F0087764: 80a40014                 cmp     %l0, %l4
F0087768: 0a80000d                 bcs     loc_F008779C
F008776C: 90100018                 mov     %i0, %o0
F0087770: a0156230                 or      %l5, 0x230, %l0
F0087774: d0040000                 ld      [%l0], %o0
F0087778: 80a22000                 cmp     %o0, 0
F008777C: 12bffffe                 bne     loc_F0087774
F0087780: 01000000                 nop
F0087784: 40003dc9                 call    _simple_lock_try
F0087788: 90100010                 mov     %l0, %o0
F008778C: 80a22000                 cmp     %o0, 0
F0087790: 02bffff9                 be      loc_F0087774
F0087794: 01000000                 nop
F0087798: 30800010                 ba,a    loc_F00877D8
F008779C: 400005ff                 call    _vm_page_lookup
F00877A0: 92100010                 mov     %l0, %o1
F00877A4: 80a22000                 cmp     %o0, 0
F00877A8: 02800011                 be      loc_F00877EC
F00877AC: 90100012                 mov     %l2, %o0
F00877B0: a0156230                 or      %l5, 0x230, %l0
F00877B4: d0040000                 ld      [%l0], %o0
F00877B8: 80a22000                 cmp     %o0, 0
F00877BC: 12bffffe                 bne     loc_F00877B4
F00877C0: 01000000                 nop
F00877C4: 40003db9                 call    _simple_lock_try
F00877C8: 90100010                 mov     %l0, %o0
F00877CC: 80a22000                 cmp     %o0, 0
F00877D0: 02bffff9                 be      loc_F00877B4
F00877D4: 01000000                 nop
F00877D8: 400006e8                 call    _vm_page_free
F00877DC: 90100012                 mov     %l2, %o0
F00877E0: c0256230                 clr     [%l5+0x230]
F00877E4: 10800006                 ba      loc_F00877FC
F00877E8: d0044000                 ld      [%l1], %o0
F00877EC: 92100018                 mov     %i0, %o1
F00877F0: 40000617                 call    _vm_page_rename
F00877F4: 94100010                 mov     %l0, %o2
F00877F8: d0044000                 ld      [%l1], %o0
F00877FC: 80a44008                 cmp     %l1, %o0
F0087800: 32bfffd5                 bne,a   loc_F0087754
F0087804: e4044000                 ld      [%l1], %l2
F0087808: d0046028                 ld      [%l1+0x28], %o0
F008780C: d0262028                 st      %o0, [%i0+0x28]
F0087810: d004602c                 ld      [%l1+0x2C], %o0
F0087814: 90020013                 add     %o0, %l3, %o0
F0087818: d026202c                 st      %o0, [%i0+0x2C]
F008781C: c0246028                 clr     [%l1+0x28]
F0087820: c0246030                 clr     [%l1+0x30]
F0087824: d0046020                 ld      [%l1+0x20], %o0
F0087828: c0246034                 clr     [%l1+0x34]
F008782C: d2062024                 ld      [%i0+0x24], %o1
F0087830: d0262020                 st      %o0, [%i0+0x20]
F0087834: d0046024                 ld      [%l1+0x24], %o0
F0087838: 92024008                 add     %o1, %o0, %o1
F008783C: d0062020                 ld      [%i0+0x20], %o0
F0087840: 80a22000                 cmp     %o0, 0
F0087844: 02800008                 be      loc_F0087864
F0087848: d2262024                 st      %o1, [%i0+0x24]
F008784C: d002201c                 ld      [%o0+0x1C], %o0
F0087850: 80a22000                 cmp     %o0, 0
F0087854: 02800004                 be      loc_F0087864
F0087858: 113c0447                 sethi   %hi(aVmObjectCollap), %o0! "vm_object_collapse: we collapsed a copy"...
F008785C: 7ffe3645                 call    _panic
F0087860: 90122080                 bset    %lo(aVmObjectCollap), %o0! "vm_object_collapse: we collapsed a copy"...
F0087864: c0246010                 clr     [%l1+0x10]
F0087868: 113c04f6a0122038         set     _vm_object_list_lock, %l0
F0087870: d0040000                 ld      [%l0], %o0
F0087874: 80a22000                 cmp     %o0, 0
F0087878: 12bffffe                 bne     loc_F0087870
F008787C: 01000000                 nop
F0087880: 40003d8a                 call    _simple_lock_try
F0087884: 90100010                 mov     %l0, %o0
F0087888: 80a22000                 cmp     %o0, 0
F008788C: 02bffff9                 be      loc_F0087870
F0087890: 01000000                 nop
F0087894: d0046008                 ld      [%l1+8], %o0
F0087898: 80a20016                 cmp     %o0, %l6
F008789C: 12800004                 bne     loc_F00878AC
F00878A0: d204600c                 ld      [%l1+0xC], %o1
F00878A4: 10800003                 ba      loc_F00878B0
F00878A8: d2222004                 st      %o1, [%o0+4]
F00878AC: d222200c                 st      %o1, [%o0+0xC]
F00878B0: 80a24016                 cmp     %o1, %l6
F00878B4: 22800003                 be,a    loc_F00878C0
F00878B8: d025e030                 st      %o0, [%l7+0x30]
F00878BC: d0226008                 st      %o0, [%o1+8]
F00878C0: 113c04f6                 sethi   %hi(_vm_object_list_lock), %o0
F00878C4: c0222038                 clr     [%o0+%lo(_vm_object_list_lock)]
F00878C8: 92100011                 mov     %l1, %o1
F00878CC: 173c04f5                 sethi   %hi(_vm_object_count), %o3
F00878D0: d402e020                 ld      [%o3+%lo(_vm_object_count)], %o2
F00878D4: 113c04f6                 sethi   %hi(_vm_object_zone), %o0
F00878D8: d0022098                 ld      [%o0+%lo(_vm_object_zone)], %o0
F00878DC: 9402bfff                 inc     -1, %o2
F00878E0: 7fffc63c                 call    _zfree
F00878E4: d422e020                 st      %o2, [%o3+%lo(_vm_object_count)]
F00878E8: 133c0446                 sethi   %hi(_object_collapses), %o1
F00878EC: d0026338                 ld      [%o1+%lo(_object_collapses)], %o0
F00878F0: 90022001                 inc     %o0
F00878F4: 10bfff6b                 ba      loc_F00876A0
F00878F8: d0226338                 st      %o0, [%o1+%lo(_object_collapses)]
F00878FC: d0046028                 ld      [%l1+0x28], %o0
F0087900: 80a22000                 cmp     %o0, 0
F0087904: 12bfff8c                 bne     loc_F0087734
F0087908: 01000000                 nop
F008790C: e4044000                 ld      [%l1], %l2
F0087910: 80a44012                 cmp     %l1, %l2
F0087914: 22800013                 be,a    loc_F0087960
F0087918: d0046020                 ld      [%l1+0x20], %o0
F008791C: d004a018                 ld      [%l2+0x18], %o0
F0087920: 80a20013                 cmp     %o0, %l3
F0087924: 0a80000a                 bcs     loc_F008794C
F0087928: a0220013                 sub     %o0, %l3, %l0
F008792C: 80a40014                 cmp     %l0, %l4
F0087930: 18800007                 bgu     loc_F008794C
F0087934: 90100018                 mov     %i0, %o0
F0087938: 40000598                 call    _vm_page_lookup
F008793C: 92100010                 mov     %l0, %o1
F0087940: 80a22000                 cmp     %o0, 0
F0087944: 02bfff7c                 be      loc_F0087734
F0087948: 01000000                 nop
F008794C: e404a008                 ld      [%l2+8], %l2
F0087950: 80a44012                 cmp     %l1, %l2
F0087954: 32bffff3                 bne,a   loc_F0087920
F0087958: d004a018                 ld      [%l2+0x18], %o0
F008795C: d0046020                 ld      [%l1+0x20], %o0
F0087960: 7ffffbc3                 call    _vm_object_reference
F0087964: d0262020                 st      %o0, [%i0+0x20]
F0087968: d0062024                 ld      [%i0+0x24], %o0
F008796C: d2046024                 ld      [%l1+0x24], %o1
F0087970: 153c0446                 sethi   %hi(_object_bypasses), %o2
F0087974: 90020009                 add     %o0, %o1, %o0
F0087978: d0262024                 st      %o0, [%i0+0x24]
F008797C: d202a33c                 ld      [%o2+%lo(_object_bypasses)], %o1
F0087980: c0246010                 clr     [%l1+0x10]
F0087984: d0146018                 lduh    [%l1+0x18], %o0
F0087988: 92026001                 inc     %o1
F008798C: d222a33c                 st      %o1, [%o2+%lo(_object_bypasses)]
F0087990: 90023fff                 inc     -1, %o0
F0087994: 10bfff43                 ba      loc_F00876A0
F0087998: d0346018                 sth     %o0, [%l1+0x18]
F008799C: 81c7e008                 ret
F00879A0: 81e80000                 restore
