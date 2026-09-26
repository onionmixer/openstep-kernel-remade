F00C5E2C: 9de3bf90                 save    %sp, -0x70, %sp
F00C5E30: e0062004                 ld      [%i0+4], %l0
F00C5E34: 80a42000                 cmp     %l0, 0
F00C5E38: 22800008                 be,a    loc_F00C5E58
F00C5E3C: f027bff0                 st      %i0, [%fp+var_10]
F00C5E40: 7ffd057e                 call    _strlen
F00C5E44: 90100010                 mov     %l0, %o0
F00C5E48: 92022001                 add     %o0, 1, %o1
F00C5E4C: 4000003e                 call    _IOFree
F00C5E50: 90100010                 mov     %l0, %o0
F00C5E54: f027bff0                 st      %i0, [%fp+var_10]
F00C5E58: 133c0507                 sethi   %hi(stru_F0141EBC.super_class), %o1
F00C5E5C: d40262c0                 ld      [%o1+%lo(stru_F0141EBC.super_class)], %o2
F00C5E60: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C5E64: 133c0503                 sethi   %hi(paFree), %o1
F00C5E68: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C5E6C: 4000aec4                 call    _objc_msgSendSuper
F00C5E70: d427bff4                 st      %o2, [%fp+var_C]
F00C5E74: 81c7e008                 ret
F00C5E78: 91e80008                 restore %g0, %o0, %o0
