F008EECC: 9de3bf88                 save    %sp, -0x78, %sp
F008EED0: f027bff0                 st      %i0, [%fp+var_10]
F008EED4: 133c0507                 sethi   %hi(stru_F0141CDC.super_class), %o1
F008EED8: d40260e0                 ld      [%o1+%lo(stru_F0141CDC.super_class)], %o2
F008EEDC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008EEE0: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008EEE4: e602602c                 ld      [%o1+%lo(paInit)], %l3
F008EEE8: d427bff4                 st      %o2, [%fp+var_C]
F008EEEC: 40018aa4                 call    _objc_msgSendSuper
F008EEF0: 92100013                 mov     %l3, %o1! SEL
F008EEF4: 113c0506                 sethi   %hi(paHashtable), %o0
F008EEF8: e402227c                 ld      [%o0+%lo(paHashtable)], %l2
F008EEFC: f4262004                 st      %i2, [%i0+4]
F008EF00: 113c0503                 sethi   %hi(paAlloc), %o0
F008EF04: e20223f0                 ld      [%o0+%lo(paAlloc)], %l1
F008EF08: c0262008                 clr     [%i0+8]
F008EF0C: 90100012                 mov     %l2, %o0! id
F008EF10: 40018a58                 call    _objc_msgSend
F008EF14: 92100011                 mov     %l1, %o1
F008EF18: 153c04489412a080         set     asc_F0112080, %o2! "*"
F008EF20: 133c0504                 sethi   %hi(paInitkeydescVal), %o1! SEL
F008EF24: 173c0448                 sethi   %hi(asc_F0112088), %o3! "*"
F008EF28: e00260e4                 ld      [%o1+%lo(paInitkeydescVal)], %l0
F008EF2C: 9612e088                 bset    %lo(asc_F0112088), %o3! "*"
F008EF30: 40018a50                 call    _objc_msgSend
F008EF34: 92100010                 mov     %l0, %o1! SEL
F008EF38: d0262010                 st      %o0, [%i0+0x10]
F008EF3C: 90100012                 mov     %l2, %o0! id
F008EF40: 40018a4c                 call    _objc_msgSend
F008EF44: 92100011                 mov     %l1, %o1
F008EF48: 92100010                 mov     %l0, %o1! SEL
F008EF4C: 153c04489412a090         set     asc_F0112090, %o2! "*"
F008EF54: 173c0448                 sethi   %hi(asc_F0112098), %o3! "@"
F008EF58: 40018a46                 call    _objc_msgSend
F008EF5C: 9612e098                 bset    %lo(asc_F0112098), %o3! "@"
F008EF60: d026200c                 st      %o0, [%i0+0xC]
F008EF64: 113c0506                 sethi   %hi(paList), %o0
F008EF68: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F008EF6C: 40018a41                 call    _objc_msgSend
F008EF70: 92100011                 mov     %l1, %o1! SEL
F008EF74: 40018a3f                 call    _objc_msgSend
F008EF78: 92100013                 mov     %l3, %o1! SEL
F008EF7C: d0262014                 st      %o0, [%i0+0x14]
F008EF80: 113c0504                 sethi   %hi(paValueforstring), %o0
F008EF84: 153c0448                 sethi   %hi(aBusType), %o2! "Bus Type"
F008EF88: e00220e8                 ld      [%o0+%lo(paValueforstring)], %l0
F008EF8C: 9412a0a0                 bset    %lo(aBusType), %o2! "Bus Type"
F008EF90: d0062004                 ld      [%i0+4], %o0! id
F008EF94: 40018a37                 call    _objc_msgSend
F008EF98: 92100010                 mov     %l0, %o1
F008EF9C: a2100008                 mov     %o0, %l1
F008EFA0: 113c0506                 sethi   %hi(paKernbus), %o0
F008EFA4: d0022294                 ld      [%o0+%lo(paKernbus)], %o0! id
F008EFA8: 133c0504                 sethi   %hi(paLookupbusclass), %o1
F008EFAC: d20260ec                 ld      [%o1+%lo(paLookupbusclass)], %o1! SEL
F008EFB0: 40018a30                 call    _objc_msgSend
F008EFB4: 94100011                 mov     %l1, %o2
F008EFB8: d0262018                 st      %o0, [%i0+0x18]
F008EFBC: 92100010                 mov     %l0, %o1! SEL
F008EFC0: 153c0448                 sethi   %hi(aBusId), %o2! "Bus ID"
F008EFC4: d0062004                 ld      [%i0+4], %o0! id
F008EFC8: 40018a2a                 call    _objc_msgSend
F008EFCC: 9412a0b0                 bset    %lo(aBusId), %o2! "Bus ID"
F008EFD0: a0920000                 orcc    %o0, %g0, %l0
F008EFD4: 02800008                 be      loc_F008EFF4
F008EFD8: 92102000                 mov     0, %o1
F008EFDC: 4000029f                 call    sub_F008FA58
F008EFE0: 9407bfec                 add     %fp, var_14, %o2
F008EFE4: 80a22000                 cmp     %o0, 0
F008EFE8: 02800003                 be      loc_F008EFF4
F008EFEC: d007bfec                 ld      [%fp+var_14], %o0
F008EFF0: d0262020                 st      %o0, [%i0+0x20]
F008EFF4: 113c0506                 sethi   %hi(paKernbus), %o0
F008EFF8: d0022294                 ld      [%o0+%lo(paKernbus)], %o0! id
F008EFFC: 133c0504                 sethi   %hi(paLookupbusinsta), %o1
F008F000: d20260f0                 ld      [%o1+%lo(paLookupbusinsta)], %o1! SEL
F008F004: d6062020                 ld      [%i0+0x20], %o3
F008F008: 40018a1a                 call    _objc_msgSend
F008F00C: 94100011                 mov     %l1, %o2
F008F010: 80a42000                 cmp     %l0, 0
F008F014: 02800007                 be      loc_F008F030
F008F018: d026201c                 st      %o0, [%i0+0x1C]
F008F01C: d0062004                 ld      [%i0+4], %o0! id
F008F020: 133c0504                 sethi   %hi(paFreestring), %o1
F008F024: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F008F028: 40018a12                 call    _objc_msgSend
F008F02C: 94100010                 mov     %l0, %o2
F008F030: 80a46000                 cmp     %l1, 0
F008F034: 02800006                 be      locret_F008F04C
F008F038: 133c0504                 sethi   %hi(paFreestring), %o1
F008F03C: d0062004                 ld      [%i0+4], %o0! id
F008F040: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F008F044: 40018a0b                 call    _objc_msgSend
F008F048: 94100011                 mov     %l1, %o2
F008F04C: 81c7e008                 ret
F008F050: 81e80000                 restore
