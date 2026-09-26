F00C9CA4: 9de3bf90                 save    %sp, -0x70, %sp
F00C9CA8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9CAC: e0062004                 ld      [%i0+4], %l0
F00C9CB0: 133c0507                 sethi   %hi(stru_F0141FAC.super_class), %o1
F00C9CB4: d40263b0                 ld      [%o1+%lo(stru_F0141FAC.super_class)], %o2
F00C9CB8: f027bff0                 st      %i0, [%fp+var_10]
F00C9CBC: 133c0504                 sethi   %hi(paInit), %o1
F00C9CC0: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C9CC4: 40009f2e                 call    _objc_msgSendSuper
F00C9CC8: d427bff4                 st      %o2, [%fp+var_C]
F00C9CCC: 80a42000                 cmp     %l0, 0
F00C9CD0: 32800009                 bne,a   loc_F00C9CF4
F00C9CD4: d0040000                 ld      [%l0], %o0
F00C9CD8: 7ffe78e6                 call    _kalloc
F00C9CDC: 90102004                 mov     4, %o0
F00C9CE0: 7ffe7bf4                 call    _simple_lock_alloc
F00C9CE4: a0100008                 mov     %o0, %l0
F00C9CE8: d0240000                 st      %o0, [%l0]
F00C9CEC: e0262004                 st      %l0, [%i0+4]
F00C9CF0: d0040000                 ld      [%l0], %o0
F00C9CF4: c0220000                 clr     [%o0]
F00C9CF8: 81c7e008                 ret
F00C9CFC: 81e80000                 restore
