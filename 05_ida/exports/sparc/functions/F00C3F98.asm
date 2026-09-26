F00C3F98: 9de3bf98                 save    %sp, -0x68, %sp
F00C3F9C: 80a62000                 cmp     %i0, 0
F00C3FA0: 2280000f                 be,a    locret_F00C3FDC
F00C3FA4: b0102000                 mov     0, %i0
F00C3FA8: c406201c                 ld      [%i0+0x1C], %g2
F00C3FAC: 80a0a000                 cmp     %g2, 0
F00C3FB0: 2280000b                 be,a    locret_F00C3FDC
F00C3FB4: b0102000                 mov     0, %i0
F00C3FB8: c4008000                 ld      [%g2], %g2
F00C3FBC: 8688a07f                 andcc   %g2, 0x7F, %g3
F00C3FC0: 02800006                 be      loc_F00C3FD8
F00C3FC4: b0102001                 mov     1, %i0
F00C3FC8: c40e4003                 ldub    [%i1+%g3], %g2
F00C3FCC: 8400a001                 inc     %g2
F00C3FD0: 10800003                 ba      locret_F00C3FDC
F00C3FD4: c42e4003                 stb     %g2, [%i1+%g3]
F00C3FD8: b0102000                 mov     0, %i0
F00C3FDC: 81c7e008                 ret
F00C3FE0: 81e80000                 restore
