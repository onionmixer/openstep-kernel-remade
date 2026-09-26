F008C530: 9de3bf98                 save    %sp, -0x68, %sp
F008C534: 053c04d0                 sethi   %hi(_active_threads), %g2
F008C538: c400a260                 ld      [%g2+%lo(_active_threads)], %g2
F008C53C: c400a00c                 ld      [%g2+0xC], %g2
F008C540: f000a00c                 ld      [%g2+0xC], %i0
F008C544: 81c7e008                 ret
F008C548: 81e80000                 restore
