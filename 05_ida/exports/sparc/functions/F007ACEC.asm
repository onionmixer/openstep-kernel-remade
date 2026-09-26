F007ACEC: 9de3bf98                 save    %sp, -0x68, %sp
F007ACF0: d0060000                 ld      [%i0], %o0
F007ACF4: d2062008                 ld      [%i0+8], %o1
F007ACF8: 153c04d0                 sethi   %hi(_page_mask), %o2
F007ACFC: d402a0d8                 ld      [%o2+%lo(_page_mask)], %o2
F007AD00: 92224008                 sub     %o1, %o0, %o1
F007AD04: 9202400a                 add     %o1, %o2, %o1
F007AD08: 7fffb526                 call    _kfree
F007AD0C: 922a400a                 bclr    %o2, %o1
F007AD10: c0262004                 clr     [%i0+4]
F007AD14: c0262008                 clr     [%i0+8]
F007AD18: c0260000                 clr     [%i0]
F007AD1C: 81c7e008                 ret
F007AD20: 81e80000                 restore
