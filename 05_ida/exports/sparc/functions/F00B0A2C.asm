F00B0A2C: 9de3bf98                 save    %sp, -0x68, %sp
F00B0A30: c6062008                 ld      [%i0+8], %g3
F00B0A34: 80a0e000                 cmp     %g3, 0
F00B0A38: 0280000c                 be      locret_F00B0A68
F00B0A3C: b0102000                 mov     0, %i0
F00B0A40: c400e028                 ld      [%g3+0x28], %g2
F00B0A44: 80a08019                 cmp     %g2, %i1
F00B0A48: 32800004                 bne,a   loc_F00B0A58
F00B0A4C: c600e004                 ld      [%g3+4], %g3
F00B0A50: 10800006                 ba      locret_F00B0A68
F00B0A54: b0102001                 mov     1, %i0
F00B0A58: 80a0e000                 cmp     %g3, 0
F00B0A5C: 32bffffa                 bne,a   loc_F00B0A44
F00B0A60: c400e028                 ld      [%g3+0x28], %g2
F00B0A64: b0102000                 mov     0, %i0
F00B0A68: 81c7e008                 ret
F00B0A6C: 81e80000                 restore
