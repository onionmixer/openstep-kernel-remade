F0073F7C: 9de3bf98                 save    %sp, -0x68, %sp
F0073F80: 053c04d0                 sethi   %hi(_active_threads), %g2
F0073F84: c400a260                 ld      [%g2+%lo(_active_threads)], %g2
F0073F88: f000a00c                 ld      [%g2+0xC], %i0
F0073F8C: 81c7e008                 ret
F0073F90: 81e80000                 restore
