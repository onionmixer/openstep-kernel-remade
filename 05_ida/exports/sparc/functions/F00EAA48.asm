F00EAA48: 9de3bf80                 save    %sp, -0x80, %sp
F00EAA4C: 133c0506                 sethi   %hi(paInsertkeynoreh), %o1
F00EAA50: 90100018                 mov     %i0, %o0! id
F00EAA54: d2026244                 ld      [%o1+%lo(paInsertkeynoreh)], %o1! SEL
F00EAA58: 9410001a                 mov     %i2, %o2
F00EAA5C: 40001b85                 call    _objc_msgSend
F00EAA60: 9610001b                 mov     %i3, %o3
F00EAA64: 80a22000                 cmp     %o0, 0
F00EAA68: 22800004                 be,a    loc_F00EAA78
F00EAA6C: d2062004                 ld      [%i0+4], %o1! SEL
F00EAA70: 10800045                 ba      locret_F00EAB84
F00EAA74: b0100008                 mov     %o0, %i0
F00EAA78: d0062010                 ld      [%i0+0x10], %o0
F00EAA7C: 80a24008                 cmp     %o1, %o0
F00EAA80: 08800040                 bleu    loc_F00EAB80
F00EAA84: 213c0506                 sethi   %hi(paHashtable), %l0
F00EAA88: 233c0506                 sethi   %hi(paAllocfromzone), %l1
F00EAA8C: 253c0506                 sethi   %hi(paZone), %l2
F00EAA90: 90100018                 mov     %i0, %o0! id
F00EAA94: 40001b77                 call    _objc_msgSend
F00EAA98: d204a254                 ld      [%l2+%lo(paZone)], %o1! SEL
F00EAA9C: 94100008                 mov     %o0, %o2
F00EAAA0: d004227c                 ld      [%l0+%lo(paHashtable)], %o0! id
F00EAAA4: 40001b73                 call    _objc_msgSend
F00EAAA8: d2046260                 ld      [%l1+%lo(paAllocfromzone)], %o1
F00EAAAC: 133c0506                 sethi   %hi(paInitbare), %o1
F00EAAB0: d202625c                 ld      [%o1+%lo(paInitbare)], %o1! SEL
F00EAAB4: d4062008                 ld      [%i0+8], %o2
F00EAAB8: d606200c                 ld      [%i0+0xC], %o3
F00EAABC: 40001b6d                 call    _objc_msgSend
F00EAAC0: d8062010                 ld      [%i0+0x10], %o4
F00EAAC4: a0100008                 mov     %o0, %l0
F00EAAC8: d0062004                 ld      [%i0+4], %o0
F00EAACC: d0242004                 st      %o0, [%l0+4]
F00EAAD0: d0062014                 ld      [%i0+0x14], %o0
F00EAAD4: d0242014                 st      %o0, [%l0+0x14]
F00EAAD8: d2062010                 ld      [%i0+0x10], %o1! SEL
F00EAADC: 90026001                 add     %o1, 1, %o0
F00EAAE0: 90020009                 add     %o0, %o1, %o0
F00EAAE4: d0262010                 st      %o0, [%i0+0x10]
F00EAAE8: c0262004                 clr     [%i0+4]
F00EAAEC: 90100018                 mov     %i0, %o0! id
F00EAAF0: 40001b60                 call    _objc_msgSend
F00EAAF4: d204a254                 ld      [%l2+0x254], %o1
F00EAAF8: d2062010                 ld      [%i0+0x10], %o1
F00EAAFC: 4000181f                 call    _NXZoneCalloc
F00EAB00: 94102008                 mov     8, %o2
F00EAB04: d0262014                 st      %o0, [%i0+0x14]
F00EAB08: 133c0504                 sethi   %hi(paInitstate), %o1
F00EAB0C: 9007bfe8                 add     %fp, var_18, %o0
F00EAB10: d023a040                 st      %o0, [%sp+0x80+var_40]
F00EAB14: 90100010                 mov     %l0, %o0! id
F00EAB18: d2026104                 ld      [%o1+%lo(paInitstate)], %o1! SEL
F00EAB1C: 40001b55                 call    _objc_msgSend
F00EAB20: 01000000                 nop
F00EAB24: 00000008                 illtrap
F00EAB28: 253c0504                 sethi   -0xFEBF000, %l2
F00EAB2C: 233c0504                 sethi   -0xFEBF000, %l1
F00EAB30: 90100010                 mov     %l0, %o0! id
F00EAB34: d204a108                 ld      [%l2+0x108], %o1! SEL
F00EAB38: 9407bfe8                 add     %fp, var_18, %o2
F00EAB3C: 9607bfe4                 add     %fp, var_1C, %o3
F00EAB40: 40001b4c                 call    _objc_msgSend
F00EAB44: 9807bfe0                 add     %fp, var_20, %o4
F00EAB48: 912a2018                 sll     %o0, 24, %o0
F00EAB4C: 80a22000                 cmp     %o0, 0
F00EAB50: 02800008                 be      loc_F00EAB70
F00EAB54: 90100018                 mov     %i0, %o0! id
F00EAB58: d2046068                 ld      [%l1+0x68], %o1! SEL
F00EAB5C: d407bfe4                 ld      [%fp+var_1C], %o2
F00EAB60: 40001b44                 call    _objc_msgSend
F00EAB64: d607bfe0                 ld      [%fp+var_20], %o3
F00EAB68: 10bffff3                 ba      loc_F00EAB34
F00EAB6C: 90100010                 mov     %l0, %o0
F00EAB70: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00EAB74: 90100010                 mov     %l0, %o0! id
F00EAB78: 40001b3e                 call    _objc_msgSend
F00EAB7C: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00EAB80: b0102000                 mov     0, %i0
F00EAB84: 81c7e008                 ret
F00EAB88: 81e80000                 restore
