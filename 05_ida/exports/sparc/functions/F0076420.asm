F0076420: 9de3bf98                 save    %sp, -0x68, %sp
F0076424: 053c04d0                 sethi   %hi(_active_threads), %g2
F0076428: f000a260                 ld      [%g2+%lo(_active_threads)], %i0
F007642C: 81c7e008                 ret
F0076430: 81e80000                 restore
