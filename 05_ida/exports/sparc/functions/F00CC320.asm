F00CC320: 9de3bf90                 save    %sp, -0x70, %sp
F00CC324: f027bff0                 st      %i0, [%fp+var_10]
F00CC328: 133c0508                 sethi   %hi(stru_F01420EC.ext), %o1
F00CC32C: d4026118                 ld      [%o1+%lo(stru_F01420EC.ext)], %o2
F00CC330: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CC334: 133c0504                 sethi   %hi(paInit), %o1
F00CC338: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00CC33C: 40009590                 call    _objc_msgSendSuper
F00CC340: d427bff4                 st      %o2, [%fp+var_C]
F00CC344: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F00CC348: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F00CC34C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00CC350: 40009548                 call    _objc_msgSend
F00CC354: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00CC358: 133c0503                 sethi   %hi(paInitwith), %o1
F00CC35C: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F00CC360: 40009544                 call    _objc_msgSend
F00CC364: 94102003                 mov     3, %o2
F00CC368: d0262008                 st      %o0, [%i0+8]
F00CC36C: 7ffff7ca                 call    _IOGetKernPort
F00CC370: 9010001a                 mov     %i2, %o0
F00CC374: d0262004                 st      %o0, [%i0+4]
F00CC378: 81c7e008                 ret
F00CC37C: 81e80000                 restore
