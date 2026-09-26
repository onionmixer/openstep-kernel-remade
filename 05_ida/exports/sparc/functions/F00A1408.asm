F00A1408: 9de3bf98                 save    %sp, -0x68, %sp
F00A140C: 073c04f78610e270         set     _pmap_info, %g3
F00A1414: c400e0b8                 ld      [%g3+0xB8], %g2
F00A1418: 8400a001                 inc     %g2
F00A141C: c420e0b8                 st      %g2, [%g3+0xB8]
F00A1420: c6060000                 ld      [%i0], %g3
F00A1424: c400e00c                 ld      [%g3+0xC], %g2
F00A1428: 80a60002                 cmp     %i0, %g2
F00A142C: 32800003                 bne,a   loc_F00A1438
F00A1430: f020a010                 st      %i0, [%g2+0x10]
F00A1434: f0262004                 st      %i0, [%i0+4]
F00A1438: c4260000                 st      %g2, [%i0]
F00A143C: c4062008                 ld      [%i0+8], %g2
F00A1440: 8400bfff                 inc     -1, %g2
F00A1444: c4262008                 st      %g2, [%i0+8]
F00A1448: 81c7e008                 ret
F00A144C: 91e80003                 restore %g0, %g3, %o0
