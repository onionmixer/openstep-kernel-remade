F00BFC20: 9de3bf90                 save    %sp, -0x70, %sp
F00BFC24: a0100018                 mov     %i0, %l0
F00BFC28: 9010001b                 mov     %i3, %o0! __s1
F00BFC2C: f0070000                 ld      [%i4], %i0
F00BFC30: 133c0482                 sethi   %hi(aEvsCurrentkeym_0), %o1! "Evs_CurrentKeyMapping"
F00BFC34: 7ffd215e                 call    _strcmp
F00BFC38: 921263d8                 bset    %lo(aEvsCurrentkeym_0), %o1! "Evs_CurrentKeyMapping"
F00BFC3C: 80a22000                 cmp     %o0, 0
F00BFC40: 32800024                 bne,a   loc_F00BFCD0
F00BFC44: e027bff0                 st      %l0, [%fp+var_10]
F00BFC48: d0042124                 ld      [%l0+0x124], %o0! id
F00BFC4C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BFC50: 4000c708                 call    _objc_msgSend
F00BFC54: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BFC58: d4042128                 ld      [%l0+0x128], %o2
F00BFC5C: 80a2a000                 cmp     %o2, 0
F00BFC60: 02800016                 be      loc_F00BFCB8
F00BFC64: 113c0504                 sethi   %hi(paKeymappingleng), %o0! id
F00BFC68: d20222bc                 ld      [%o0+%lo(paKeymappingleng)], %o1! SEL
F00BFC6C: 4000c701                 call    _objc_msgSend
F00BFC70: 9010000a                 mov     %o2, %o0
F00BFC74: b6100008                 mov     %o0, %i3
F00BFC78: 80a6c018                 cmp     %i3, %i0
F00BFC7C: 3a800002                 bcc,a   loc_F00BFC84
F00BFC80: 90100018                 mov     %i0, %o0
F00BFC84: b6100008                 mov     %o0, %i3
F00BFC88: f6270000                 st      %i3, [%i4]
F00BFC8C: 94102000                 mov     0, %o2! size_t
F00BFC90: d0042128                 ld      [%l0+0x128], %o0! id
F00BFC94: 133c0504                 sethi   %hi(paKeymapping), %o1
F00BFC98: d20262cc                 ld      [%o1+%lo(paKeymapping)], %o1! SEL
F00BFC9C: 4000c6f5                 call    _objc_msgSend
F00BFCA0: b0102000                 mov     0, %i0
F00BFCA4: 9210001a                 mov     %i2, %o1! void *
F00BFCA8: 7fff539a                 call    _bcopy
F00BFCAC: 9410001b                 mov     %i3, %o2
F00BFCB0: 10800004                 ba      loc_F00BFCC0
F00BFCB4: d0042124                 ld      [%l0+0x124], %o0
F00BFCB8: b0103d27                 mov     -0x2D9, %i0
F00BFCBC: d0042124                 ld      [%l0+0x124], %o0! id
F00BFCC0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BFCC4: 4000c6eb                 call    _objc_msgSend
F00BFCC8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BFCCC: 3080000f                 ba,a    locret_F00BFD08
F00BFCD0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BFCD4: 9410001a                 mov     %i2, %o2
F00BFCD8: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BFCDC: d6026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o3
F00BFCE0: 9810001c                 mov     %i4, %o4
F00BFCE4: 133c0504                 sethi   %hi(paGetcharvaluesF_0), %o1
F00BFCE8: d627bff4                 st      %o3, [%fp+var_C]
F00BFCEC: d20262d0                 ld      [%o1+%lo(paGetcharvaluesF_0)], %o1! SEL
F00BFCF0: 4000c723                 call    _objc_msgSendSuper
F00BFCF4: 9610001b                 mov     %i3, %o3
F00BFCF8: b0100008                 mov     %o0, %i0
F00BFCFC: 80a63d39                 cmp     %i0, -0x2C7
F00BFD00: 22800002                 be,a    locret_F00BFD08
F00BFD04: b0103d3e                 mov     -0x2C2, %i0
F00BFD08: 81c7e008                 ret
F00BFD0C: 81e80000                 restore
