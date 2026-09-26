F00AEDC4: 9de3bf98                 save    %sp, -0x68, %sp
F00AEDC8: 053c0470                 sethi   %hi(_obp_romvec_version), %g2
F00AEDCC: c400a278                 ld      [%g2+%lo(_obp_romvec_version)], %g2
F00AEDD0: 80a0a000                 cmp     %g2, 0
F00AEDD4: 12800006                 bne     locret_F00AEDEC
F00AEDD8: b0102000                 mov     0, %i0
F00AEDDC: 053c000c                 sethi   %hi(_romp), %g2
F00AEDE0: c400a030                 ld      [%g2+%lo(_romp)], %g2
F00AEDE4: c400a080                 ld      [%g2+0x80], %g2
F00AEDE8: f0008000                 ld      [%g2], %i0
F00AEDEC: 81c7e008                 ret
F00AEDF0: 81e80000                 restore
