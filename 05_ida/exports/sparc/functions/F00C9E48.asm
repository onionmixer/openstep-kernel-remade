F00C9E48: 9de3bf90                 save    %sp, -0x70, %sp
F00C9E4C: e0062004                 ld      [%i0+4], %l0
F00C9E50: 80a42000                 cmp     %l0, 0
F00C9E54: 2280000a                 be,a    loc_F00C9E7C
F00C9E58: f027bff0                 st      %i0, [%fp+var_10]
F00C9E5C: 7ffe7ba5                 call    _lock_free
F00C9E60: d0042004                 ld      [%l0+4], %o0
F00C9E64: 7ffe7b98                 call    _simple_lock_free
F00C9E68: d0040000                 ld      [%l0], %o0
F00C9E6C: 90100010                 mov     %l0, %o0
F00C9E70: 7ffe78cc                 call    _kfree
F00C9E74: 9210200c                 mov     0xC, %o1
F00C9E78: f027bff0                 st      %i0, [%fp+var_10]
F00C9E7C: 133c0507                 sethi   %hi(stru_F0141FAC.ext), %o1
F00C9E80: d40263d8                 ld      [%o1+%lo(stru_F0141FAC.ext)], %o2
F00C9E84: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9E88: 133c0503                 sethi   %hi(paFree), %o1
F00C9E8C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C9E90: 40009ebb                 call    _objc_msgSendSuper
F00C9E94: d427bff4                 st      %o2, [%fp+var_C]
F00C9E98: 81c7e008                 ret
F00C9E9C: 91e80008                 restore %g0, %o0, %o0
