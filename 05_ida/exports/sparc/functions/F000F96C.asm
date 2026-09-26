F000F96C: 9de3bf98                 save    %sp, -0x68, %sp
F000F970: 053c04d0                 sethi   %hi(_active_threads), %g2
F000F974: c400a260                 ld      [%g2+%lo(_active_threads)], %g2
F000F978: c400a00c                 ld      [%g2+0xC], %g2
F000F97C: c400a038                 ld      [%g2+0x38], %g2
F000F980: c4008000                 ld      [%g2], %g2
F000F984: 80a0a000                 cmp     %g2, 0
F000F988: 12800004                 bne     loc_F000F998
F000F98C: 053c04cf                 sethi   -0xFECC400, %g2
F000F990: 10800011                 ba      locret_F000F9D4
F000F994: b0102000                 mov     0, %i0
F000F998: f200a1d8                 ld      [%g2+0x1D8], %i1
F000F99C: c606601c                 ld      [%i1+0x1C], %g3
F000F9A0: c650e002                 ldsh    [%g3+2], %g3
F000F9A4: 80a0e000                 cmp     %g3, 0
F000F9A8: 02800007                 be      loc_F000F9C4
F000F9AC: 8410a1d8                 bset    0x1D8, %g2
F000F9B0: c600a004                 ld      [%g2+4], %g3
F000F9B4: b0102000                 mov     0, %i0
F000F9B8: 84102001                 mov     1, %g2
F000F9BC: 10800006                 ba      locret_F000F9D4
F000F9C0: c428e038                 stb     %g2, [%g3+0x38]
F000F9C4: c4166240                 lduh    [%i1+0x240], %g2
F000F9C8: b0102001                 mov     1, %i0
F000F9CC: 8410a002                 bset    2, %g2
F000F9D0: c4366240                 sth     %g2, [%i1+0x240]
F000F9D4: 81c7e008                 ret
F000F9D8: 81e80000                 restore
