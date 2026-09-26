F00B030C: 9de3bf98                 save    %sp, -0x68, %sp
F00B0310: 053c0470                 sethi   %hi(_obp_romvec_version), %g2
F00B0314: f000a278                 ld      [%g2+%lo(_obp_romvec_version)], %i0
F00B0318: 81c7e008                 ret
F00B031C: 81e80000                 restore
