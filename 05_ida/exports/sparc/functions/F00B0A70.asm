F00B0A70: 9de3bf98                 save    %sp, -0x68, %sp
F00B0A74: c4062008                 ld      [%i0+8], %g2
F00B0A78: 80a0a000                 cmp     %g2, 0
F00B0A7C: 12800004                 bne     loc_F00B0A8C
F00B0A80: 86100002                 mov     %g2, %g3
F00B0A84: 10800007                 ba      locret_F00B0AA0
F00B0A88: f2262008                 st      %i1, [%i0+8]
F00B0A8C: c400e004                 ld      [%g3+4], %g2
F00B0A90: 80a0a000                 cmp     %g2, 0
F00B0A94: 32bffffe                 bne,a   loc_F00B0A8C
F00B0A98: c600e004                 ld      [%g3+4], %g3
F00B0A9C: f220e004                 st      %i1, [%g3+4]
F00B0AA0: 81c7e008                 ret
F00B0AA4: 81e80000                 restore
