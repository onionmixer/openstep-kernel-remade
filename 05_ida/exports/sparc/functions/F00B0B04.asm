F00B0B04: 9de3bf98                 save    %sp, -0x68, %sp
F00B0B08: 053c0474b010a2a0         set     _av_opstab, %i0
F00B0B10: c4062004                 ld      [%i0+4], %g2
F00B0B14: 80a0a000                 cmp     %g2, 0
F00B0B18: 02800009                 be      loc_F00B0B3C
F00B0B1C: 86100018                 mov     %i0, %g3
F00B0B20: 8600e008                 inc     8, %g3
F00B0B24: c6260000                 st      %g3, [%i0]
F00B0B28: b0100003                 mov     %g3, %i0
F00B0B2C: c4062004                 ld      [%i0+4], %g2
F00B0B30: 80a0a000                 cmp     %g2, 0
F00B0B34: 12bffffc                 bne     loc_F00B0B24
F00B0B38: 8600e008                 inc     8, %g3
F00B0B3C: 073c0470                 sethi   %hi(_dev_opslist), %g3
F00B0B40: 053c04748410a2a0         set     _av_opstab, %g2
F00B0B48: c420e3d0                 st      %g2, [%g3+%lo(_dev_opslist)]
F00B0B4C: 81c7e008                 ret
F00B0B50: 81e80000                 restore
