F00EB060: 9de3bf90                 save    %sp, -0x70, %sp
F00EB064: 7ffdf4a7                 call    _free
F00EB068: d0062004                 ld      [%i0+4], %o0
F00EB06C: f027bff0                 st      %i0, [%fp+var_10]
F00EB070: 113c0508                 sethi   %hi(stru_F01423BC.super_class), %o0
F00EB074: d00223c0                 ld      [%o0+%lo(stru_F01423BC.super_class)], %o0
F00EB078: d027bff4                 st      %o0, [%fp+var_C]
F00EB07C: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00EB080: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00EB084: 40001a3e                 call    _objc_msgSendSuper
F00EB088: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00EB08C: 81c7e008                 ret
F00EB090: 91e80008                 restore %g0, %o0, %o0
