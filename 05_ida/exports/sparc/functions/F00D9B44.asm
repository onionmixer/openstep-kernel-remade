F00D9B44: 9de3bf90                 save    %sp, -0x70, %sp
F00D9B48: c4062148                 ld      [%i0+0x148], %g2
F00D9B4C: 80a0a001                 cmp     %g2, 1
F00D9B50: 2280000c                 be,a    locret_F00D9B80
F00D9B54: b010225a                 mov     0x25A, %i0
F00D9B58: 0a800007                 bcs     loc_F00D9B74
F00D9B5C: 80a0a002                 cmp     %g2, 2
F00D9B60: 02800007                 be      loc_F00D9B7C
F00D9B64: 80a0a003                 cmp     %g2, 3
F00D9B68: 22800006                 be,a    locret_F00D9B80
F00D9B6C: b0102259                 mov     0x259, %i0
F00D9B70: 30800004                 ba,a    locret_F00D9B80
F00D9B74: 10800003                 ba      locret_F00D9B80
F00D9B78: b0102258                 mov     0x258, %i0
F00D9B7C: b010225b                 mov     0x25B, %i0
F00D9B80: 81c7e008                 ret
F00D9B84: 81e80000                 restore
