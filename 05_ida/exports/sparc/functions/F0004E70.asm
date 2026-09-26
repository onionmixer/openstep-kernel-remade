F0004E70: 2b3fbff4                 sethi   -0x1003000, %l5
F0004E74: c2054000                 ld      [%l5], %g1
F0004E78: 053c04bc                 sethi   %hi(_clk_intr), %g2
F0004E7C: c600a1f8                 ld      [%g2+%lo(_clk_intr)], %g3
F0004E80: 8600e001                 inc     %g3
F0004E84: c620a1f8                 st      %g3, [%g2+%lo(_clk_intr)]
F0004E88: d005a004                 ld      [%l6+4], %o0
F0004E8C: 40024a2e                 call    _sparc_hardclock
F0004E90: d205a000                 ld      [%l6], %o1
F0004E94: 30bffb00                 ba,a    loc_F0003A94
