F00EB1C4: 9c03bf90                 inc     -0x70, %sp
F00EB1C8: c4022008                 ld      [%o0+8], %g2
F00EB1CC: 80a28002                 cmp     %o2, %g2
F00EB1D0: 1a800005                 bcc     loc_F00EB1E4
F00EB1D4: 852aa002                 sll     %o2, 2, %g2
F00EB1D8: c6022004                 ld      [%o0+4], %g3
F00EB1DC: 10800003                 ba      locret_F00EB1E8
F00EB1E0: d000c002                 ld      [%g3+%g2], %o0
F00EB1E4: 90102000                 mov     0, %o0
F00EB1E8: 81c3e008                 retl
F00EB1EC: 9c23bf90                 dec     -0x70, %sp
