F00EEFB8: 1080000e                 ba      loc_F00EEFF0
F00EEFBC: d002200c                 ld      [%o0+0xC], %o0
F00EEFC0: c4024000                 ld      [%o1], %g2
F00EEFC4: 8528a003                 sll     %g2, 3, %g2
F00EEFC8: 86020002                 add     %o0, %g2, %g3
F00EEFCC: c4020002                 ld      [%o0+%g2], %g2
F00EEFD0: 80a0bfff                 cmp     %g2, -1
F00EEFD4: 22800008                 be,a    loc_F00EEFF4
F00EEFD8: c4024000                 ld      [%o1], %g2
F00EEFDC: c4228000                 st      %g2, [%o2]
F00EEFE0: c400e004                 ld      [%g3+4], %g2
F00EEFE4: c422c000                 st      %g2, [%o3]
F00EEFE8: 10800008                 ba      locret_F00EF008
F00EEFEC: 90102001                 mov     1, %o0
F00EEFF0: c4024000                 ld      [%o1], %g2
F00EEFF4: 8400bfff                 inc     -1, %g2
F00EEFF8: 80a0bfff                 cmp     %g2, -1
F00EEFFC: 12bffff1                 bne     loc_F00EEFC0
F00EF000: c4224000                 st      %g2, [%o1]
F00EF004: 90102000                 mov     0, %o0
F00EF008: 81c3e008                 retl
F00EF00C: 01000000                 nop
