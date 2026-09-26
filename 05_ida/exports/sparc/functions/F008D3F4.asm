F008D3F4: 9de3bf90                 save    %sp, -0x70, %sp
F008D3F8: f027bff0                 st      %i0, [%fp+var_10]
F008D3FC: 133c0506                 sethi   %hi(stru_F0141B4C.ext), %o1
F008D400: d4026378                 ld      [%o1+%lo(stru_F0141B4C.ext)], %o2
F008D404: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D408: 133c0503                 sethi   %hi(paFree), %o1
F008D40C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008D410: 4001915b                 call    _objc_msgSendSuper
F008D414: d427bff4                 st      %o2, [%fp+var_C]
F008D418: 81c7e008                 ret
F008D41C: 91e80008                 restore %g0, %o0, %o0
