F003D1AC: 9de3bf98                 save    %sp, -0x68, %sp
F003D1B0: c4060000                 ld      [%i0], %g2
F003D1B4: 80a0a000                 cmp     %g2, 0
F003D1B8: 12800015                 bne     locret_F003D20C
F003D1BC: 353c0434                 sethi   %hi(_rpfreelist), %i2
F003D1C0: c606a048                 ld      [%i2+%lo(_rpfreelist)], %g3
F003D1C4: 80a0e000                 cmp     %g3, 0
F003D1C8: 32800005                 bne,a   loc_F003D1DC
F003D1CC: c6260000                 st      %g3, [%i0]
F003D1D0: f0260000                 st      %i0, [%i0]
F003D1D4: 10800009                 ba      loc_F003D1F8
F003D1D8: f0262004                 st      %i0, [%i0+4]
F003D1DC: c400e004                 ld      [%g3+4], %g2
F003D1E0: c4262004                 st      %g2, [%i0+4]
F003D1E4: c400e004                 ld      [%g3+4], %g2
F003D1E8: 80a66000                 cmp     %i1, 0
F003D1EC: f0208000                 st      %i0, [%g2]
F003D1F0: 02800003                 be      loc_F003D1FC
F003D1F4: f020e004                 st      %i0, [%g3+4]
F003D1F8: f026a048                 st      %i0, [%i2+0x48]
F003D1FC: 073c04ea                 sethi   %hi(_rnfree), %g3
F003D200: c400e270                 ld      [%g3+%lo(_rnfree)], %g2
F003D204: 8400a001                 inc     %g2
F003D208: c420e270                 st      %g2, [%g3+%lo(_rnfree)]
F003D20C: 81c7e008                 ret
F003D210: 81e80000                 restore
