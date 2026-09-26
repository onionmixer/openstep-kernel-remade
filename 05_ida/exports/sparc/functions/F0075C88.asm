F0075C88: 9de3bf98                 save    %sp, -0x68, %sp
F0075C8C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0075C90: 400083be                 call    _splusclock
F0075C94: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0075C98: a4100008                 mov     %o0, %l2
F0075C9C: a0046020                 add     %l1, 0x20, %l0 ! ' '
F0075CA0: d0040000                 ld      [%l0], %o0
F0075CA4: 80a22000                 cmp     %o0, 0
F0075CA8: 12bffffe                 bne     loc_F0075CA0
F0075CAC: 01000000                 nop
F0075CB0: 4000847e                 call    _simple_lock_try
F0075CB4: 90100010                 mov     %l0, %o0
F0075CB8: 80a22000                 cmp     %o0, 0
F0075CBC: 02bffff9                 be      loc_F0075CA0
F0075CC0: 01000000                 nop
F0075CC4: d0046054                 ld      [%l1+0x54], %o0
F0075CC8: 80a60008                 cmp     %i0, %o0
F0075CCC: 26800002                 bl,a    loc_F0075CD4
F0075CD0: f0246054                 st      %i0, [%l1+0x54]
F0075CD4: f0246050                 st      %i0, [%l1+0x50]
F0075CD8: 90100011                 mov     %l1, %o0
F0075CDC: 7fffef1a                 call    _compute_priority
F0075CE0: 92102001                 mov     1, %o1
F0075CE4: c0246020                 clr     [%l1+0x20]
F0075CE8: 4000840f                 call    _splx
F0075CEC: 90100012                 mov     %l2, %o0
F0075CF0: 81c7e008                 ret
F0075CF4: 81e80000                 restore
