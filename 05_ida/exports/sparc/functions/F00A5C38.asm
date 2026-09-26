F00A5C38: 9de3bf98                 save    %sp, -0x68, %sp! int
F00A5C3C: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A5C40: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00A5C44: 7ffd7cae                 call    _flush_user_windows
F00A5C48: e6022028                 ld      [%o0+0x28], %l3
F00A5C4C: e804e230                 ld      [%l3+0x230], %l4
F00A5C50: 80a52000                 cmp     %l4, 0
F00A5C54: 0480002b                 ble     locret_F00A5D00
F00A5C58: 912d2006                 sll     %l4, 6, %o0
F00A5C5C: b0022010                 add     %o0, 0x10, %i0
F00A5C60: 912d2002                 sll     %l4, 2, %o0
F00A5C64: ae020013                 add     %o0, %l3, %l7
F00A5C68: b0063fc0                 inc     -0x40, %i0
F00A5C6C: ae05fffc                 inc     -4, %l7
F00A5C70: d205e210                 ld      [%l7+0x210], %o1! int
F00A5C74: a8053fff                 inc     -1, %l4
F00A5C78: 808a6007                 btst    7, %o1
F00A5C7C: 1280001e                 bne     loc_F00A5CF4
F00A5C80: ad2d2002                 sll     %l4, 2, %l6
F00A5C84: 9004c018                 add     %l3, %i0, %o0! int
F00A5C88: 7fffc911                 call    _copyout
F00A5C8C: 94102040                 mov     0x40, %o2 ! '@'
F00A5C90: 80a22000                 cmp     %o0, 0
F00A5C94: 12800018                 bne     loc_F00A5CF4
F00A5C98: a12d2006                 sll     %l4, 6, %l0
F00A5C9C: d004e230                 ld      [%l3+0x230], %o0
F00A5CA0: aa100014                 mov     %l4, %l5
F00A5CA4: 90023fff                 inc     -1, %o0
F00A5CA8: 80a50008                 cmp     %l4, %o0
F00A5CAC: 16800012                 bge     loc_F00A5CF4
F00A5CB0: d024e230                 st      %o0, [%l3+0x230]
F00A5CB4: a4042010                 add     %l0, 0x10, %l2
F00A5CB8: a2042050                 add     %l0, 0x50, %l1 ! 'P'
F00A5CBC: a0058013                 add     %l6, %l3, %l0
F00A5CC0: 9004c011                 add     %l3, %l1, %o0! void *
F00A5CC4: 9204c012                 add     %l3, %l2, %o1! void *
F00A5CC8: 94102040                 mov     0x40, %o2 ! '@'! size_t
F00A5CCC: a404a040                 inc     0x40, %l2 ! '@'
F00A5CD0: a2046040                 inc     0x40, %l1 ! '@'
F00A5CD4: d6042214                 ld      [%l0+0x214], %o3
F00A5CD8: aa056001                 inc     %l5
F00A5CDC: 7fffbb8d                 call    _bcopy
F00A5CE0: d6242210                 st      %o3, [%l0+0x210]
F00A5CE4: d004e230                 ld      [%l3+0x230], %o0
F00A5CE8: 80a54008                 cmp     %l5, %o0
F00A5CEC: 06bffff5                 bl      loc_F00A5CC0
F00A5CF0: a0042004                 inc     4, %l0
F00A5CF4: 80a52000                 cmp     %l4, 0
F00A5CF8: 34bfffdd                 bg,a    loc_F00A5C6C
F00A5CFC: b0063fc0                 inc     -0x40, %i0
F00A5D00: 81c7e008                 ret
F00A5D04: 81e80000                 restore
