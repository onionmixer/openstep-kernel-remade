F00CA000: 9de3bf90                 save    %sp, -0x70, %sp
F00CA004: e0062004                 ld      [%i0+4], %l0
F00CA008: 80a42000                 cmp     %l0, 0
F00CA00C: 22800008                 be,a    loc_F00CA02C
F00CA010: f027bff0                 st      %i0, [%fp+var_10]
F00CA014: 7ffe7b37                 call    _lock_free
F00CA018: d0040000                 ld      [%l0], %o0
F00CA01C: 90100010                 mov     %l0, %o0
F00CA020: 7ffe7860                 call    _kfree
F00CA024: 92102004                 mov     4, %o1
F00CA028: f027bff0                 st      %i0, [%fp+var_10]
F00CA02C: 133c0508                 sethi   %hi(stru_F0141FFC.super_class), %o1
F00CA030: d4026000                 ld      [%o1+%lo(stru_F0141FFC.super_class)], %o2
F00CA034: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CA038: 133c0503                 sethi   %hi(paFree), %o1
F00CA03C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00CA040: 40009e4f                 call    _objc_msgSendSuper
F00CA044: d427bff4                 st      %o2, [%fp+var_C]
F00CA048: 81c7e008                 ret
F00CA04C: 91e80008                 restore %g0, %o0, %o0
