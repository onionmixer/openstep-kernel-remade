F00D56D0: 9de3bf90                 save    %sp, -0x70, %sp
F00D56D4: d4062110                 ld      [%i0+0x110], %o2
F00D56D8: 80a2a000                 cmp     %o2, 0
F00D56DC: 02800005                 be      loc_F00D56F0
F00D56E0: 113c0503                 sethi   %hi(paFree), %o0! id
F00D56E4: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00D56E8: 40007062                 call    _objc_msgSend
F00D56EC: 9010000a                 mov     %o2, %o0
F00D56F0: f027bff0                 st      %i0, [%fp+var_10]
F00D56F4: 133c0508                 sethi   %hi(stru_F01421DC.ext), %o1
F00D56F8: d4026208                 ld      [%o1+%lo(stru_F01421DC.ext)], %o2
F00D56FC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D5700: 133c0503                 sethi   %hi(paFree), %o1
F00D5704: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00D5708: 4000709d                 call    _objc_msgSendSuper
F00D570C: d427bff4                 st      %o2, [%fp+var_C]
F00D5710: 81c7e008                 ret
F00D5714: 91e80008                 restore %g0, %o0, %o0
