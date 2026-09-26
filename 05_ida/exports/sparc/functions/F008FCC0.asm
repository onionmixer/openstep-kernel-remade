F008FCC0: 9de3bf68                 save    %sp, -0x98, %sp
F008FCC4: a2100018                 mov     %i0, %l1
F008FCC8: d004601c                 ld      [%l1+0x1C], %o0! id
F008FCCC: 133c0504                 sethi   %hi(paLookupresource), %o1
F008FCD0: d2026128                 ld      [%o1+%lo(paLookupresource)], %o1! SEL
F008FCD4: 400186e7                 call    _objc_msgSend
F008FCD8: 9410001a                 mov     %i2, %o2
F008FCDC: a0920000                 orcc    %o0, %g0, %l0
F008FCE0: 12800008                 bne     loc_F008FD00
F008FCE4: 113c0506                 sethi   -0xFEBE800, %o0
F008FCE8: 113c0448901220c8         set     aSCouldnTLocate, %o0! "%s: Couldn't locate resource object\n"
F008FCF0: 7ffe125a                 call    _printf
F008FCF4: 9210001a                 mov     %i2, %o1
F008FCF8: 10800052                 ba      locret_F008FE40
F008FCFC: b0102000                 mov     0, %i0
F008FD00: d0022288                 ld      [%o0+0x288], %o0! id
F008FD04: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008FD08: 400186da                 call    _objc_msgSend
F008FD0C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008FD10: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008FD14: 400186d7                 call    _objc_msgSend
F008FD18: d202602c                 ld      [%o1+%lo(paInit)], %o1
F008FD1C: f627bfec                 st      %i3, [%fp+var_14]
F008FD20: 80a6e000                 cmp     %i3, 0
F008FD24: 02800047                 be      locret_F008FE40
F008FD28: b0100008                 mov     %o0, %i0
F008FD2C: 90100011                 mov     %l1, %o0! id
F008FD30: 133c0504                 sethi   %hi(paIsshared), %o1
F008FD34: d2026120                 ld      [%o1+%lo(paIsshared)], %o1! SEL
F008FD38: 400186ce                 call    _objc_msgSend
F008FD3C: 9410001a                 mov     %i2, %o2
F008FD40: b607bfec                 add     %fp, var_14, %i3
F008FD44: 912a2018                 sll     %o0, 24, %o0
F008FD48: a33a2018                 sra     %o0, 24, %l1
F008FD4C: d007bfec                 ld      [%fp+var_14], %o0
F008FD50: 9210001b                 mov     %i3, %o1
F008FD54: 7fffff41                 call    sub_F008FA58
F008FD58: 9407bfe8                 add     %fp, var_18, %o2
F008FD5C: 80a22000                 cmp     %o0, 0
F008FD60: 02800038                 be      locret_F008FE40
F008FD64: 9210001b                 mov     %i3, %o1
F008FD68: d007bfec                 ld      [%fp+var_14], %o0
F008FD6C: 9407bfe4                 add     %fp, var_1C, %o2
F008FD70: 90022001                 inc     %o0
F008FD74: 7fffff39                 call    sub_F008FA58
F008FD78: d027bfec                 st      %o0, [%fp+var_14]
F008FD7C: 80a22000                 cmp     %o0, 0
F008FD80: 02800030                 be      locret_F008FE40
F008FD84: d207bfe8                 ld      [%fp+var_18], %o1
F008FD88: 80a46000                 cmp     %l1, 0
F008FD8C: d007bfe4                 ld      [%fp+var_1C], %o0
F008FD90: d227bfd0                 st      %o1, [%fp+var_30]
F008FD94: 90220009                 sub     %o0, %o1, %o0
F008FD98: 90022001                 inc     %o0
F008FD9C: d027bfd4                 st      %o0, [%fp+var_2C]
F008FDA0: d227bfd8                 st      %o1, [%fp+var_28]
F008FDA4: 02800009                 be      loc_F008FDC8
F008FDA8: d027bfdc                 st      %o0, [%fp+var_24]
F008FDAC: d227bfd0                 st      %o1, [%fp+var_30]
F008FDB0: d027bfd4                 st      %o0, [%fp+var_2C]
F008FDB4: 90100010                 mov     %l0, %o0
F008FDB8: 133c0504                 sethi   %hi(paSharerange), %o1
F008FDBC: d2026134                 ld      [%o1+%lo(paSharerange)], %o1
F008FDC0: 10800008                 ba      loc_F008FDE0
F008FDC4: 9407bfd0                 add     %fp, var_30, %o2
F008FDC8: d227bfc8                 st      %o1, [%fp+var_38]
F008FDCC: d027bfcc                 st      %o0, [%fp+var_34]
F008FDD0: 90100010                 mov     %l0, %o0! id
F008FDD4: 133c0504                 sethi   %hi(paReserverange), %o1
F008FDD8: d2026138                 ld      [%o1+%lo(paReserverange)], %o1! SEL
F008FDDC: 9407bfc8                 add     %fp, var_38, %o2
F008FDE0: 400186a4                 call    _objc_msgSend
F008FDE4: 01000000                 nop
F008FDE8: 94100008                 mov     %o0, %o2
F008FDEC: 133c0504                 sethi   %hi(paAddobject), %o1
F008FDF0: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F008FDF4: 4001869f                 call    _objc_msgSend
F008FDF8: 90100018                 mov     %i0, %o0
F008FDFC: 80a22000                 cmp     %o0, 0
F008FE00: 32bfffd4                 bne,a   loc_F008FD50
F008FE04: d007bfec                 ld      [%fp+var_14], %o0
F008FE08: 113c0448                 sethi   %hi(aSCouldnTReserv), %o0! "%s: Couldn't reserve range %08x-%08x\n"
F008FE0C: d407bfe8                 ld      [%fp+var_18], %o2
F008FE10: 901220f0                 bset    %lo(aSCouldnTReserv), %o0! "%s: Couldn't reserve range %08x-%08x\n"
F008FE14: d607bfe4                 ld      [%fp+var_1C], %o3
F008FE18: 7ffe1210                 call    _printf
F008FE1C: 9210001a                 mov     %i2, %o1
F008FE20: 113c0504                 sethi   %hi(paFreeobjects), %o0! id
F008FE24: d20220cc                 ld      [%o0+%lo(paFreeobjects)], %o1! SEL
F008FE28: 40018692                 call    _objc_msgSend
F008FE2C: 90100018                 mov     %i0, %o0! id
F008FE30: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008FE34: 4001868f                 call    _objc_msgSend
F008FE38: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F008FE3C: b0100008                 mov     %o0, %i0
F008FE40: 81c7e008                 ret
F008FE44: 81e80000                 restore
