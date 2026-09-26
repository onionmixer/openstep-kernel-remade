F0073F94: 9de3bf98                 save    %sp, -0x68, %sp
F0073F98: 053c04d0                 sethi   %hi(_active_threads), %g2
F0073F9C: c400a260                 ld      [%g2+%lo(_active_threads)], %g2
F0073FA0: c400a00c                 ld      [%g2+0xC], %g2
F0073FA4: f000a00c                 ld      [%g2+0xC], %i0
F0073FA8: 81c7e008                 ret
F0073FAC: 81e80000                 restore
