F004FB6C: 9de3bf98                 save    %sp, -0x68, %sp
F004FB70: 80a66000                 cmp     %i1, 0
F004FB74: 0280000d                 be      locret_F004FBA8
F004FB78: 01000000                 nop
F004FB7C: c6062018                 ld      [%i0+0x18], %g3
F004FB80: 80a0e000                 cmp     %g3, 0
F004FB84: 32800005                 bne,a   loc_F004FB98
F004FB88: c400e018                 ld      [%g3+0x18], %g2
F004FB8C: 10800007                 ba      locret_F004FBA8
F004FB90: f2262018                 st      %i1, [%i0+0x18]
F004FB94: c400e018                 ld      [%g3+0x18], %g2
F004FB98: 80a0a000                 cmp     %g2, 0
F004FB9C: 32bffffe                 bne,a   loc_F004FB94
F004FBA0: c600e018                 ld      [%g3+0x18], %g3
F004FBA4: f220e018                 st      %i1, [%g3+0x18]
F004FBA8: 81c7e008                 ret
F004FBAC: 81e80000                 restore
