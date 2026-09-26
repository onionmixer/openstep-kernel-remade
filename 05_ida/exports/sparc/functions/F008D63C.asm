F008D63C: 9de3bf90                 save    %sp, -0x70, %sp
F008D640: 94100018                 mov     %i0, %o2
F008D644: d002a004                 ld      [%o2+4], %o0! id
F008D648: 80a22000                 cmp     %o0, 0
F008D64C: 02800006                 be      loc_F008D664
F008D650: 133c0504                 sethi   %hi(paDestroymapping), %o1
F008D654: d2026060                 ld      [%o1+%lo(paDestroymapping)], %o1! SEL
F008D658: 40019086                 call    _objc_msgSend
F008D65C: c022a004                 clr     [%o2+4]
F008D660: 30800009                 ba,a    locret_F008D684
F008D664: d427bff0                 st      %o2, [%fp+var_10]
F008D668: 133c0506                 sethi   %hi(stru_F0141B4C.super_class), %o1
F008D66C: d4026350                 ld      [%o1+%lo(stru_F0141B4C.super_class)], %o2
F008D670: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D674: 133c0503                 sethi   %hi(paFree), %o1
F008D678: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008D67C: 400190c0                 call    _objc_msgSendSuper
F008D680: d427bff4                 st      %o2, [%fp+var_C]
F008D684: 81c7e008                 ret
F008D688: 91e80008                 restore %g0, %o0, %o0
