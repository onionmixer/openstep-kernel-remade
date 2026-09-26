F00BFFBC: 9de3bf90                 save    %sp, -0x70, %sp
F00BFFC0: f027bff0                 st      %i0, [%fp+var_10]
F00BFFC4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BFFC8: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BFFCC: d6026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o3
F00BFFD0: 9410001a                 mov     %i2, %o2
F00BFFD4: 133c0504                 sethi   %hi(paRelinquishowne_0), %o1! SEL
F00BFFD8: f40262b8                 ld      [%o1+%lo(paRelinquishowne_0)], %i2
F00BFFDC: d627bff4                 st      %o3, [%fp+var_C]
F00BFFE0: 4000c667                 call    _objc_msgSendSuper
F00BFFE4: 9210001a                 mov     %i2, %o1
F00BFFE8: 133c0504                 sethi   %hi(paOwnerlock), %o1
F00BFFEC: a0100008                 mov     %o0, %l0
F00BFFF0: d20262b0                 ld      [%o1+%lo(paOwnerlock)], %o1! SEL
F00BFFF4: 4000c61f                 call    _objc_msgSend
F00BFFF8: 90100018                 mov     %i0, %o0! id
F00BFFFC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C0000: 4000c61c                 call    _objc_msgSend
F00C0004: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C0008: 113c0482                 sethi   %hi(_wserver_on), %o0
F00C000C: 80a42000                 cmp     %l0, 0
F00C0010: 12800010                 bne     loc_F00C0050
F00C0014: c02222ec                 clr     [%o0+%lo(_wserver_on)]
F00C0018: 113c0504                 sethi   %hi(paOwner_0), %o0! id
F00C001C: d2022298                 ld      [%o0+%lo(paOwner_0)], %o1! SEL
F00C0020: 4000c614                 call    _objc_msgSend
F00C0024: 90100018                 mov     %i0, %o0
F00C0028: 80a22000                 cmp     %o0, 0
F00C002C: 1280000a                 bne     loc_F00C0054
F00C0030: 113c0504                 sethi   -0xFEBF000, %o0
F00C0034: d006212c                 ld      [%i0+0x12C], %o0! id
F00C0038: 9210001a                 mov     %i2, %o1! SEL
F00C003C: 4000c60d                 call    _objc_msgSend
F00C0040: 94100018                 mov     %i0, %o2
F00C0044: 80a22000                 cmp     %o0, 0
F00C0048: 22800002                 be,a    loc_F00C0050
F00C004C: c02e2130                 clrb    [%i0+0x130]
F00C0050: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C0054: d20222b0                 ld      [%o0+0x2B0], %o1! SEL
F00C0058: 4000c606                 call    _objc_msgSend
F00C005C: 90100018                 mov     %i0, %o0! id
F00C0060: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C0064: 4000c603                 call    _objc_msgSend
F00C0068: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C006C: 81c7e008                 ret
F00C0070: 91e80010                 restore %g0, %l0, %o0
