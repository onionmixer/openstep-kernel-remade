F00EAD10: 9c03bf88                 inc     -0x78, %sp
F00EAD14: c402a004                 ld      [%o2+4], %g2
F00EAD18: 80a0a000                 cmp     %g2, 0
F00EAD1C: 12800010                 bne     loc_F00EAD5C
F00EAD20: d0022014                 ld      [%o0+0x14], %o0
F00EAD24: c4028000                 ld      [%o2], %g2
F00EAD28: 80a0a000                 cmp     %g2, 0
F00EAD2C: 12800006                 bne     loc_F00EAD44
F00EAD30: 8400bfff                 inc     -1, %g2
F00EAD34: c022c000                 clr     [%o3]
F00EAD38: c0230000                 clr     [%o4]
F00EAD3C: 10800019                 ba      locret_F00EADA0
F00EAD40: 90102000                 mov     0, %o0
F00EAD44: c4228000                 st      %g2, [%o2]
F00EAD48: 8528a003                 sll     %g2, 3, %g2
F00EAD4C: c4020002                 ld      [%o0+%g2], %g2
F00EAD50: 80a0a000                 cmp     %g2, 0
F00EAD54: 02bffff4                 be      loc_F00EAD24
F00EAD58: c422a004                 st      %g2, [%o2+4]
F00EAD5C: c602a004                 ld      [%o2+4], %g3
F00EAD60: 8600ffff                 inc     -1, %g3
F00EAD64: c622a004                 st      %g3, [%o2+4]
F00EAD68: c4028000                 ld      [%o2], %g2
F00EAD6C: 8528a003                 sll     %g2, 3, %g2
F00EAD70: 84020002                 add     %o0, %g2, %g2
F00EAD74: c400a004                 ld      [%g2+4], %g2
F00EAD78: 8728e003                 sll     %g3, 3, %g3
F00EAD7C: d0008003                 ld      [%g2+%g3], %o0
F00EAD80: d023a060                 st      %o0, [%sp+0x78+var_18]
F00EAD84: 84008003                 add     %g2, %g3, %g2
F00EAD88: c400a004                 ld      [%g2+4], %g2
F00EAD8C: c423a064                 st      %g2, [%sp+0x78+var_14]
F00EAD90: d022c000                 st      %o0, [%o3]
F00EAD94: c403a064                 ld      [%sp+0x78+var_14], %g2
F00EAD98: c4230000                 st      %g2, [%o4]
F00EAD9C: 90102001                 mov     1, %o0
F00EADA0: 81c3e008                 retl
F00EADA4: 9c23bf88                 dec     -0x78, %sp
