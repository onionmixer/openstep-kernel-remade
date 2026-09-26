F000ED74: 9de3bf98                 save    %sp, -0x68, %sp
F000ED78: 80a62000                 cmp     %i0, 0
F000ED7C: 32800004                 bne,a   loc_F000ED8C
F000ED80: c406200c                 ld      [%i0+0xC], %g2
F000ED84: 10800003                 ba      locret_F000ED90
F000ED88: b0102000                 mov     0, %i0
F000ED8C: f000a038                 ld      [%g2+0x38], %i0
F000ED90: 81c7e008                 ret
F000ED94: 81e80000                 restore
