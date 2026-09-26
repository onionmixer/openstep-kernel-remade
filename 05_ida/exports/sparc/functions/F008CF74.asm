F008CF74: 9de3bf90                 save    %sp, -0x70, %sp
F008CF78: d0062014                 ld      [%i0+0x14], %o0
F008CF7C: 80a22000                 cmp     %o0, 0
F008CF80: 1480000a                 bg      locret_F008CFA8
F008CF84: 133c0506                 sethi   %hi(stru_F0141B9C.super_class), %o1
F008CF88: f027bff0                 st      %i0, [%fp+var_10]
F008CF8C: d40263a0                 ld      [%o1+%lo(stru_F0141B9C.super_class)], %o2
F008CF90: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CF94: 133c0503                 sethi   %hi(paFree), %o1
F008CF98: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008CF9C: 40019278                 call    _objc_msgSendSuper
F008CFA0: d427bff4                 st      %o2, [%fp+var_C]
F008CFA4: b0100008                 mov     %o0, %i0
F008CFA8: 81c7e008                 ret
F008CFAC: 81e80000                 restore
