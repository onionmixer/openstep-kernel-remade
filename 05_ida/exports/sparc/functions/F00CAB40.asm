F00CAB40: 9de3bf90                 save    %sp, -0x70, %sp
F00CAB44: c406200c                 ld      [%i0+0xC], %g2
F00CAB48: 80a0a000                 cmp     %g2, 0
F00CAB4C: 0280000c                 be      loc_F00CAB7C
F00CAB50: 8400bfff                 inc     -1, %g2
F00CAB54: f2062004                 ld      [%i0+4], %i1
F00CAB58: c6064000                 ld      [%i1], %g3
F00CAB5C: 80a0a000                 cmp     %g2, 0
F00CAB60: c6262004                 st      %g3, [%i0+4]
F00CAB64: 12800004                 bne     loc_F00CAB74
F00CAB68: c426200c                 st      %g2, [%i0+0xC]
F00CAB6C: c0262008                 clr     [%i0+8]
F00CAB70: c0262004                 clr     [%i0+4]
F00CAB74: 10800003                 ba      locret_F00CAB80
F00CAB78: c0264000                 clr     [%i1]
F00CAB7C: b2102000                 mov     0, %i1
F00CAB80: 81c7e008                 ret
F00CAB84: 91e80019                 restore %g0, %i1, %o0
