F00CA7E4: 9de3bf90                 save    %sp, -0x70, %sp
F00CA7E8: 7ffd85e6                 call    _if_detach
F00CA7EC: d0062004                 ld      [%i0+4], %o0
F00CA7F0: f027bff0                 st      %i0, [%fp+var_10]
F00CA7F4: 133c0508                 sethi   %hi(stru_F014204C.super_class), %o1
F00CA7F8: d4026050                 ld      [%o1+%lo(stru_F014204C.super_class)], %o2
F00CA7FC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CA800: 133c0503                 sethi   %hi(paFree), %o1
F00CA804: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00CA808: 40009c5d                 call    _objc_msgSendSuper
F00CA80C: d427bff4                 st      %o2, [%fp+var_C]
F00CA810: 81c7e008                 ret
F00CA814: 91e80008                 restore %g0, %o0, %o0
