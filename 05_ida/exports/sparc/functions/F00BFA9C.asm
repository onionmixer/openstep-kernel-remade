F00BFA9C: 9de3bf90                 save    %sp, -0x70, %sp
F00BFAA0: a0100018                 mov     %i0, %l0
F00BFAA4: b0103d3e                 mov     -0x2C2, %i0
F00BFAA8: 9010001b                 mov     %i3, %o0! __s1
F00BFAAC: e2070000                 ld      [%i4], %l1
F00BFAB0: 133c0482                 sethi   %hi(aEvsCurrentkeyr), %o1! "Evs_CurrentKeyRepeat"
F00BFAB4: 7ffd21be                 call    _strcmp
F00BFAB8: 92126388                 bset    %lo(aEvsCurrentkeyr), %o1! "Evs_CurrentKeyRepeat"
F00BFABC: 80a22000                 cmp     %o0, 0
F00BFAC0: 32800012                 bne,a   loc_F00BFB08
F00BFAC4: 9010001b                 mov     %i3, %o0
F00BFAC8: 80a46003                 cmp     %l1, 3
F00BFACC: 08800053                 bleu    locret_F00BFC18
F00BFAD0: 90102004                 mov     4, %o0
F00BFAD4: d0270000                 st      %o0, [%i4]
F00BFAD8: d0042124                 ld      [%l0+0x124], %o0! id
F00BFADC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BFAE0: 4000c764                 call    _objc_msgSend
F00BFAE4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BFAE8: 90042170                 add     %l0, 0x170, %o0
F00BFAEC: 7ffffdaa                 call    sub_F00BF194
F00BFAF0: 9210001a                 mov     %i2, %o1
F00BFAF4: 90042168                 add     %l0, 0x168, %o0
F00BFAF8: 7ffffda7                 call    sub_F00BF194
F00BFAFC: 9206a008                 add     %i2, 8, %o1
F00BFB00: 1080001b                 ba      loc_F00BFB6C
F00BFB04: d0042124                 ld      [%l0+0x124], %o0! __s1
F00BFB08: 133c0482                 sethi   %hi(aEvsCurrentkeym), %o1! "Evs_CurrentKeyMappingLength"
F00BFB0C: 7ffd21a8                 call    _strcmp
F00BFB10: 921263a0                 bset    %lo(aEvsCurrentkeym), %o1! "Evs_CurrentKeyMappingLength"
F00BFB14: 80a22000                 cmp     %o0, 0
F00BFB18: 3280001a                 bne,a   loc_F00BFB80
F00BFB1C: 9010001b                 mov     %i3, %o0
F00BFB20: 80a46000                 cmp     %l1, 0
F00BFB24: 0280003d                 be      locret_F00BFC18
F00BFB28: 90102001                 mov     1, %o0
F00BFB2C: d0270000                 st      %o0, [%i4]
F00BFB30: d0042124                 ld      [%l0+0x124], %o0! id
F00BFB34: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BFB38: 4000c74e                 call    _objc_msgSend
F00BFB3C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BFB40: d4042128                 ld      [%l0+0x128], %o2
F00BFB44: 80a2a000                 cmp     %o2, 0
F00BFB48: 12800004                 bne     loc_F00BFB58
F00BFB4C: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BFB50: 10800006                 ba      loc_F00BFB68
F00BFB54: c0268000                 clr     [%i2]
F00BFB58: d20222bc                 ld      [%o0+0x2BC], %o1! SEL
F00BFB5C: 4000c745                 call    _objc_msgSend
F00BFB60: 9010000a                 mov     %o2, %o0
F00BFB64: d0268000                 st      %o0, [%i2]
F00BFB68: d0042124                 ld      [%l0+0x124], %o0! id
F00BFB6C: 133c0504                 sethi   %hi(paUnlock), %o1
F00BFB70: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00BFB74: 4000c73f                 call    _objc_msgSend
F00BFB78: b0102000                 mov     0, %i0
F00BFB7C: 30800027                 ba,a    locret_F00BFC18
F00BFB80: 133c0482                 sethi   %hi(aEvsEventdevice_0), %o1! "Evs_EventDeviceInfo"
F00BFB84: 7ffd218a                 call    _strcmp
F00BFB88: 921263c0                 bset    %lo(aEvsEventdevice_0), %o1! "Evs_EventDeviceInfo"
F00BFB8C: 80a22000                 cmp     %o0, 0
F00BFB90: 32800014                 bne,a   loc_F00BFBE0
F00BFB94: e027bff0                 st      %l0, [%fp+var_10]
F00BFB98: c0270000                 clr     [%i4]
F00BFB9C: d004212c                 ld      [%l0+0x12C], %o0! id
F00BFBA0: 133c0504                 sethi   %hi(paInterfaceid), %o1! SEL
F00BFBA4: 4000c733                 call    _objc_msgSend
F00BFBA8: d20262c0                 ld      [%o1+%lo(paInterfaceid)], %o1
F00BFBAC: d0268000                 st      %o0, [%i2]
F00BFBB0: 90102001                 mov     1, %o0
F00BFBB4: d026a008                 st      %o0, [%i2+8]
F00BFBB8: c026a004                 clr     [%i2+4]
F00BFBBC: d004212c                 ld      [%l0+0x12C], %o0! id
F00BFBC0: 133c0504                 sethi   %hi(paHandlerid), %o1
F00BFBC4: d20262c4                 ld      [%o1+%lo(paHandlerid)], %o1! SEL
F00BFBC8: 4000c72a                 call    _objc_msgSend
F00BFBCC: b0102000                 mov     0, %i0
F00BFBD0: d026a00c                 st      %o0, [%i2+0xC]
F00BFBD4: 90102004                 mov     4, %o0
F00BFBD8: 10800010                 ba      locret_F00BFC18
F00BFBDC: d0270000                 st      %o0, [%i4]
F00BFBE0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BFBE4: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BFBE8: 9610001b                 mov     %i3, %o3
F00BFBEC: d4026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o2
F00BFBF0: 9810001c                 mov     %i4, %o4
F00BFBF4: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00BFBF8: d427bff4                 st      %o2, [%fp+var_C]
F00BFBFC: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00BFC00: 4000c75f                 call    _objc_msgSendSuper
F00BFC04: 9410001a                 mov     %i2, %o2
F00BFC08: b0100008                 mov     %o0, %i0
F00BFC0C: 80a63d39                 cmp     %i0, -0x2C7
F00BFC10: 22800002                 be,a    locret_F00BFC18
F00BFC14: b0103d3e                 mov     -0x2C2, %i0
F00BFC18: 81c7e008                 ret
F00BFC1C: 81e80000                 restore
