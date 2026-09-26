F00EDE10: c4026004                 ld      [%o1+4], %g2
F00EDE14: 80a0a000                 cmp     %g2, 0
F00EDE18: 1280000d                 bne     loc_F00EDE4C
F00EDE1C: c602200c                 ld      [%o0+0xC], %g3
F00EDE20: c4024000                 ld      [%o1], %g2
F00EDE24: 80a0a000                 cmp     %g2, 0
F00EDE28: 02800014                 be      loc_F00EDE78
F00EDE2C: 8400bfff                 inc     -1, %g2
F00EDE30: c4224000                 st      %g2, [%o1]
F00EDE34: 8528a003                 sll     %g2, 3, %g2
F00EDE38: c400c002                 ld      [%g3+%g2], %g2
F00EDE3C: 80a0a000                 cmp     %g2, 0
F00EDE40: 02bffff8                 be      loc_F00EDE20
F00EDE44: c4226004                 st      %g2, [%o1+4]
F00EDE48: c4026004                 ld      [%o1+4], %g2
F00EDE4C: 8400bfff                 inc     -1, %g2
F00EDE50: c4226004                 st      %g2, [%o1+4]
F00EDE54: c4024000                 ld      [%o1], %g2
F00EDE58: 8528a003                 sll     %g2, 3, %g2
F00EDE5C: 8600c002                 add     %g3, %g2, %g3
F00EDE60: c400c000                 ld      [%g3], %g2
F00EDE64: 80a0a001                 cmp     %g2, 1
F00EDE68: 32800006                 bne,a   loc_F00EDE80
F00EDE6C: c4026004                 ld      [%o1+4], %g2
F00EDE70: 10800007                 ba      loc_F00EDE8C
F00EDE74: c400e004                 ld      [%g3+4], %g2
F00EDE78: 10800007                 ba      locret_F00EDE94
F00EDE7C: 90102000                 mov     0, %o0
F00EDE80: c600e004                 ld      [%g3+4], %g3
F00EDE84: 8528a002                 sll     %g2, 2, %g2
F00EDE88: c400c002                 ld      [%g3+%g2], %g2
F00EDE8C: c4228000                 st      %g2, [%o2]
F00EDE90: 90102001                 mov     1, %o0
F00EDE94: 81c3e008                 retl
F00EDE98: 01000000                 nop
