F00BFEA0: 9de3bf90                 save    %sp, -0x70, %sp
F00BFEA4: a2103d3e                 mov     -0x2C2, %l1
F00BFEA8: 9010001b                 mov     %i3, %o0! __s1
F00BFEAC: 133c0483                 sethi   %hi(aEvsSetkeymappi), %o1! "Evs_SetKeyMapping"
F00BFEB0: 7ffd20bf                 call    _strcmp
F00BFEB4: 92126038                 bset    %lo(aEvsSetkeymappi), %o1! "Evs_SetKeyMapping"
F00BFEB8: 80a22000                 cmp     %o0, 0
F00BFEBC: 32800030                 bne,a   loc_F00BFF7C
F00BFEC0: f027bff0                 st      %i0, [%fp+var_10]
F00BFEC4: 4000181b                 call    _IOMalloc
F00BFEC8: 9010001c                 mov     %i4, %o0
F00BFECC: a0100008                 mov     %o0, %l0
F00BFED0: 9010001a                 mov     %i2, %o0! void *
F00BFED4: 92100010                 mov     %l0, %o1! void *
F00BFED8: 7fff530e                 call    _bcopy
F00BFEDC: 9410001c                 mov     %i4, %o2
F00BFEE0: d0062124                 ld      [%i0+0x124], %o0! id
F00BFEE4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BFEE8: 4000c662                 call    _objc_msgSend
F00BFEEC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BFEF0: 113c0506                 sethi   %hi(paKeymap), %o0
F00BFEF4: d00222a4                 ld      [%o0+%lo(paKeymap)], %o0! id
F00BFEF8: 133c0503                 sethi   %hi(paAlloc), %o1
F00BFEFC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00BFF00: 4000c65c                 call    _objc_msgSend
F00BFF04: f4062128                 ld      [%i0+0x128], %i2
F00BFF08: 94100010                 mov     %l0, %o2
F00BFF0C: 9610001c                 mov     %i4, %o3
F00BFF10: 133c0504                 sethi   %hi(paInitfromkeymap), %o1
F00BFF14: d2026284                 ld      [%o1+%lo(paInitfromkeymap)], %o1! SEL
F00BFF18: 4000c656                 call    _objc_msgSend
F00BFF1C: 98102001                 mov     1, %o4
F00BFF20: 80a22000                 cmp     %o0, 0
F00BFF24: 02800010                 be      loc_F00BFF64
F00BFF28: d0262128                 st      %o0, [%i0+0x128]
F00BFF2C: 80a6a000                 cmp     %i2, 0
F00BFF30: 02800005                 be      loc_F00BFF44
F00BFF34: 113c0503                 sethi   %hi(paFree), %o0! id
F00BFF38: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00BFF3C: 4000c64d                 call    _objc_msgSend
F00BFF40: 9010001a                 mov     %i2, %o0
F00BFF44: 94100018                 mov     %i0, %o2
F00BFF48: d0062128                 ld      [%i0+0x128], %o0! id
F00BFF4C: 133c0504                 sethi   %hi(paSetdelegate), %o1
F00BFF50: d2026288                 ld      [%o1+%lo(paSetdelegate)], %o1! SEL
F00BFF54: 4000c647                 call    _objc_msgSend
F00BFF58: a2102000                 mov     0, %l1
F00BFF5C: 10800004                 ba      loc_F00BFF6C
F00BFF60: d0062124                 ld      [%i0+0x124], %o0
F00BFF64: f4262128                 st      %i2, [%i0+0x128]
F00BFF68: d0062124                 ld      [%i0+0x124], %o0! id
F00BFF6C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BFF70: 4000c640                 call    _objc_msgSend
F00BFF74: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BFF78: 3080000f                 ba,a    locret_F00BFFB4
F00BFF7C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BFF80: 9410001a                 mov     %i2, %o2
F00BFF84: 9610001b                 mov     %i3, %o3
F00BFF88: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BFF8C: da026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o5
F00BFF90: 9810001c                 mov     %i4, %o4
F00BFF94: 133c0504                 sethi   %hi(paSetcharvaluesF_0), %o1
F00BFF98: d20262d8                 ld      [%o1+%lo(paSetcharvaluesF_0)], %o1! SEL
F00BFF9C: 4000c678                 call    _objc_msgSendSuper
F00BFFA0: da27bff4                 st      %o5, [%fp+var_C]
F00BFFA4: a2100008                 mov     %o0, %l1
F00BFFA8: 80a47d39                 cmp     %l1, -0x2C7
F00BFFAC: 22800002                 be,a    locret_F00BFFB4
F00BFFB0: a2103d3e                 mov     -0x2C2, %l1
F00BFFB4: 81c7e008                 ret
F00BFFB8: 91e80011                 restore %g0, %l1, %o0
