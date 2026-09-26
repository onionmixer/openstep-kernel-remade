F008A4BC: 9de3bf98                 save    %sp, -0x68, %sp
F008A4C0: 10800004                 ba      loc_F008A4D0
F008A4C4: e0062004                 ld      [%i0+4], %l0
F008A4C8: 7ffffa70                 call    _vm_page_remove
F008A4CC: d0040000                 ld      [%l0], %o0
F008A4D0: d0040000                 ld      [%l0], %o0
F008A4D4: 80a40008                 cmp     %l0, %o0
F008A4D8: 12bffffc                 bne     loc_F008A4C8
F008A4DC: 01000000                 nop
F008A4E0: d0062008                 ld      [%i0+8], %o0
F008A4E4: 7fff772f                 call    _kfree
F008A4E8: d206200c                 ld      [%i0+0xC], %o1
F008A4EC: 81c7e008                 ret
F008A4F0: 81e80000                 restore
