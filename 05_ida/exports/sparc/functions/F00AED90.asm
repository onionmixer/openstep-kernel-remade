F00AED90: 9de3bf98                 save    %sp, -0x68, %sp
F00AED94: 053c0470                 sethi   %hi(_obp_romvec_version), %g2
F00AED98: c400a278                 ld      [%g2+%lo(_obp_romvec_version)], %g2
F00AED9C: 80a0a000                 cmp     %g2, 0
F00AEDA0: 02800006                 be      loc_F00AEDB8
F00AEDA4: 053c000c                 sethi   %hi(_romp), %g2
F00AEDA8: c400a030                 ld      [%g2+%lo(_romp)], %g2
F00AEDAC: c400a08c                 ld      [%g2+0x8C], %g2
F00AEDB0: 10800003                 ba      locret_F00AEDBC
F00AEDB4: f0008000                 ld      [%g2], %i0
F00AEDB8: b0102000                 mov     0, %i0
F00AEDBC: 81c7e008                 ret
F00AEDC0: 81e80000                 restore
