F00D4D2C: 9de3bf90                 save    %sp, -0x70, %sp
F00D4D30: d0062110                 ld      [%i0+0x110], %o0! id
F00D4D34: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D4D38: 400072ce                 call    _objc_msgSend
F00D4D3C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D4D40: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4D44: 80a22000                 cmp     %o0, 0
F00D4D48: 0280000b                 be      loc_F00D4D74
F00D4D4C: 113fe03f                 sethi   -0x7F0400, %o0
F00D4D50: d4062168                 ld      [%i0+0x168], %o2
F00D4D54: d202a00c                 ld      [%o2+0xC], %o1
F00D4D58: 90122380                 bset    0x380, %o0
F00D4D5C: 920a4008                 and     %o1, %o0, %o1
F00D4D60: 11001fc09012207f         set     0x7F007F, %o0
F00D4D68: 900e8008                 and     %i2, %o0, %o0
F00D4D6C: 92124008                 bset    %o0, %o1
F00D4D70: d222a00c                 st      %o1, [%o2+0xC]
F00D4D74: d0062110                 ld      [%i0+0x110], %o0! id
F00D4D78: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4D7C: 400072bd                 call    _objc_msgSend
F00D4D80: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D4D84: 81c7e008                 ret
F00D4D88: 81e80000                 restore
