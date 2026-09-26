F008D470: 9de3bf90                 save    %sp, -0x70, %sp
F008D474: d0062014                 ld      [%i0+0x14], %o0
F008D478: 80a22000                 cmp     %o0, 0
F008D47C: 1480000a                 bg      locret_F008D4A4
F008D480: 133c0506                 sethi   %hi(stru_F0141B4C.ext), %o1
F008D484: f027bff0                 st      %i0, [%fp+var_10]
F008D488: d4026378                 ld      [%o1+%lo(stru_F0141B4C.ext)], %o2
F008D48C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D490: 133c0503                 sethi   %hi(paFree), %o1
F008D494: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008D498: 40019139                 call    _objc_msgSendSuper
F008D49C: d427bff4                 st      %o2, [%fp+var_C]
F008D4A0: b0100008                 mov     %o0, %i0
F008D4A4: 81c7e008                 ret
F008D4A8: 81e80000                 restore
