F00DD780: 9de3bf90                 save    %sp, -0x70, %sp
F00DD784: 113c0503                 sethi   %hi(paFree), %o0
F00DD788: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00DD78C: d0062008                 ld      [%i0+8], %o0! id
F00DD790: 40005038                 call    _objc_msgSend
F00DD794: 92100010                 mov     %l0, %o1
F00DD798: f027bff0                 st      %i0, [%fp+var_10]
F00DD79C: 133c0508                 sethi   %hi(stru_F014231C.super_class), %o1
F00DD7A0: d4026320                 ld      [%o1+%lo(stru_F014231C.super_class)], %o2
F00DD7A4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DD7A8: 92100010                 mov     %l0, %o1! SEL
F00DD7AC: 40005074                 call    _objc_msgSendSuper
F00DD7B0: d427bff4                 st      %o2, [%fp+var_C]
F00DD7B4: 81c7e008                 ret
F00DD7B8: 91e80008                 restore %g0, %o0, %o0
