F00AEDF4: 9de3bf98                 save    %sp, -0x68, %sp
F00AEDF8: 053c0470                 sethi   %hi(_obp_romvec_version), %g2
F00AEDFC: c400a278                 ld      [%g2+%lo(_obp_romvec_version)], %g2
F00AEE00: 80a0a000                 cmp     %g2, 0
F00AEE04: 02800006                 be      loc_F00AEE1C
F00AEE08: 053c000c                 sethi   %hi(_romp), %g2
F00AEE0C: c400a030                 ld      [%g2+%lo(_romp)], %g2
F00AEE10: c400a088                 ld      [%g2+0x88], %g2
F00AEE14: 10800003                 ba      locret_F00AEE20
F00AEE18: f0008000                 ld      [%g2], %i0
F00AEE1C: b0102000                 mov     0, %i0
F00AEE20: 81c7e008                 ret
F00AEE24: 81e80000                 restore
