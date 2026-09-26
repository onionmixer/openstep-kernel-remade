F00C4AB4: 9de3bf90                 save    %sp, -0x70, %sp
F00C4AB8: f027bff0                 st      %i0, [%fp+var_10]
F00C4ABC: 133c0507                 sethi   %hi(stru_F0141E6C.ext), %o1
F00C4AC0: d4026298                 ld      [%o1+%lo(stru_F0141E6C.ext)], %o2
F00C4AC4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C4AC8: 133c0504                 sethi   %hi(paInit), %o1
F00C4ACC: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C4AD0: 4000b3ab                 call    _objc_msgSendSuper
F00C4AD4: d427bff4                 st      %o2, [%fp+var_C]
F00C4AD8: 81c7e008                 ret
F00C4ADC: 91e80008                 restore %g0, %o0, %o0
