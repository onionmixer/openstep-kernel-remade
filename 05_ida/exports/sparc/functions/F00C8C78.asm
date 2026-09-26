F00C8C78: 9de3bf90                 save    %sp, -0x70, %sp
F00C8C7C: e0062010                 ld      [%i0+0x10], %l0
F00C8C80: d2042004                 ld      [%l0+4], %o1
F00C8C84: 80a26000                 cmp     %o1, 0
F00C8C88: 22800006                 be,a    loc_F00C8CA0
F00C8C8C: d204200c                 ld      [%l0+0xC], %o1
F00C8C90: d0040000                 ld      [%l0], %o0
F00C8C94: 7ffff4ac                 call    _IOFree
F00C8C98: 932a6002                 sll     %o1, 2, %o1
F00C8C9C: d204200c                 ld      [%l0+0xC], %o1
F00C8CA0: 80a26000                 cmp     %o1, 0
F00C8CA4: 02800006                 be      loc_F00C8CBC
F00C8CA8: 90100010                 mov     %l0, %o0
F00C8CAC: d0042008                 ld      [%l0+8], %o0
F00C8CB0: 7ffff4a5                 call    _IOFree
F00C8CB4: 932a6003                 sll     %o1, 3, %o1
F00C8CB8: 90100010                 mov     %l0, %o0
F00C8CBC: 7ffff4a2                 call    _IOFree
F00C8CC0: 92102010                 mov     0x10, %o1
F00C8CC4: d0062004                 ld      [%i0+4], %o0
F00C8CC8: 80a22000                 cmp     %o0, 0
F00C8CCC: 22800005                 be,a    loc_F00C8CE0
F00C8CD0: f027bff0                 st      %i0, [%fp+var_10]
F00C8CD4: 7fff1d9c                 call    _destroy_dev_port
F00C8CD8: 01000000                 nop
F00C8CDC: f027bff0                 st      %i0, [%fp+var_10]
F00C8CE0: 133c0507                 sethi   %hi(stru_F0141F5C.super_class), %o1
F00C8CE4: d4026360                 ld      [%o1+%lo(stru_F0141F5C.super_class)], %o2
F00C8CE8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C8CEC: 133c0503                 sethi   %hi(paFree), %o1
F00C8CF0: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C8CF4: 4000a322                 call    _objc_msgSendSuper
F00C8CF8: d427bff4                 st      %o2, [%fp+var_C]
F00C8CFC: 81c7e008                 ret
F00C8D00: 91e80008                 restore %g0, %o0, %o0
