F004EDFC: 9de3bf98                 save    %sp, -0x68, %sp
F004EE00: ac100018                 mov     %i0, %l6
F004EE04: b0102000                 mov     0, %i0
F004EE08: ae102001                 mov     1, %l7
F004EE0C: a2102000                 mov     0, %l1
F004EE10: 80a6001b                 cmp     %i0, %i3
F004EE14: 16800009                 bge     loc_F004EE38
F004EE18: e605a050                 ld      [%l6+0x50], %l3
F004EE1C: 90100017                 mov     %l7, %o0
F004EE20: d204e074                 ld      [%l3+0x74], %o1! int
F004EE24: 7ffeddb7                 call    _umul
F004EE28: a2046001                 inc     %l1
F004EE2C: 80a4401b                 cmp     %l1, %i3
F004EE30: 06bffffb                 bl      loc_F004EE1C
F004EE34: ae100008                 mov     %o0, %l7
F004EE38: a4968000                 orcc    %i2, %g0, %l2
F004EE3C: 24800007                 ble,a   loc_F004EE58
F004EE40: d005a028                 ld      [%l6+0x28], %o0
F004EE44: 90100012                 mov     %l2, %o0! int
F004EE48: 7ffeddf0                 call    _div
F004EE4C: 92100017                 mov     %l7, %o1
F004EE50: a4100008                 mov     %o0, %l2
F004EE54: d005a028                 ld      [%l6+0x28], %o0
F004EE58: d2022080                 ld      [%o0+0x80], %o1
F004EE5C: 9fc24000                 call    %o1
F004EE60: 9005a00c                 add     %l6, 0xC, %o0! int
F004EE64: e004e030                 ld      [%l3+0x30], %l0
F004EE68: 92100008                 mov     %o0, %o1! int
F004EE6C: 7ffedde7                 call    _div
F004EE70: 90100010                 mov     %l0, %o0
F004EE74: b8100008                 mov     %o0, %i4
F004EE78: 7fff5774                 call    _geteblk
F004EE7C: 90100010                 mov     %l0, %o0
F004EE80: a0100008                 mov     %o0, %l0
F004EE84: d005a040                 ld      [%l6+0x40], %o0
F004EE88: d204e064                 ld      [%l3+0x64], %o1
F004EE8C: d404e030                 ld      [%l3+0x30], %o2
F004EE90: 7fff55a4                 call    _bread
F004EE94: 932e4009                 sll     %i1, %o1, %o1
F004EE98: a8100008                 mov     %o0, %l4
F004EE9C: d0050000                 ld      [%l4], %o0
F004EEA0: 808a2004                 btst    4, %o0
F004EEA4: 22800008                 be,a    loc_F004EEC4
F004EEA8: ea052020                 ld      [%l4+0x20], %l5
F004EEAC: 7fff566f                 call    _brelse
F004EEB0: 90100010                 mov     %l0, %o0
F004EEB4: 7fff566d                 call    _brelse
F004EEB8: 90100014                 mov     %l4, %o0! void *
F004EEBC: 10800040                 ba      locret_F004EFBC
F004EEC0: b0102000                 mov     0, %i0
F004EEC4: d2042020                 ld      [%l0+0x20], %o1! void *
F004EEC8: d404e030                 ld      [%l3+0x30], %o2! size_t
F004EECC: 40011711                 call    _bcopy
F004EED0: 90100015                 mov     %l5, %o0
F004EED4: 912ca002                 sll     %l2, 2, %o0
F004EED8: 90022004                 inc     4, %o0
F004EEDC: d204e074                 ld      [%l3+0x74], %o1
F004EEE0: 90054008                 add     %l5, %o0, %o0! void *
F004EEE4: 92027fff                 inc     -1, %o1
F004EEE8: 92224012                 sub     %o1, %l2, %o1! size_t
F004EEEC: 400117db                 call    _bzero
F004EEF0: 932a6002                 sll     %o1, 2, %o1
F004EEF4: 7fff561d                 call    _bwrite
F004EEF8: 90100014                 mov     %l4, %o0
F004EEFC: d004e074                 ld      [%l3+0x74], %o0
F004EF00: a8100010                 mov     %l0, %l4
F004EF04: a2023fff                 add     %o0, -1, %l1
F004EF08: 80a44012                 cmp     %l1, %l2
F004EF0C: 04800018                 ble     loc_F004EF6C
F004EF10: ea052020                 ld      [%l4+0x20], %l5
F004EF14: b32c6002                 sll     %l1, 2, %i1
F004EF18: e0064015                 ld      [%i1+%l5], %l0
F004EF1C: 80a42000                 cmp     %l0, 0
F004EF20: 22800010                 be,a    loc_F004EF60
F004EF24: a2047fff                 inc     -1, %l1
F004EF28: 80a6e000                 cmp     %i3, 0
F004EF2C: 04800007                 ble     loc_F004EF48
F004EF30: 90100016                 mov     %l6, %o0
F004EF34: 92100010                 mov     %l0, %o1
F004EF38: 94103fff                 mov     -1, %o2
F004EF3C: 7fffffb0                 call    _indirtrunc
F004EF40: 9606ffff                 add     %i3, -1, %o3
F004EF44: b0060008                 add     %i0, %o0, %i0
F004EF48: 90100016                 mov     %l6, %o0
F004EF4C: 92100010                 mov     %l0, %o1
F004EF50: d404e030                 ld      [%l3+0x30], %o2
F004EF54: 7fffec89                 call    _free_block
F004EF58: b006001c                 add     %i0, %i4, %i0
F004EF5C: a2047fff                 inc     -1, %l1
F004EF60: 80a44012                 cmp     %l1, %l2
F004EF64: 14bfffed                 bg      loc_F004EF18
F004EF68: b2067ffc                 inc     -4, %i1
F004EF6C: 80a6e000                 cmp     %i3, 0
F004EF70: 04800011                 ble     loc_F004EFB4
F004EF74: 80a6a000                 cmp     %i2, 0
F004EF78: 0680000f                 bl      loc_F004EFB4
F004EF7C: 9010001a                 mov     %i2, %o0
F004EF80: 7ffede4a                 call    _rem
F004EF84: 92100017                 mov     %l7, %o1
F004EF88: 932c6002                 sll     %l1, 2, %o1
F004EF8C: e0054009                 ld      [%l5+%o1], %l0
F004EF90: 80a42000                 cmp     %l0, 0
F004EF94: 02800008                 be      loc_F004EFB4
F004EF98: a4100008                 mov     %o0, %l2
F004EF9C: 90100016                 mov     %l6, %o0
F004EFA0: 92100010                 mov     %l0, %o1
F004EFA4: 94100012                 mov     %l2, %o2
F004EFA8: 7fffff95                 call    _indirtrunc
F004EFAC: 9606ffff                 add     %i3, -1, %o3
F004EFB0: b0060008                 add     %i0, %o0, %i0
F004EFB4: 7fff562d                 call    _brelse
F004EFB8: 90100014                 mov     %l4, %o0
F004EFBC: 81c7e008                 ret
F004EFC0: 81e80000                 restore
