F008D8BC: 9de3bf90                 save    %sp, -0x70, %sp
F008D8C0: d0062008                 ld      [%i0+8], %o0
F008D8C4: 80a22000                 cmp     %o0, 0
F008D8C8: 1480000a                 bg      locret_F008D8F0
F008D8CC: 133c0506                 sethi   %hi(stru_F0141AFC.ext), %o1
F008D8D0: f027bff0                 st      %i0, [%fp+var_10]
F008D8D4: d4026328                 ld      [%o1+%lo(stru_F0141AFC.ext)], %o2
F008D8D8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D8DC: 133c0503                 sethi   %hi(paFree), %o1
F008D8E0: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008D8E4: 40019026                 call    _objc_msgSendSuper
F008D8E8: d427bff4                 st      %o2, [%fp+var_C]
F008D8EC: b0100008                 mov     %o0, %i0
F008D8F0: 81c7e008                 ret
F008D8F4: 81e80000                 restore
