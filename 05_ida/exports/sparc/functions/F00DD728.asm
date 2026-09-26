F00DD728: 9de3bf90                 save    %sp, -0x70, %sp
F00DD72C: f027bff0                 st      %i0, [%fp+var_10]
F00DD730: 133c0508                 sethi   %hi(stru_F014231C.super_class), %o1
F00DD734: d4026320                 ld      [%o1+%lo(stru_F014231C.super_class)], %o2
F00DD738: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DD73C: 133c0504                 sethi   %hi(paInit), %o1
F00DD740: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00DD744: 4000508e                 call    _objc_msgSendSuper
F00DD748: d427bff4                 st      %o2, [%fp+var_C]
F00DD74C: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F00DD750: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F00DD754: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00DD758: 40005046                 call    _objc_msgSend
F00DD75C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00DD760: 133c0503                 sethi   %hi(paInitwith), %o1
F00DD764: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F00DD768: 40005042                 call    _objc_msgSend
F00DD76C: 94102003                 mov     3, %o2
F00DD770: d0262008                 st      %o0, [%i0+8]
F00DD774: f4262004                 st      %i2, [%i0+4]
F00DD778: 81c7e008                 ret
F00DD77C: 81e80000                 restore
