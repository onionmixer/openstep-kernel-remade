F00CD9AC: 9de3bf90                 save    %sp, -0x70, %sp
F00CD9B0: 113c0506                 sethi   %hi(paScsidisk_0), %o0
F00CD9B4: d002229c                 ld      [%o0+%lo(paScsidisk_0)], %o0! id
F00CD9B8: 133c0504                 sethi   %hi(paClass), %o1! SEL
F00CD9BC: 40008fad                 call    _objc_msgSend
F00CD9C0: d2026014                 ld      [%o1+%lo(paClass)], %o1
F00CD9C4: 80a60008                 cmp     %i0, %o0
F00CD9C8: 32800005                 bne,a   loc_F00CD9DC
F00CD9CC: f027bff0                 st      %i0, [%fp+var_10]
F00CD9D0: 7fff115b                 call    _sd_init_idmap
F00CD9D4: 01000000                 nop
F00CD9D8: f027bff0                 st      %i0, [%fp+var_10]
F00CD9DC: 133c050a                 sethi   %hi(stru_F0142A74.ext), %o1
F00CD9E0: d40262a0                 ld      [%o1+%lo(stru_F0142A74.ext)], %o2
F00CD9E4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CD9E8: 133c0505                 sethi   %hi(paInitialize), %o1
F00CD9EC: d20263ec                 ld      [%o1+%lo(paInitialize)], %o1! SEL
F00CD9F0: 40008fe3                 call    _objc_msgSendSuper
F00CD9F4: d427bff4                 st      %o2, [%fp+var_C]
F00CD9F8: 81c7e008                 ret
F00CD9FC: 91e80008                 restore %g0, %o0, %o0
