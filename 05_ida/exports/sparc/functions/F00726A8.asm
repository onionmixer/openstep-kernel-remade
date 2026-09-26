F00726A8: 9de3bf98                 save    %sp, -0x68, %sp
F00726AC: 053c04d0                 sethi   %hi(_active_threads), %g2
F00726B0: c400a260                 ld      [%g2+%lo(_active_threads)], %g2
F00726B4: f000a044                 ld      [%g2+0x44], %i0
F00726B8: 81c7e008                 ret
F00726BC: 81e80000                 restore
