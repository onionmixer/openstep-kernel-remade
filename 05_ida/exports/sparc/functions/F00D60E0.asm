F00D60E0: 9de3bf90                 save    %sp, -0x70, %sp
F00D60E4: d00624f4                 ld      [%i0+0x4F4], %o0! id
F00D60E8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D60EC: 40006de1                 call    _objc_msgSend
F00D60F0: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D60F4: e20624f4                 ld      [%i0+0x4F4], %l1
F00D60F8: d40624ec                 ld      [%i0+0x4EC], %o2
F00D60FC: 80a2a000                 cmp     %o2, 0
F00D6100: 0280000a                 be      loc_F00D6128
F00D6104: c02624f4                 clr     [%i0+0x4F4]
F00D6108: d04e24fc                 ldsb    [%i0+0x4FC], %o0
F00D610C: 80a22001                 cmp     %o0, 1
F00D6110: 32800007                 bne,a   loc_F00D612C
F00D6114: 113c0504                 sethi   -0xFEBF000, %o0
F00D6118: d20624f0                 ld      [%i0+0x4F0], %o1
F00D611C: 7fffbf8a                 call    _IOFree
F00D6120: 9010000a                 mov     %o2, %o0
F00D6124: c02624ec                 clr     [%i0+0x4EC]
F00D6128: 113c0504                 sethi   -0xFEBF000, %o0! id
F00D612C: d2022244                 ld      [%o0+0x244], %o1! SEL
F00D6130: 40006dd0                 call    _objc_msgSend
F00D6134: 90100011                 mov     %l1, %o0
F00D6138: 113c0503                 sethi   %hi(paFree), %o0
F00D613C: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00D6140: 90100011                 mov     %l1, %o0! id
F00D6144: 40006dcb                 call    _objc_msgSend
F00D6148: 92100010                 mov     %l0, %o1
F00D614C: f027bff0                 st      %i0, [%fp+var_10]
F00D6150: 133c0508                 sethi   %hi(stru_F014222C.super_class), %o1
F00D6154: d4026230                 ld      [%o1+%lo(stru_F014222C.super_class)], %o2
F00D6158: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D615C: 92100010                 mov     %l0, %o1! SEL
F00D6160: 40006e07                 call    _objc_msgSendSuper
F00D6164: d427bff4                 st      %o2, [%fp+var_C]
F00D6168: 81c7e008                 ret
F00D616C: 91e80008                 restore %g0, %o0, %o0
