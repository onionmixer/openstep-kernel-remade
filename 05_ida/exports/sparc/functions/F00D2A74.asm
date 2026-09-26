F00D2A74: 9de3bf88                 save    %sp, -0x78, %sp
F00D2A78: d0062114                 ld      [%i0+0x114], %o0
F00D2A7C: 80a68008                 cmp     %i2, %o0
F00D2A80: 32800051                 bne,a   locret_F00D2BC4
F00D2A84: b0103d3f                 mov     -0x2C1, %i0
F00D2A88: d04e21d0                 ldsb    [%i0+0x1D0], %o0
F00D2A8C: 80a22000                 cmp     %o0, 0
F00D2A90: 12800004                 bne     loc_F00D2AA0
F00D2A94: 80a6e000                 cmp     %i3, 0
F00D2A98: 1080004b                 ba      locret_F00D2BC4
F00D2A9C: b0103d3f                 mov     -0x2C1, %i0
F00D2AA0: 0280000c                 be      loc_F00D2AD0
F00D2AA4: 80a72000                 cmp     %i4, 0
F00D2AA8: 22800047                 be,a    locret_F00D2BC4
F00D2AAC: b0103d3e                 mov     -0x2C2, %i0
F00D2AB0: d0062150                 ld      [%i0+0x150], %o0
F00D2AB4: 80a22000                 cmp     %o0, 0
F00D2AB8: 32800043                 bne,a   locret_F00D2BC4
F00D2ABC: b0103d3e                 mov     -0x2C2, %i0
F00D2AC0: d0062154                 ld      [%i0+0x154], %o0
F00D2AC4: 80a22000                 cmp     %o0, 0
F00D2AC8: 02800004                 be      loc_F00D2AD8
F00D2ACC: 9010001b                 mov     %i3, %o0
F00D2AD0: 1080003d                 ba      locret_F00D2BC4
F00D2AD4: b0103d3e                 mov     -0x2C2, %i0
F00D2AD8: 9210001c                 mov     %i4, %o1! SEL
F00D2ADC: 9407bfec                 add     %fp, var_14, %o2
F00D2AE0: 9607bfe8                 add     %fp, var_18, %o3
F00D2AE4: 7fffb145                 call    _createEventShmem
F00D2AE8: 9806215c                 add     %i0, 0x15C, %o4
F00D2AEC: a2920000                 orcc    %o0, %g0, %l1
F00D2AF0: 1280002b                 bne     loc_F00D2B9C
F00D2AF4: 90100018                 mov     %i0, %o0
F00D2AF8: 113c0504                 sethi   %hi(paLock), %o0
F00D2AFC: e2022000                 ld      [%o0+%lo(paLock)], %l1
F00D2B00: d0062110                 ld      [%i0+0x110], %o0! id
F00D2B04: 40007b5b                 call    _objc_msgSend
F00D2B08: 92100011                 mov     %l1, %o1
F00D2B0C: f8262160                 st      %i4, [%i0+0x160]
F00D2B10: f6262150                 st      %i3, [%i0+0x150]
F00D2B14: d207bfe8                 ld      [%fp+var_18], %o1
F00D2B18: 90100018                 mov     %i0, %o0! id
F00D2B1C: d2262158                 st      %o1, [%i0+0x158]
F00D2B20: d2274000                 st      %o1, [%i5]
F00D2B24: d407bfec                 ld      [%fp+var_14], %o2
F00D2B28: 133c0505                 sethi   %hi(paInitshmem), %o1
F00D2B2C: d202630c                 ld      [%o1+%lo(paInitshmem)], %o1! SEL
F00D2B30: 40007b50                 call    _objc_msgSend
F00D2B34: d4262154                 st      %o2, [%i0+0x154]
F00D2B38: 113c0504                 sethi   %hi(paUnlock), %o0
F00D2B3C: e0022244                 ld      [%o0+%lo(paUnlock)], %l0
F00D2B40: d0062110                 ld      [%i0+0x110], %o0! id
F00D2B44: 40007b4b                 call    _objc_msgSend
F00D2B48: 92100010                 mov     %l0, %o1
F00D2B4C: 113c0505                 sethi   %hi(paResetmousepara), %o0! id
F00D2B50: d202231c                 ld      [%o0+%lo(paResetmousepara)], %o1! SEL
F00D2B54: 40007b47                 call    _objc_msgSend
F00D2B58: 90100018                 mov     %i0, %o0
F00D2B5C: 113c0505                 sethi   %hi(paResetkeyboardp), %o0! id
F00D2B60: d2022318                 ld      [%o0+%lo(paResetkeyboardp)], %o1! SEL
F00D2B64: 40007b43                 call    _objc_msgSend
F00D2B68: 90100018                 mov     %i0, %o0
F00D2B6C: d0062110                 ld      [%i0+0x110], %o0! id
F00D2B70: 40007b40                 call    _objc_msgSend
F00D2B74: 92100011                 mov     %l1, %o1
F00D2B78: 113c0505                 sethi   %hi(paSchedulenextpe), %o0! id
F00D2B7C: d2022308                 ld      [%o0+%lo(paSchedulenextpe)], %o1! SEL
F00D2B80: 40007b3c                 call    _objc_msgSend
F00D2B84: 90100018                 mov     %i0, %o0
F00D2B88: d0062110                 ld      [%i0+0x110], %o0! id
F00D2B8C: 40007b39                 call    _objc_msgSend
F00D2B90: 92100010                 mov     %l0, %o1
F00D2B94: 1080000c                 ba      locret_F00D2BC4
F00D2B98: b0102000                 mov     0, %i0
F00D2B9C: 133c0504                 sethi   %hi(paName), %o1
F00D2BA0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D2BA4: 213c03ef                 sethi   %hi(aSCreateeventsh), %l0! "%s: createEventShmem fails (%d).\n"
F00D2BA8: 40007b32                 call    _objc_msgSend
F00D2BAC: a0142198                 bset    %lo(aSCreateeventsh), %l0! "%s: createEventShmem fails (%d).\n"
F00D2BB0: 92100008                 mov     %o0, %o1
F00D2BB4: 90100010                 mov     %l0, %o0
F00D2BB8: 7fffcd4f                 call    _IOLog
F00D2BBC: 94100011                 mov     %l1, %o2
F00D2BC0: b0100011                 mov     %l1, %i0
F00D2BC4: 81c7e008                 ret
F00D2BC8: 81e80000                 restore
