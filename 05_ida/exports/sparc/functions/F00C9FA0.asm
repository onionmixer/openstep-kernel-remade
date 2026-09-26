F00C9FA0: 9de3bf90                 save    %sp, -0x70, %sp
F00C9FA4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9FA8: e0062004                 ld      [%i0+4], %l0
F00C9FAC: 133c0504                 sethi   %hi(paInit), %o1
F00C9FB0: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C9FB4: 153c0508                 sethi   %hi(stru_F0141FFC.super_class), %o2
F00C9FB8: d402a000                 ld      [%o2+%lo(stru_F0141FFC.super_class)], %o2
F00C9FBC: f027bff0                 st      %i0, [%fp+var_10]
F00C9FC0: 40009e6f                 call    _objc_msgSendSuper
F00C9FC4: d427bff4                 st      %o2, [%fp+var_C]
F00C9FC8: 80a42000                 cmp     %l0, 0
F00C9FCC: 32800009                 bne,a   loc_F00C9FF0
F00C9FD0: d0040000                 ld      [%l0], %o0
F00C9FD4: 7ffe7827                 call    _kalloc
F00C9FD8: 90102004                 mov     4, %o0
F00C9FDC: 7ffe7b40                 call    _lock_alloc
F00C9FE0: a0100008                 mov     %o0, %l0
F00C9FE4: d0240000                 st      %o0, [%l0]
F00C9FE8: e0262004                 st      %l0, [%i0+4]
F00C9FEC: d0040000                 ld      [%l0], %o0
F00C9FF0: 7ffe7b46                 call    _lock_init
F00C9FF4: 92102001                 mov     1, %o1
F00C9FF8: 81c7e008                 ret
F00C9FFC: 81e80000                 restore
