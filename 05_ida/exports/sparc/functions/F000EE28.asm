F000EE28: 9de3bf98                 save    %sp, -0x68, %sp
F000EE2C: 053c04cf                 sethi   %hi(_active_u), %g2
F000EE30: c600a1d8                 ld      [%g2+%lo(_active_u)], %g3
F000EE34: 053c04d0                 sethi   %hi(_active_threads), %g2
F000EE38: c400a260                 ld      [%g2+%lo(_active_threads)], %g2
F000EE3C: c600c000                 ld      [%g3], %g3
F000EE40: f000a084                 ld      [%g2+0x84], %i0
F000EE44: c450e030                 ldsh    [%g3+0x30], %g2
F000EE48: c4262030                 st      %g2, [%i0+0x30]
F000EE4C: c450e032                 ldsh    [%g3+0x32], %g2
F000EE50: c4262034                 st      %g2, [%i0+0x34]
F000EE54: 81c7e008                 ret
F000EE58: 81e80000                 restore
