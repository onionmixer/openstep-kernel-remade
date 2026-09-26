F00C5A60: 9de3bf88                 save    %sp, -0x78, %sp
F00C5A64: a2102000                 mov     0, %l1
F00C5A68: 273c0504                 sethi   -0xFEBF000, %l3
F00C5A6C: 153c04cc                 sethi   %hi(dword_F013304C), %o2
F00C5A70: d002a04c                 ld      [%o2+%lo(dword_F013304C)], %o0! id
F00C5A74: 133c0504                 sethi   %hi(paLock), %o1
F00C5A78: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C5A7C: 4000af7d                 call    _objc_msgSend
F00C5A80: a410000a                 mov     %o2, %l2
F00C5A84: 90100011                 mov     %l1, %o0
F00C5A88: 7ffffb69                 call    sub_F00C482C
F00C5A8C: 9207bfec                 add     %fp, var_14, %o1
F00C5A90: 80a23d40                 cmp     %o0, -0x2C0
F00C5A94: 2280005c                 be,a    loc_F00C5C04
F00C5A98: 113c04cc                 sethi   -0xFECD000, %o0
F00C5A9C: 34800005                 bg,a    loc_F00C5AB0
F00C5AA0: 113c0504                 sethi   -0xFEBF000, %o0
F00C5AA4: 80a23d29                 cmp     %o0, -0x2D7
F00C5AA8: 02800055                 be      loc_F00C5BFC
F00C5AAC: 113c0504                 sethi   -0xFEBF000, %o0
F00C5AB0: d202233c                 ld      [%o0+0x33C], %o1! SEL
F00C5AB4: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5AB8: 4000af6e                 call    _objc_msgSend
F00C5ABC: d0020000                 ld      [%o0], %o0
F00C5AC0: 80a22001                 cmp     %o0, 1
F00C5AC4: 32bffff0                 bne,a   loc_F00C5A84
F00C5AC8: a2046001                 inc     %l1
F00C5ACC: 113c0504                 sethi   %hi(paRequiredprotoc), %o0
F00C5AD0: d2022204                 ld      [%o0+%lo(paRequiredprotoc)], %o1! SEL
F00C5AD4: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5AD8: 4000af66                 call    _objc_msgSend
F00C5ADC: d0020000                 ld      [%o0], %o0
F00C5AE0: 94920000                 orcc    %o0, %g0, %o2
F00C5AE4: 02800007                 be      loc_F00C5B00
F00C5AE8: 113c0504                 sethi   -0xFEBF000, %o0
F00C5AEC: d0028000                 ld      [%o2], %o0
F00C5AF0: 80a22000                 cmp     %o0, 0
F00C5AF4: 1280000d                 bne     loc_F00C5B28
F00C5AF8: a010000a                 mov     %o2, %l0
F00C5AFC: 113c0504                 sethi   -0xFEBF000, %o0
F00C5B00: d2022008                 ld      [%o0+8], %o1! SEL
F00C5B04: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5B08: 4000af5a                 call    _objc_msgSend
F00C5B0C: d0020000                 ld      [%o0], %o0
F00C5B10: 153c03ea                 sethi   %hi(aLoadedClassSRe), %o2! "Loaded class %s returns nil for +requir"...
F00C5B14: 92100008                 mov     %o0, %o1
F00C5B18: 40000177                 call    _IOLog
F00C5B1C: 9012a1f8                 or      %o2, %lo(aLoadedClassSRe), %o0! "Loaded class %s returns nil for +requir"...
F00C5B20: 10bfffd9                 ba      loc_F00C5A84
F00C5B24: a2046001                 inc     %l1
F00C5B28: d204e018                 ld      [%l3+0x18], %o1! SEL
F00C5B2C: d4040000                 ld      [%l0], %o2
F00C5B30: 4000af50                 call    _objc_msgSend
F00C5B34: 9010001a                 mov     %i2, %o0
F00C5B38: 912a2018                 sll     %o0, 24, %o0
F00C5B3C: 80a22000                 cmp     %o0, 0
F00C5B40: 0280002f                 be      loc_F00C5BFC
F00C5B44: a0042004                 inc     4, %l0
F00C5B48: d0040000                 ld      [%l0], %o0
F00C5B4C: 80a22000                 cmp     %o0, 0
F00C5B50: 12bffff7                 bne     loc_F00C5B2C
F00C5B54: d204e018                 ld      [%l3+0x18], %o1
F00C5B58: d007bfec                 ld      [%fp+var_14], %o0
F00C5B5C: d0022010                 ld      [%o0+0x10], %o0
F00C5B60: 80a22000                 cmp     %o0, 0
F00C5B64: 1280000b                 bne     loc_F00C5B90
F00C5B68: a0100008                 mov     %o0, %l0
F00C5B6C: 113c0506                 sethi   %hi(paIodevicedescri), %o0
F00C5B70: d00222b4                 ld      [%o0+%lo(paIodevicedescri)], %o0! id
F00C5B74: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C5B78: 4000af3e                 call    _objc_msgSend
F00C5B7C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C5B80: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00C5B84: 4000af3b                 call    _objc_msgSend
F00C5B88: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00C5B8C: a0100008                 mov     %o0, %l0
F00C5B90: 90100010                 mov     %l0, %o0! id
F00C5B94: 133c0506                 sethi   %hi(paSetdirectdevic), %o1
F00C5B98: d20261cc                 ld      [%o1+%lo(paSetdirectdevic)], %o1! SEL
F00C5B9C: 4000af35                 call    _objc_msgSend
F00C5BA0: 9410001a                 mov     %i2, %o2
F00C5BA4: d004a04c                 ld      [%l2+0x4C], %o0! id
F00C5BA8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C5BAC: 4000af31                 call    _objc_msgSend
F00C5BB0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C5BB4: 113c0504                 sethi   %hi(paProbe), %o0
F00C5BB8: d2022368                 ld      [%o0+%lo(paProbe)], %o1! SEL
F00C5BBC: d007bfec                 ld      [%fp+var_14], %o0
F00C5BC0: d0020000                 ld      [%o0], %o0! id
F00C5BC4: 4000af2b                 call    _objc_msgSend
F00C5BC8: 94100010                 mov     %l0, %o2
F00C5BCC: 912a2018                 sll     %o0, 24, %o0
F00C5BD0: 80a22000                 cmp     %o0, 0
F00C5BD4: 12800007                 bne     loc_F00C5BF0
F00C5BD8: d004a04c                 ld      [%l2+0x4C], %o0
F00C5BDC: 113c0503                 sethi   %hi(paFree), %o0! id
F00C5BE0: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C5BE4: 4000af23                 call    _objc_msgSend
F00C5BE8: 90100010                 mov     %l0, %o0
F00C5BEC: d004a04c                 ld      [%l2+0x4C], %o0! id
F00C5BF0: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C5BF4: 4000af1f                 call    _objc_msgSend
F00C5BF8: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C5BFC: 10bfffa2                 ba      loc_F00C5A84
F00C5C00: a2046001                 inc     %l1
F00C5C04: d002204c                 ld      [%o0+0x4C], %o0! id
F00C5C08: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C5C0C: 4000af19                 call    _objc_msgSend
F00C5C10: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C5C14: 81c7e008                 ret
F00C5C18: 81e80000                 restore
