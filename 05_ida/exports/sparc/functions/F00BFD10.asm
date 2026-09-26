F00BFD10: 9de3bf90                 save    %sp, -0x70, %sp
F00BFD14: a0100018                 mov     %i0, %l0
F00BFD18: b0103d3e                 mov     -0x2C2, %i0
F00BFD1C: 9010001b                 mov     %i3, %o0! __s1
F00BFD20: 133c0482                 sethi   %hi(aEvsSetkeyrepea), %o1! "Evs_SetKeyRepeat"
F00BFD24: 7ffd2122                 call    _strcmp
F00BFD28: 921263f0                 bset    %lo(aEvsSetkeyrepea), %o1! "Evs_SetKeyRepeat"
F00BFD2C: 80a22000                 cmp     %o0, 0
F00BFD30: 3280001e                 bne,a   loc_F00BFDA8
F00BFD34: 9010001b                 mov     %i3, %o0
F00BFD38: 80a72002                 cmp     %i4, 2
F00BFD3C: 12800057                 bne     locret_F00BFE98
F00BFD40: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BFD44: d0042124                 ld      [%l0+0x124], %o0! id
F00BFD48: 4000c6ca                 call    _objc_msgSend
F00BFD4C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BFD50: 9010001a                 mov     %i2, %o0
F00BFD54: 7ffffd1e                 call    sub_F00BF1CC
F00BFD58: 92042168                 add     %l0, 0x168, %o1
F00BFD5C: d0042168                 ld      [%l0+0x168], %o0
F00BFD60: 80a22000                 cmp     %o0, 0
F00BFD64: 3880000e                 bgu,a   loc_F00BFD9C
F00BFD68: d0042124                 ld      [%l0+0x124], %o0
F00BFD6C: 12800007                 bne     loc_F00BFD88
F00BFD70: 11003fb4                 sethi   0xFED000, %o0
F00BFD74: d204216c                 ld      [%l0+0x16C], %o1
F00BFD78: 9012225f                 bset    0x25F, %o0
F00BFD7C: 80a24008                 cmp     %o1, %o0
F00BFD80: 38800007                 bgu,a   loc_F00BFD9C
F00BFD84: d0042124                 ld      [%l0+0x124], %o0
F00BFD88: 90102000                 mov     0, %o0
F00BFD8C: 13003fb492126260         set     0xFED260, %o1
F00BFD94: d03c2168                 std     %o0, [%l0+0x168]
F00BFD98: d0042124                 ld      [%l0+0x124], %o0! __s1
F00BFD9C: 133c0504                 sethi   %hi(paUnlock), %o1
F00BFDA0: 1080002d                 ba      loc_F00BFE54
F00BFDA4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BFDA8: 133c0483                 sethi   %hi(aEvsSetinitialk), %o1! "Evs_SetInitialKeyRepeat"
F00BFDAC: 7ffd2100                 call    _strcmp
F00BFDB0: 92126008                 bset    %lo(aEvsSetinitialk), %o1! "Evs_SetInitialKeyRepeat"
F00BFDB4: 80a22000                 cmp     %o0, 0
F00BFDB8: 3280001e                 bne,a   loc_F00BFE30
F00BFDBC: 9010001b                 mov     %i3, %o0
F00BFDC0: 80a72002                 cmp     %i4, 2
F00BFDC4: 12800035                 bne     locret_F00BFE98
F00BFDC8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BFDCC: d0042124                 ld      [%l0+0x124], %o0! id
F00BFDD0: 4000c6a8                 call    _objc_msgSend
F00BFDD4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BFDD8: 9010001a                 mov     %i2, %o0
F00BFDDC: 7ffffcfc                 call    sub_F00BF1CC
F00BFDE0: 92042170                 add     %l0, 0x170, %o1
F00BFDE4: d0042170                 ld      [%l0+0x170], %o0
F00BFDE8: 80a22000                 cmp     %o0, 0
F00BFDEC: 3880000e                 bgu,a   loc_F00BFE24
F00BFDF0: d0042124                 ld      [%l0+0x124], %o0
F00BFDF4: 12800007                 bne     loc_F00BFE10
F00BFDF8: 11003fb4                 sethi   0xFED000, %o0
F00BFDFC: d2042174                 ld      [%l0+0x174], %o1
F00BFE00: 9012225f                 bset    0x25F, %o0
F00BFE04: 80a24008                 cmp     %o1, %o0
F00BFE08: 38800007                 bgu,a   loc_F00BFE24
F00BFE0C: d0042124                 ld      [%l0+0x124], %o0
F00BFE10: 90102000                 mov     0, %o0
F00BFE14: 13003fb492126260         set     0xFED260, %o1
F00BFE1C: d03c2170                 std     %o0, [%l0+0x170]
F00BFE20: d0042124                 ld      [%l0+0x124], %o0! __s1
F00BFE24: 133c0504                 sethi   %hi(paUnlock), %o1
F00BFE28: 1080000b                 ba      loc_F00BFE54
F00BFE2C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BFE30: 133c0483                 sethi   %hi(aEvsResetkeyboa_0), %o1! "Evs_ResetKeyboard"
F00BFE34: 7ffd20de                 call    _strcmp
F00BFE38: 92126020                 bset    %lo(aEvsResetkeyboa_0), %o1! "Evs_ResetKeyboard"
F00BFE3C: 80a22000                 cmp     %o0, 0
F00BFE40: 32800008                 bne,a   loc_F00BFE60
F00BFE44: e027bff0                 st      %l0, [%fp+var_10]
F00BFE48: 90100010                 mov     %l0, %o0! id
F00BFE4C: 133c0504                 sethi   %hi(paResetkeyboard), %o1
F00BFE50: d20262d4                 ld      [%o1+%lo(paResetkeyboard)], %o1! SEL
F00BFE54: 4000c687                 call    _objc_msgSend
F00BFE58: b0102000                 mov     0, %i0
F00BFE5C: 3080000f                 ba,a    locret_F00BFE98
F00BFE60: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BFE64: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BFE68: 9610001b                 mov     %i3, %o3
F00BFE6C: d4026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o2
F00BFE70: 9810001c                 mov     %i4, %o4
F00BFE74: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00BFE78: d427bff4                 st      %o2, [%fp+var_C]
F00BFE7C: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00BFE80: 4000c6bf                 call    _objc_msgSendSuper
F00BFE84: 9410001a                 mov     %i2, %o2
F00BFE88: b0100008                 mov     %o0, %i0
F00BFE8C: 80a63d39                 cmp     %i0, -0x2C7
F00BFE90: 22800002                 be,a    locret_F00BFE98
F00BFE94: b0103d3e                 mov     -0x2C2, %i0
F00BFE98: 81c7e008                 ret
F00BFE9C: 81e80000                 restore
