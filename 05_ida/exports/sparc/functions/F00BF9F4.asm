F00BF9F4: 9de3bf90                 save    %sp, -0x70, %sp
F00BF9F8: e2062124                 ld      [%i0+0x124], %l1
F00BF9FC: 113c0504                 sethi   %hi(paLock), %o0! id
F00BFA00: d2022000                 ld      [%o0+%lo(paLock)], %o1! SEL
F00BFA04: 4000c79b                 call    _objc_msgSend
F00BFA08: 90100011                 mov     %l1, %o0
F00BFA0C: 113c0482                 sethi   %hi(dword_F0120AE8), %o0
F00BFA10: c02222e8                 clr     [%o0+%lo(dword_F0120AE8)]
F00BFA14: d4062128                 ld      [%i0+0x128], %o2
F00BFA18: 80a2a000                 cmp     %o2, 0
F00BFA1C: 02800006                 be      loc_F00BFA34
F00BFA20: c0262124                 clr     [%i0+0x124]
F00BFA24: 113c0503                 sethi   %hi(paFree), %o0! id
F00BFA28: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00BFA2C: 4000c791                 call    _objc_msgSend
F00BFA30: 9010000a                 mov     %o2, %o0
F00BFA34: d006212c                 ld      [%i0+0x12C], %o0
F00BFA38: 80a22000                 cmp     %o0, 0
F00BFA3C: 22800007                 be,a    loc_F00BFA58
F00BFA40: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BFA44: 133c0504                 sethi   %hi(paRelinquishowne_0), %o1
F00BFA48: d20262b8                 ld      [%o1+%lo(paRelinquishowne_0)], %o1! SEL
F00BFA4C: 4000c789                 call    _objc_msgSend
F00BFA50: 94100018                 mov     %i0, %o2
F00BFA54: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BFA58: d2022244                 ld      [%o0+0x244], %o1! SEL
F00BFA5C: 4000c785                 call    _objc_msgSend
F00BFA60: 90100011                 mov     %l1, %o0
F00BFA64: 113c0503                 sethi   %hi(paFree), %o0
F00BFA68: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00BFA6C: 90100011                 mov     %l1, %o0! id
F00BFA70: 4000c780                 call    _objc_msgSend
F00BFA74: 92100010                 mov     %l0, %o1
F00BFA78: f027bff0                 st      %i0, [%fp+var_10]
F00BFA7C: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BFA80: d4026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o2
F00BFA84: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BFA88: 92100010                 mov     %l0, %o1! SEL
F00BFA8C: 4000c7bc                 call    _objc_msgSendSuper
F00BFA90: d427bff4                 st      %o2, [%fp+var_C]
F00BFA94: 81c7e008                 ret
F00BFA98: 91e80008                 restore %g0, %o0, %o0
