F000DE04: 9de3bf98                 save    %sp, -0x68, %sp
F000DE08: 333c04cf                 sethi   %hi(_active_u), %i1
F000DE0C: c6062084                 ld      [%i0+0x84], %g3
F000DE10: 841661d8                 or      %i1, %lo(_active_u), %g2
F000DE14: c620a004                 st      %g3, [%g2+4]
F000DE18: c406200c                 ld      [%i0+0xC], %g2
F000DE1C: c400a038                 ld      [%g2+0x38], %g2
F000DE20: c42661d8                 st      %g2, [%i1+%lo(_active_u)]
F000DE24: 81c7e008                 ret
F000DE28: 81e80000                 restore
