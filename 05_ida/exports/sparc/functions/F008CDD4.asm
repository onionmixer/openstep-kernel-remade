F008CDD4: 9de3bf90                 save    %sp, -0x70, %sp
F008CDD8: f027bff0                 st      %i0, [%fp+var_10]
F008CDDC: 133c0506                 sethi   %hi(stru_F0141B9C.ext), %o1
F008CDE0: d40263c8                 ld      [%o1+%lo(stru_F0141B9C.ext)], %o2
F008CDE4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CDE8: 133c0503                 sethi   %hi(paFree), %o1
F008CDEC: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008CDF0: 400192e3                 call    _objc_msgSendSuper
F008CDF4: d427bff4                 st      %o2, [%fp+var_C]
F008CDF8: 81c7e008                 ret
F008CDFC: 91e80008                 restore %g0, %o0, %o0
