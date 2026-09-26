F00CAA38: 9de3bf90                 save    %sp, -0x70, %sp
F00CAA3C: f027bff0                 st      %i0, [%fp+var_10]
F00CAA40: 133c0508                 sethi   %hi(stru_F014204C.ext), %o1
F00CAA44: d4026078                 ld      [%o1+%lo(stru_F014204C.ext)], %o2
F00CAA48: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CAA4C: 133c0504                 sethi   %hi(paInit), %o1
F00CAA50: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00CAA54: 40009bca                 call    _objc_msgSendSuper
F00CAA58: d427bff4                 st      %o2, [%fp+var_C]
F00CAA5C: c0262008                 clr     [%i0+8]
F00CAA60: c0262004                 clr     [%i0+4]
F00CAA64: c026200c                 clr     [%i0+0xC]
F00CAA68: f4262010                 st      %i2, [%i0+0x10]
F00CAA6C: 81c7e008                 ret
F00CAA70: 81e80000                 restore
