F00EB5B4: 9c03bf90                 inc     -0x70, %sp
F00EB5B8: 80a2e000                 cmp     %o3, 0
F00EB5BC: 2280000b                 be,a    locret_F00EB5E8
F00EB5C0: 90102000                 mov     0, %o0
F00EB5C4: c4022008                 ld      [%o0+8], %g2
F00EB5C8: 80a28002                 cmp     %o2, %g2
F00EB5CC: 1a800006                 bcc     loc_F00EB5E4
F00EB5D0: 852aa002                 sll     %o2, 2, %g2
F00EB5D4: c6022004                 ld      [%o0+4], %g3
F00EB5D8: d0008003                 ld      [%g2+%g3], %o0
F00EB5DC: 10800003                 ba      locret_F00EB5E8
F00EB5E0: d6208003                 st      %o3, [%g2+%g3]
F00EB5E4: 90102000                 mov     0, %o0
F00EB5E8: 81c3e008                 retl
F00EB5EC: 9c23bf90                 dec     -0x70, %sp
