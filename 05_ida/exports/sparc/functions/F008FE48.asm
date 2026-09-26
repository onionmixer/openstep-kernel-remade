F008FE48: 9de3bf88                 save    %sp, -0x78, %sp
F008FE4C: a2100018                 mov     %i0, %l1
F008FE50: d004601c                 ld      [%l1+0x1C], %o0! id
F008FE54: 133c0504                 sethi   %hi(paLookupresource), %o1
F008FE58: d2026128                 ld      [%o1+%lo(paLookupresource)], %o1! SEL
F008FE5C: 40018685                 call    _objc_msgSend
F008FE60: 9410001a                 mov     %i2, %o2
F008FE64: a0920000                 orcc    %o0, %g0, %l0
F008FE68: 12800008                 bne     loc_F008FE88
F008FE6C: 113c0506                 sethi   -0xFEBE800, %o0
F008FE70: 113c044890122118         set     aSCouldnTLocate_0, %o0! "%s: Couldn't locate resource object\n"
F008FE78: 7ffe11f8                 call    _printf
F008FE7C: 9210001a                 mov     %i2, %o1
F008FE80: 10800039                 ba      locret_F008FF64
F008FE84: b0102000                 mov     0, %i0
F008FE88: d0022288                 ld      [%o0+0x288], %o0! id
F008FE8C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008FE90: 40018678                 call    _objc_msgSend
F008FE94: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008FE98: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008FE9C: 40018675                 call    _objc_msgSend
F008FEA0: d202602c                 ld      [%o1+%lo(paInit)], %o1
F008FEA4: f627bfec                 st      %i3, [%fp+var_14]
F008FEA8: 80a6e000                 cmp     %i3, 0
F008FEAC: 0280002e                 be      locret_F008FF64
F008FEB0: b0100008                 mov     %o0, %i0
F008FEB4: 90100011                 mov     %l1, %o0! id
F008FEB8: 133c0504                 sethi   %hi(paIsshared), %o1
F008FEBC: d2026120                 ld      [%o1+%lo(paIsshared)], %o1! SEL
F008FEC0: 4001866c                 call    _objc_msgSend
F008FEC4: 9410001a                 mov     %i2, %o2
F008FEC8: 912a2018                 sll     %o0, 24, %o0
F008FECC: a33a2018                 sra     %o0, 24, %l1
F008FED0: d007bfec                 ld      [%fp+var_14], %o0
F008FED4: 9207bfec                 add     %fp, var_14, %o1
F008FED8: 7ffffee0                 call    sub_F008FA58
F008FEDC: 9407bfe8                 add     %fp, var_18, %o2
F008FEE0: 80a22000                 cmp     %o0, 0
F008FEE4: 02800020                 be      locret_F008FF64
F008FEE8: 80a46000                 cmp     %l1, 0
F008FEEC: 22800005                 be,a    loc_F008FF00
F008FEF0: 113c0504                 sethi   -0xFEBF000, %o0
F008FEF4: 113c0504                 sethi   %hi(paShareitem), %o0! id
F008FEF8: 10800003                 ba      loc_F008FF04
F008FEFC: d202212c                 ld      [%o0+%lo(paShareitem)], %o1
F008FF00: d2022130                 ld      [%o0+0x130], %o1! SEL
F008FF04: d407bfe8                 ld      [%fp+var_18], %o2
F008FF08: 4001865a                 call    _objc_msgSend
F008FF0C: 90100010                 mov     %l0, %o0! id
F008FF10: 94100008                 mov     %o0, %o2
F008FF14: 133c0504                 sethi   %hi(paAddobject), %o1
F008FF18: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F008FF1C: 40018655                 call    _objc_msgSend
F008FF20: 90100018                 mov     %i0, %o0
F008FF24: 80a22000                 cmp     %o0, 0
F008FF28: 32bfffeb                 bne,a   loc_F008FED4
F008FF2C: d007bfec                 ld      [%fp+var_14], %o0
F008FF30: 113c044890122140         set     aSCouldnTReserv_0, %o0! "%s: Couldn't reserve %d\n"
F008FF38: d407bfe8                 ld      [%fp+var_18], %o2
F008FF3C: 7ffe11c7                 call    _printf
F008FF40: 9210001a                 mov     %i2, %o1
F008FF44: 113c0504                 sethi   %hi(paFreeobjects), %o0! id
F008FF48: d20220cc                 ld      [%o0+%lo(paFreeobjects)], %o1! SEL
F008FF4C: 40018649                 call    _objc_msgSend
F008FF50: 90100018                 mov     %i0, %o0! id
F008FF54: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008FF58: 40018646                 call    _objc_msgSend
F008FF5C: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F008FF60: b0100008                 mov     %o0, %i0
F008FF64: 81c7e008                 ret
F008FF68: 81e80000                 restore
