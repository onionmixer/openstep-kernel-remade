F00E9FA4: 9de3bf90                 save    %sp, -0x70, %sp
F00E9FA8: f027bff0                 st      %i0, [%fp+var_10]
F00E9FAC: 113c0508                 sethi   %hi(stru_F014236C.super_class), %o0! objc_super *
F00E9FB0: 9410001a                 mov     %i2, %o2
F00E9FB4: 9610001b                 mov     %i3, %o3
F00E9FB8: d2022370                 ld      [%o0+%lo(stru_F014236C.super_class)], %o1
F00E9FBC: 9810001c                 mov     %i4, %o4
F00E9FC0: d227bff4                 st      %o1, [%fp+var_C]
F00E9FC4: 133c0504                 sethi   %hi(paSetcharvaluesF_0), %o1
F00E9FC8: d20262d8                 ld      [%o1+%lo(paSetcharvaluesF_0)], %o1! SEL
F00E9FCC: 40001e6c                 call    _objc_msgSendSuper
F00E9FD0: 9007bff0                 add     %fp, var_10, %o0
F00E9FD4: 81c7e008                 ret
F00E9FD8: 91e80008                 restore %g0, %o0, %o0
