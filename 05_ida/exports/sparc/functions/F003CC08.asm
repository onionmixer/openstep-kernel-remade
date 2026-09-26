F003CC08: 9de3bf98                 save    %sp, -0x68, %sp
F003CC0C: c4062024                 ld      [%i0+0x24], %g2
F003CC10: c400a00c                 ld      [%g2+0xC], %g2
F003CC14: 8088a010                 btst    0x10, %g2
F003CC18: 1280000b                 bne     loc_F003CC44
F003CC1C: c4062030                 ld      [%i0+0x30], %g2
F003CC20: c410a084                 lduh    [%g2+0x84], %g2
F003CC24: 8088a400                 btst    0x400, %g2
F003CC28: 32800007                 bne,a   loc_F003CC44
F003CC2C: c4062030                 ld      [%i0+0x30], %g2
F003CC30: 053c04cf                 sethi   %hi(_active_u), %g2
F003CC34: c400a1d8                 ld      [%g2+%lo(_active_u)], %g2
F003CC38: c400a01c                 ld      [%g2+0x1C], %g2
F003CC3C: 10800003                 ba      locret_F003CC48
F003CC40: f050a004                 ldsh    [%g2+4], %i0
F003CC44: f050a088                 ldsh    [%g2+0x88], %i0
F003CC48: 81c7e008                 ret
F003CC4C: 81e80000                 restore
