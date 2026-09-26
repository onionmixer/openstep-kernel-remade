F00CEE8C: 9de3bf90                 save    %sp, -0x70, %sp
F00CEE90: 113c0504                 sethi   %hi(paIsdiskready), %o0! id
F00CEE94: d2022164                 ld      [%o0+%lo(paIsdiskready)], %o1! SEL
F00CEE98: e807a05c                 ld      [%fp+arg_5C], %l4
F00CEE9C: a4100018                 mov     %i0, %l2
F00CEEA0: e607a060                 ld      [%fp+arg_60], %l3
F00CEEA4: 94102001                 mov     1, %o2
F00CEEA8: ea07a064                 ld      [%fp+arg_64], %l5
F00CEEAC: 40008a71                 call    _objc_msgSend
F00CEEB0: 90100012                 mov     %l2, %o0
F00CEEB4: b0100008                 mov     %o0, %i0
F00CEEB8: 80a63bb2                 cmp     %i0, -0x44E
F00CEEBC: 02800006                 be      loc_F00CEED4
F00CEEC0: 80a62000                 cmp     %i0, 0
F00CEEC4: 32800006                 bne,a   loc_F00CEEDC
F00CEEC8: 90100012                 mov     %l2, %o0
F00CEECC: 10800014                 ba      loc_F00CEF1C
F00CEED0: 113c0504                 sethi   -0xFEBF000, %o0! id
F00CEED4: 10800054                 ba      locret_F00CF024
F00CEED8: b0103bb2                 mov     -0x44E, %i0
F00CEEDC: 133c0504                 sethi   %hi(paName), %o1
F00CEEE0: 213c03ea                 sethi   %hi(aSDevicerwcommo), %l0! "%s deviceRwCommon: bogus return from is"...
F00CEEE4: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CEEE8: 40008a62                 call    _objc_msgSend
F00CEEEC: a01423a8                 bset    %lo(aSDevicerwcommo), %l0! "%s deviceRwCommon: bogus return from is"...
F00CEEF0: a2100008                 mov     %o0, %l1
F00CEEF4: 90100012                 mov     %l2, %o0! id
F00CEEF8: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00CEEFC: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00CEF00: 40008a5c                 call    _objc_msgSend
F00CEF04: 94100018                 mov     %i0, %o2
F00CEF08: 94100008                 mov     %o0, %o2
F00CEF0C: 90100010                 mov     %l0, %o0! id
F00CEF10: 7fffdc79                 call    _IOLog
F00CEF14: 92100011                 mov     %l1, %o1
F00CEF18: 30800043                 ba,a    locret_F00CF024
F00CEF1C: d2022178                 ld      [%o0+0x178], %o1! SEL
F00CEF20: 40008a54                 call    _objc_msgSend
F00CEF24: 90100012                 mov     %l2, %o0
F00CEF28: 912a2018                 sll     %o0, 24, %o0
F00CEF2C: 80a22000                 cmp     %o0, 0
F00CEF30: 12800004                 bne     loc_F00CEF40
F00CEF34: 113c0504                 sethi   -0xFEBF000, %o0! id
F00CEF38: 1080003b                 ba      locret_F00CF024
F00CEF3C: b0103bb3                 mov     -0x44D, %i0
F00CEF40: d2022188                 ld      [%o0+0x188], %o1! SEL
F00CEF44: 40008a4b                 call    _objc_msgSend
F00CEF48: 90100012                 mov     %l2, %o0! id
F00CEF4C: 133c0504                 sethi   %hi(paDisksize), %o1
F00CEF50: a2100008                 mov     %o0, %l1
F00CEF54: d20261b0                 ld      [%o1+%lo(paDisksize)], %o1! SEL
F00CEF58: 40008a46                 call    _objc_msgSend
F00CEF5C: 90100012                 mov     %l2, %o0
F00CEF60: a0100008                 mov     %o0, %l0
F00CEF64: 9010001c                 mov     %i4, %o0
F00CEF68: 7ffcde4e                 call    _urem
F00CEF6C: 92100011                 mov     %l1, %o1
F00CEF70: 80a22000                 cmp     %o0, 0
F00CEF74: 1280002c                 bne     locret_F00CF024
F00CEF78: b0103fff                 mov     -1, %i0
F00CEF7C: 9010001c                 mov     %i4, %o0
F00CEF80: 7ffcdda0                 call    _udiv
F00CEF84: 92100011                 mov     %l1, %o1
F00CEF88: a2100008                 mov     %o0, %l1
F00CEF8C: 9006c011                 add     %i3, %l1, %o0
F00CEF90: 80a20010                 cmp     %o0, %l0
F00CEF94: 08800006                 bleu    loc_F00CEFAC
F00CEF98: 80a6c010                 cmp     %i3, %l0
F00CEF9C: 0a800004                 bcs     loc_F00CEFAC
F00CEFA0: a224001b                 sub     %l0, %i3, %l1
F00CEFA4: 10800020                 ba      locret_F00CF024
F00CEFA8: b0103d3e                 mov     -0x2C2, %i0
F00CEFAC: 90100012                 mov     %l2, %o0! id
F00CEFB0: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CEFB4: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CEFB8: 40008a2e                 call    _objc_msgSend
F00CEFBC: 94100013                 mov     %l3, %o2
F00CEFC0: a0100008                 mov     %o0, %l0
F00CEFC4: f4240000                 st      %i2, [%l0]
F00CEFC8: f6242004                 st      %i3, [%l0+4]
F00CEFCC: e2242008                 st      %l1, [%l0+8]
F00CEFD0: fa24200c                 st      %i5, [%l0+0xC]
F00CEFD4: e8242010                 st      %l4, [%l0+0x10]
F00CEFD8: 90100012                 mov     %l2, %o0! id
F00CEFDC: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CEFE0: 94100010                 mov     %l0, %o2
F00CEFE4: d6042020                 ld      [%l0+0x20], %o3
F00CEFE8: 19200000                 sethi   0x80000000, %o4
F00CEFEC: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CEFF0: 9612c00c                 bset    %o4, %o3
F00CEFF4: 40008a1f                 call    _objc_msgSend
F00CEFF8: d6242020                 st      %o3, [%l0+0x20]
F00CEFFC: 80a4e000                 cmp     %l3, 0
F00CF000: 12800009                 bne     locret_F00CF024
F00CF004: b0100008                 mov     %o0, %i0
F00CF008: 90100012                 mov     %l2, %o0! id
F00CF00C: 94100010                 mov     %l0, %o2
F00CF010: d602a024                 ld      [%o2+0x24], %o3
F00CF014: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CF018: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CF01C: 40008a15                 call    _objc_msgSend
F00CF020: d6254000                 st      %o3, [%l5]
F00CF024: 81c7e008                 ret
F00CF028: 81e80000                 restore
