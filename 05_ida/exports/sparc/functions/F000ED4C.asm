F000ED4C: 9de3bf98                 save    %sp, -0x68, %sp
F000ED50: 80a62000                 cmp     %i0, 0
F000ED54: 32800004                 bne,a   loc_F000ED64
F000ED58: c406200c                 ld      [%i0+0xC], %g2
F000ED5C: 10800004                 ba      locret_F000ED6C
F000ED60: b0102000                 mov     0, %i0
F000ED64: c400a038                 ld      [%g2+0x38], %g2
F000ED68: f0008000                 ld      [%g2], %i0
F000ED6C: 81c7e008                 ret
F000ED70: 81e80000                 restore
