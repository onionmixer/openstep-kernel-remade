F00EBE44: 9de3bf90                 save    %sp, -0x70, %sp
F00EBE48: e4060000                 ld      [%i0], %l2
F00EBE4C: 80a4a000                 cmp     %l2, 0
F00EBE50: 22800055                 be,a    locret_F00EBFA4
F00EBE54: b0102000                 mov     0, %i0
F00EBE58: 293c0506                 sethi   -0xFEBE800, %l4
F00EBE5C: 273c0506                 sethi   -0xFEBE800, %l3
F00EBE60: d0048000                 ld      [%l2], %o0
F00EBE64: d002200c                 ld      [%o0+0xC], %o0
F00EBE68: 80a22002                 cmp     %o0, 2
F00EBE6C: 24800026                 ble,a   loc_F00EBF04
F00EBE70: e404a004                 ld      [%l2+4], %l2
F00EBE74: e204a024                 ld      [%l2+0x24], %l1
F00EBE78: 80a46000                 cmp     %l1, 0
F00EBE7C: 22800022                 be,a    loc_F00EBF04
F00EBE80: e404a004                 ld      [%l2+4], %l2
F00EBE84: 10800012                 ba      loc_F00EBECC
F00EBE88: a0102000                 mov     0, %l0
F00EBE8C: 90020011                 add     %o0, %l1, %o0
F00EBE90: d2022008                 ld      [%o0+8], %o1
F00EBE94: d004a010                 ld      [%l2+0x10], %o0
F00EBE98: 808a2002                 btst    2, %o0
F00EBE9C: 02800004                 be      loc_F00EBEAC
F00EBEA0: 90100009                 mov     %o1, %o0! id
F00EBEA4: 10800003                 ba      loc_F00EBEB0
F00EBEA8: d205221c                 ld      [%l4+0x21C], %o1
F00EBEAC: d204e218                 ld      [%l3+0x218], %o1! SEL
F00EBEB0: 40001670                 call    _objc_msgSend
F00EBEB4: 9410001a                 mov     %i2, %o2
F00EBEB8: 80a22000                 cmp     %o0, 0
F00EBEBC: 02800004                 be      loc_F00EBECC
F00EBEC0: a0042001                 inc     %l0
F00EBEC4: 10800038                 ba      locret_F00EBFA4
F00EBEC8: b0100008                 mov     %o0, %i0
F00EBECC: d0046004                 ld      [%l1+4], %o0
F00EBED0: 80a40008                 cmp     %l0, %o0
F00EBED4: 06bfffee                 bl      loc_F00EBE8C
F00EBED8: 912c2002                 sll     %l0, 2, %o0
F00EBEDC: d0048000                 ld      [%l2], %o0
F00EBEE0: d002200c                 ld      [%o0+0xC], %o0
F00EBEE4: 80a22004                 cmp     %o0, 4
F00EBEE8: 24800007                 ble,a   loc_F00EBF04
F00EBEEC: e404a004                 ld      [%l2+4], %l2
F00EBEF0: e2044000                 ld      [%l1], %l1
F00EBEF4: 80a46000                 cmp     %l1, 0
F00EBEF8: 32bffff5                 bne,a   loc_F00EBECC
F00EBEFC: a0102000                 mov     0, %l0
F00EBF00: e404a004                 ld      [%l2+4], %l2
F00EBF04: 80a4a000                 cmp     %l2, 0
F00EBF08: 32bfffd7                 bne,a   loc_F00EBE64
F00EBF0C: d0048000                 ld      [%l2], %o0
F00EBF10: e4060000                 ld      [%i0], %l2
F00EBF14: 80a4a000                 cmp     %l2, 0
F00EBF18: 02800023                 be      locret_F00EBFA4
F00EBF1C: b0102000                 mov     0, %i0
F00EBF20: d404a01c                 ld      [%l2+0x1C], %o2
F00EBF24: 80a2a000                 cmp     %o2, 0
F00EBF28: 2280001b                 be,a    loc_F00EBF94
F00EBF2C: e404a004                 ld      [%l2+4], %l2
F00EBF30: 92102000                 mov     0, %o1
F00EBF34: d002a004                 ld      [%o2+4], %o0
F00EBF38: 80a24008                 cmp     %o1, %o0
F00EBF3C: 36800012                 bge,a   loc_F00EBF84
F00EBF40: d4028000                 ld      [%o2], %o2
F00EBF44: d602a004                 ld      [%o2+4], %o3
F00EBF48: 912a6001                 sll     %o1, 1, %o0
F00EBF4C: 90020009                 add     %o0, %o1, %o0
F00EBF50: b12a2002                 sll     %o0, 2, %i0
F00EBF54: 90028018                 add     %o2, %i0, %o0
F00EBF58: d0022008                 ld      [%o0+8], %o0
F00EBF5C: 80a2001a                 cmp     %o0, %i2
F00EBF60: 12800005                 bne     loc_F00EBF74
F00EBF64: 92026001                 inc     %o1
F00EBF68: b0062008                 inc     8, %i0
F00EBF6C: 1080000e                 ba      locret_F00EBFA4
F00EBF70: b0028018                 add     %o2, %i0, %i0
F00EBF74: 80a2400b                 cmp     %o1, %o3
F00EBF78: 06bffff5                 bl      loc_F00EBF4C
F00EBF7C: 912a6001                 sll     %o1, 1, %o0
F00EBF80: d4028000                 ld      [%o2], %o2
F00EBF84: 80a2a000                 cmp     %o2, 0
F00EBF88: 32bfffeb                 bne,a   loc_F00EBF34
F00EBF8C: 92102000                 mov     0, %o1
F00EBF90: e404a004                 ld      [%l2+4], %l2
F00EBF94: 80a4a000                 cmp     %l2, 0
F00EBF98: 32bfffe3                 bne,a   loc_F00EBF24
F00EBF9C: d404a01c                 ld      [%l2+0x1C], %o2
F00EBFA0: b0102000                 mov     0, %i0
F00EBFA4: 81c7e008                 ret
F00EBFA8: 81e80000                 restore
