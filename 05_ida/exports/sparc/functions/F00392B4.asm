F00392B4: 9de3bf98                 save    %sp, -0x68, %sp
F00392B8: c6062004                 ld      [%i0+4], %g3
F00392BC: 80a0e000                 cmp     %g3, 0
F00392C0: 22800005                 be,a    loc_F00392D4
F00392C4: c4060000                 ld      [%i0], %g2
F00392C8: c400e014                 ld      [%g3+0x14], %g2
F00392CC: 1080000e                 ba      locret_F0039304
F00392D0: c4262004                 st      %g2, [%i0+4]
F00392D4: 80a0a000                 cmp     %g2, 0
F00392D8: 0280000b                 be      locret_F0039304
F00392DC: 01000000                 nop
F00392E0: c4060000                 ld      [%i0], %g2
F00392E4: c600a044                 ld      [%g2+0x44], %g3
F00392E8: c400a040                 ld      [%g2+0x40], %g2
F00392EC: 80a0e000                 cmp     %g3, 0
F00392F0: 12bffff6                 bne     loc_F00392C8
F00392F4: c4260000                 st      %g2, [%i0]
F00392F8: 80a0a000                 cmp     %g2, 0
F00392FC: 32bffffa                 bne,a   loc_F00392E4
F0039300: c4060000                 ld      [%i0], %g2
F0039304: 81c7e008                 ret
F0039308: 91e80003                 restore %g0, %g3, %o0
