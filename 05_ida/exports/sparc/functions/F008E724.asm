F008E724: 9de3bf90                 save    %sp, -0x70, %sp
F008E728: 113c0504                 sethi   %hi(paDetach), %o0! id
F008E72C: d20220d0                 ld      [%o0+%lo(paDetach)], %o1! SEL
F008E730: 40018c50                 call    _objc_msgSend
F008E734: 90100018                 mov     %i0, %o0
F008E738: 113c0503                 sethi   %hi(paFree), %o0
F008E73C: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F008E740: d0062008                 ld      [%i0+8], %o0! id
F008E744: 40018c4b                 call    _objc_msgSend
F008E748: 92100010                 mov     %l0, %o1
F008E74C: 40000104                 call    sub_F008EB5C
F008E750: d0062014                 ld      [%i0+0x14], %o0
F008E754: f027bff0                 st      %i0, [%fp+var_10]
F008E758: 133c0507                 sethi   %hi(stru_F0141C8C.super_class), %o1
F008E75C: d4026090                 ld      [%o1+%lo(stru_F0141C8C.super_class)], %o2
F008E760: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008E764: 92100010                 mov     %l0, %o1! SEL
F008E768: 40018c85                 call    _objc_msgSendSuper
F008E76C: d427bff4                 st      %o2, [%fp+var_C]
F008E770: 81c7e008                 ret
F008E774: 91e80008                 restore %g0, %o0, %o0
