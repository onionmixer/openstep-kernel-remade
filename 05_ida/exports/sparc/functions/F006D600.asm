F006D600: 9de3bf98                 save    %sp, -0x68, %sp
F006D604: d2062038                 ld      [%i0+0x38], %o1
F006D608: 11100000                 sethi   0x40000000, %o0
F006D60C: 808a4008                 btst    %o0, %o1
F006D610: 028000b4                 be      locret_F006D8E0
F006D614: 902a4008                 andn    %o1, %o0, %o0
F006D618: e6062010                 ld      [%i0+0x10], %l3
F006D61C: e2062024                 ld      [%i0+0x24], %l1
F006D620: d0262038                 st      %o0, [%i0+0x38]
F006D624: 80a46000                 cmp     %l1, 0
F006D628: 028000ae                 be      locret_F006D8E0
F006D62C: f006200c                 ld      [%i0+0xC], %i0
F006D630: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F006D638: d0040000                 ld      [%l0], %o0
F006D63C: 80a22000                 cmp     %o0, 0
F006D640: 12bffffe                 bne     loc_F006D638
F006D644: 01000000                 nop
F006D648: 4000a618                 call    _simple_lock_try
F006D64C: 90100010                 mov     %l0, %o0
F006D650: 80a22000                 cmp     %o0, 0
F006D654: 02bffff9                 be      loc_F006D638
F006D658: 01000000                 nop
F006D65C: a0046010                 add     %l1, 0x10, %l0
F006D660: d0040000                 ld      [%l0], %o0
F006D664: 80a22000                 cmp     %o0, 0
F006D668: 12bffffe                 bne     loc_F006D660
F006D66C: 01000000                 nop
F006D670: 4000a60e                 call    _simple_lock_try
F006D674: 90100010                 mov     %l0, %o0
F006D678: 80a22000                 cmp     %o0, 0
F006D67C: 02bffff9                 be      loc_F006D660
F006D680: 113c04d0                 sethi   %hi(_page_mask), %o0
F006D684: d40220d8                 ld      [%o0+%lo(_page_mask)], %o2
F006D688: 90060013                 add     %i0, %l3, %o0
F006D68C: 9238000a                 xnor    %g0, %o2, %o1
F006D690: a60cc009                 and     %l3, %o1, %l3
F006D694: 9002000a                 add     %o0, %o2, %o0
F006D698: aa0a0009                 and     %o0, %o1, %l5
F006D69C: 80a4c015                 cmp     %l3, %l5
F006D6A0: 1a80008d                 bcc     loc_F006D8D4
F006D6A4: 113fffdf                 sethi   -0x8400, %o0
F006D6A8: 35200000                 sethi   0x80000000, %i2
F006D6AC: 33100000                 sethi   0x40000000, %i1
F006D6B0: 293c04f0                 sethi   -0xFEC4000, %l4
F006D6B4: 373c04f0ac16e228         set     _vm_page_queue_inactive, %l6
F006D6BC: b81223ff                 or      %o0, 0x3FF, %i4
F006D6C0: 111fffffae1223ff         set     0x7FFFFFFF, %l7
F006D6C8: 90100011                 mov     %l1, %o0
F006D6CC: 40006e33                 call    _vm_page_lookup
F006D6D0: 92100013                 mov     %l3, %o1
F006D6D4: a0920000                 orcc    %o0, %g0, %l0
F006D6D8: 0280007a                 be      loc_F006D8C0
F006D6DC: 113c0447                 sethi   -0xFEEE400, %o0
F006D6E0: d2042020                 ld      [%l0+0x20], %o1
F006D6E4: 91326014                 srl     %o1, 20, %o0
F006D6E8: 808a2001                 btst    1, %o0
F006D6EC: 32800075                 bne,a   loc_F006D8C0
F006D6F0: 113c0447                 sethi   -0xFEEE400, %o0
F006D6F4: 808a401a                 btst    %i2, %o1
F006D6F8: 0280001f                 be      loc_F006D774
F006D6FC: 90124019                 or      %o1, %i1, %o0
F006D700: d0242020                 st      %o0, [%l0+0x20]
F006D704: 90100010                 mov     %l0, %o0
F006D708: 40000d73                 call    _assert_wait
F006D70C: 92102000                 mov     0, %o1
F006D710: c0246010                 clr     [%l1+0x10]
F006D714: c0252230                 clr     [%l4+0x230]
F006D718: 400013ea                 call    _thread_block
F006D71C: a0152230                 or      %l4, 0x230, %l0
F006D720: d0040000                 ld      [%l0], %o0
F006D724: 80a22000                 cmp     %o0, 0
F006D728: 12bffffe                 bne     loc_F006D720
F006D72C: 01000000                 nop
F006D730: 4000a5de                 call    _simple_lock_try
F006D734: 90100010                 mov     %l0, %o0
F006D738: 80a22000                 cmp     %o0, 0
F006D73C: 02bffff9                 be      loc_F006D720
F006D740: b0046010                 add     %l1, 0x10, %i0
F006D744: d0060000                 ld      [%i0], %o0
F006D748: 80a22000                 cmp     %o0, 0
F006D74C: 12bffffe                 bne     loc_F006D744
F006D750: 01000000                 nop
F006D754: 4000a5d5                 call    _simple_lock_try
F006D758: 90100018                 mov     %i0, %o0
F006D75C: 80a22000                 cmp     %o0, 0
F006D760: 02bffff9                 be      loc_F006D744
F006D764: 80a4c015                 cmp     %l3, %l5
F006D768: 30800059                 ba,a    loc_F006D8CC
F006D76C: 10800011                 ba      loc_F006D7B0
F006D770: d026e228                 st      %o0, [%i3+0x228]
F006D774: d204201c                 ld      [%l0+0x1C], %o1
F006D778: 11000010                 sethi   0x4000, %o0
F006D77C: 808a4008                 btst    %o0, %o1
F006D780: 12800004                 bne     loc_F006D790
F006D784: 01000000                 nop
F006D788: 40007017                 call    _vm_page_activate
F006D78C: 90100010                 mov     %l0, %o0
F006D790: 40006fd3                 call    _vm_page_deactivate
F006D794: 90100010                 mov     %l0, %o0
F006D798: d0040000                 ld      [%l0], %o0
F006D79C: d2042004                 ld      [%l0+4], %o1
F006D7A0: 80a24016                 cmp     %o1, %l6
F006D7A4: 02bffff2                 be      loc_F006D76C
F006D7A8: d2222004                 st      %o1, [%o0+4]
F006D7AC: d0224000                 st      %o0, [%o1]
F006D7B0: d004201c                 ld      [%l0+0x1C], %o0
F006D7B4: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F006D7B8: d202a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o1
F006D7BC: 900a001c                 and     %o0, %i4, %o0
F006D7C0: d024201c                 st      %o0, [%l0+0x1C]
F006D7C4: 92027fff                 inc     -1, %o1
F006D7C8: d0042020                 ld      [%l0+0x20], %o0
F006D7CC: d222a220                 st      %o1, [%o2+%lo(_vm_page_inactive_count)]
F006D7D0: d204201c                 ld      [%l0+0x1C], %o1
F006D7D4: 9012001a                 bset    %i2, %o0
F006D7D8: d0242020                 st      %o0, [%l0+0x20]
F006D7DC: 11000008                 sethi   0x2000, %o0
F006D7E0: 808a4008                 btst    %o0, %o1
F006D7E4: 02800028                 be      loc_F006D884
F006D7E8: 01000000                 nop
F006D7EC: d0042024                 ld      [%l0+0x24], %o0
F006D7F0: 4000c002                 call    _pmap_remove_all
F006D7F4: b0152230                 or      %l4, 0x230, %i0
F006D7F8: c0246010                 clr     [%l1+0x10]
F006D7FC: d2146044                 lduh    [%l1+0x44], %o1
F006D800: 92026001                 inc     %o1
F006D804: d2346044                 sth     %o1, [%l1+0x44]
F006D808: c0252230                 clr     [%l4+0x230]
F006D80C: 400077b1                 call    _vnode_pageout
F006D810: 90100010                 mov     %l0, %o0
F006D814: a4100008                 mov     %o0, %l2
F006D818: d0060000                 ld      [%i0], %o0
F006D81C: 80a22000                 cmp     %o0, 0
F006D820: 12bffffe                 bne     loc_F006D818
F006D824: 01000000                 nop
F006D828: 4000a5a0                 call    _simple_lock_try
F006D82C: 90100018                 mov     %i0, %o0
F006D830: 80a22000                 cmp     %o0, 0
F006D834: 02bffff9                 be      loc_F006D818
F006D838: 01000000                 nop
F006D83C: b0046010                 add     %l1, 0x10, %i0
F006D840: d0060000                 ld      [%i0], %o0
F006D844: 80a22000                 cmp     %o0, 0
F006D848: 12bffffe                 bne     loc_F006D840
F006D84C: 01000000                 nop
F006D850: 4000a596                 call    _simple_lock_try
F006D854: 90100018                 mov     %i0, %o0
F006D858: 80a22000                 cmp     %o0, 0
F006D85C: 02bffff9                 be      loc_F006D840
F006D860: 80a4a000                 cmp     %l2, 0
F006D864: d0146044                 lduh    [%l1+0x44], %o0
F006D868: 90023fff                 inc     -1, %o0
F006D86C: 12800006                 bne     loc_F006D884
F006D870: d0346044                 sth     %o0, [%l1+0x44]
F006D874: d204201c                 ld      [%l0+0x1C], %o1
F006D878: 11000008                 sethi   0x2000, %o0
F006D87C: 902a4008                 andn    %o1, %o0, %o0
F006D880: d024201c                 st      %o0, [%l0+0x1C]
F006D884: 40006fd8                 call    _vm_page_activate
F006D888: 90100010                 mov     %l0, %o0
F006D88C: d0042020                 ld      [%l0+0x20], %o0
F006D890: 920a0017                 and     %o0, %l7, %o1
F006D894: 808a4019                 btst    %i1, %o1
F006D898: 02800009                 be      loc_F006D8BC
F006D89C: d2242020                 st      %o1, [%l0+0x20]
F006D8A0: 11100000                 sethi   0x40000000, %o0
F006D8A4: 902a4008                 andn    %o1, %o0, %o0
F006D8A8: d0242020                 st      %o0, [%l0+0x20]
F006D8AC: 90100010                 mov     %l0, %o0
F006D8B0: 92102000                 mov     0, %o1
F006D8B4: 40000dd2                 call    _thread_wakeup_prim
F006D8B8: 94102000                 mov     0, %o2
F006D8BC: 113c0447                 sethi   -0xFEEE400, %o0
F006D8C0: d002213c                 ld      [%o0+0x13C], %o0
F006D8C4: a604c008                 add     %l3, %o0, %l3
F006D8C8: 80a4c015                 cmp     %l3, %l5
F006D8CC: 0abfff80                 bcs     loc_F006D6CC
F006D8D0: 90100011                 mov     %l1, %o0
F006D8D4: c0246010                 clr     [%l1+0x10]
F006D8D8: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F006D8DC: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F006D8E0: 81c7e008                 ret
F006D8E4: 81e80000                 restore
