F008C8C8: 9de3bf90                 save    %sp, -0x70, %sp
F008C8CC: f027bff0                 st      %i0, [%fp+var_10]
F008C8D0: 133c0506                 sethi   %hi(stru_F0141AFC.super_class), %o1
F008C8D4: d4026300                 ld      [%o1+%lo(stru_F0141AFC.super_class)], %o2
F008C8D8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008C8DC: 133c0503                 sethi   %hi(paFree), %o1
F008C8E0: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008C8E4: 40019426                 call    _objc_msgSendSuper
F008C8E8: d427bff4                 st      %o2, [%fp+var_C]
F008C8EC: 81c7e008                 ret
F008C8F0: 91e80008                 restore %g0, %o0, %o0
