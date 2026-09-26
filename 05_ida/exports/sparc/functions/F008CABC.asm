F008CABC: 9de3bf90                 save    %sp, -0x70, %sp
F008CAC0: d0062014                 ld      [%i0+0x14], %o0
F008CAC4: 80a22000                 cmp     %o0, 0
F008CAC8: 14800015                 bg      locret_F008CB1C
F008CACC: 01000000                 nop
F008CAD0: d0062008                 ld      [%i0+8], %o0
F008CAD4: 80a22000                 cmp     %o0, 0
F008CAD8: 22800009                 be,a    loc_F008CAFC
F008CADC: f027bff0                 st      %i0, [%fp+var_10]
F008CAE0: d0062018                 ld      [%i0+0x18], %o0
F008CAE4: 80a22000                 cmp     %o0, 0
F008CAE8: 22800005                 be,a    loc_F008CAFC
F008CAEC: f027bff0                 st      %i0, [%fp+var_10]
F008CAF0: 4000e515                 call    _IOFree
F008CAF4: 92102004                 mov     4, %o1
F008CAF8: f027bff0                 st      %i0, [%fp+var_10]
F008CAFC: 133c0506                 sethi   %hi(stru_F0141BEC.super_class), %o1
F008CB00: d40263f0                 ld      [%o1+%lo(stru_F0141BEC.super_class)], %o2
F008CB04: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CB08: 133c0503                 sethi   %hi(paFree), %o1
F008CB0C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008CB10: 4001939b                 call    _objc_msgSendSuper
F008CB14: d427bff4                 st      %o2, [%fp+var_C]
F008CB18: b0100008                 mov     %o0, %i0
F008CB1C: 81c7e008                 ret
F008CB20: 81e80000                 restore
