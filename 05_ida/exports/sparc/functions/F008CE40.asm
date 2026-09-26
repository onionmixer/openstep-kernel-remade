F008CE40: 9de3bf90                 save    %sp, -0x70, %sp
F008CE44: d006200c                 ld      [%i0+0xC], %o0
F008CE48: 80a22000                 cmp     %o0, 0
F008CE4C: 1480000a                 bg      locret_F008CE74
F008CE50: 133c0506                 sethi   %hi(stru_F0141B9C.ext), %o1
F008CE54: f027bff0                 st      %i0, [%fp+var_10]
F008CE58: d40263c8                 ld      [%o1+%lo(stru_F0141B9C.ext)], %o2
F008CE5C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CE60: 133c0503                 sethi   %hi(paFree), %o1
F008CE64: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008CE68: 400192c5                 call    _objc_msgSendSuper
F008CE6C: d427bff4                 st      %o2, [%fp+var_C]
F008CE70: b0100008                 mov     %o0, %i0
F008CE74: 81c7e008                 ret
F008CE78: 81e80000                 restore
