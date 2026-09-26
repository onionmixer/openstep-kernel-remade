F00C9D00: 9de3bf90                 save    %sp, -0x70, %sp
F00C9D04: e0062004                 ld      [%i0+4], %l0
F00C9D08: 80a42000                 cmp     %l0, 0
F00C9D0C: 22800008                 be,a    loc_F00C9D2C
F00C9D10: f027bff0                 st      %i0, [%fp+var_10]
F00C9D14: 7ffe7bec                 call    _simple_lock_free
F00C9D18: d0040000                 ld      [%l0], %o0
F00C9D1C: 90100010                 mov     %l0, %o0
F00C9D20: 7ffe7920                 call    _kfree
F00C9D24: 92102004                 mov     4, %o1
F00C9D28: f027bff0                 st      %i0, [%fp+var_10]
F00C9D2C: 133c0507                 sethi   %hi(stru_F0141FAC.super_class), %o1
F00C9D30: d40263b0                 ld      [%o1+%lo(stru_F0141FAC.super_class)], %o2
F00C9D34: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9D38: 133c0503                 sethi   %hi(paFree), %o1
F00C9D3C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C9D40: 40009f0f                 call    _objc_msgSendSuper
F00C9D44: d427bff4                 st      %o2, [%fp+var_C]
F00C9D48: 81c7e008                 ret
F00C9D4C: 91e80008                 restore %g0, %o0, %o0
