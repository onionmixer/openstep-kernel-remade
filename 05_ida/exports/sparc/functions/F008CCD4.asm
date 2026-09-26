F008CCD4: 9de3bf90                 save    %sp, -0x70, %sp
F008CCD8: 113c0504                 sethi   %hi(paIskindof), %o0! id
F008CCDC: d2022040                 ld      [%o0+%lo(paIskindof)], %o1! SEL
F008CCE0: e0062018                 ld      [%i0+0x18], %l0
F008CCE4: d4062010                 ld      [%i0+0x10], %o2
F008CCE8: 400192e2                 call    _objc_msgSend
F008CCEC: 9010001a                 mov     %i2, %o0
F008CCF0: 912a2018                 sll     %o0, 24, %o0
F008CCF4: 80a22000                 cmp     %o0, 0
F008CCF8: 2280001a                 be,a    locret_F008CD60
F008CCFC: b0102000                 mov     0, %i0
F008CD00: d006a008                 ld      [%i2+8], %o0
F008CD04: d206200c                 ld      [%i0+0xC], %o1
F008CD08: 90220009                 sub     %o0, %o1, %o0
F008CD0C: 932a2002                 sll     %o0, 2, %o1
F008CD10: d0040009                 ld      [%l0+%o1], %o0
F008CD14: 80a22000                 cmp     %o0, 0
F008CD18: 32800004                 bne,a   loc_F008CD28
F008CD1C: c0240009                 clr     [%l0+%o1]
F008CD20: 10800010                 ba      locret_F008CD60
F008CD24: b0102000                 mov     0, %i0
F008CD28: d0062014                 ld      [%i0+0x14], %o0
F008CD2C: 90023fff                 inc     -1, %o0
F008CD30: 80a22000                 cmp     %o0, 0
F008CD34: 12800006                 bne     loc_F008CD4C
F008CD38: d0262014                 st      %o0, [%i0+0x14]
F008CD3C: d0062004                 ld      [%i0+4], %o0! id
F008CD40: 133c0504                 sethi   %hi(paResourceinacti), %o1! SEL
F008CD44: 400192cb                 call    _objc_msgSend
F008CD48: d2026044                 ld      [%o1+%lo(paResourceinacti)], %o1
F008CD4C: 113c0504                 sethi   %hi(paDealloc), %o0! id
F008CD50: d2022048                 ld      [%o0+%lo(paDealloc)], %o1! SEL
F008CD54: 400192c7                 call    _objc_msgSend
F008CD58: 9010001a                 mov     %i2, %o0
F008CD5C: b0100008                 mov     %o0, %i0
F008CD60: 81c7e008                 ret
F008CD64: 81e80000                 restore
