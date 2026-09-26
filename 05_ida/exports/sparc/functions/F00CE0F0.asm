F00CE0F0: 9de3bf90                 save    %sp, -0x70, %sp
F00CE0F4: d04e21c8                 ldsb    [%i0+0x1C8], %o0
F00CE0F8: 80a22000                 cmp     %o0, 0
F00CE0FC: 02800005                 be      loc_F00CE110
F00CE100: 9410001a                 mov     %i2, %o2
F00CE104: 80a2a003                 cmp     %o2, 3
F00CE108: 32800002                 bne,a   loc_F00CE110
F00CE10C: c02e21c8                 clrb    [%i0+0x1C8]
F00CE110: 113c0508                 sethi   %hi(stru_F014213C.ext), %o0
F00CE114: f027bff0                 st      %i0, [%fp+var_10]
F00CE118: d0022168                 ld      [%o0+%lo(stru_F014213C.ext)], %o0! objc_super *
F00CE11C: 133c0506                 sethi   %hi(paSetlastreadyst), %o1
F00CE120: d2026178                 ld      [%o1+%lo(paSetlastreadyst)], %o1! SEL
F00CE124: d027bff4                 st      %o0, [%fp+var_C]
F00CE128: 40008e15                 call    _objc_msgSendSuper
F00CE12C: 9007bff0                 add     %fp, var_10, %o0
F00CE130: 81c7e008                 ret
F00CE134: 81e80000                 restore
