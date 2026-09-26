F00A1508: 9de3bf98                 save    %sp, -0x68, %sp
F00A150C: 073c04f78610e270         set     _pmap_info, %g3
F00A1514: b00e2007                 and     %i0, 7, %i0
F00A1518: c400e0c4                 ld      [%g3+0xC4], %g2
F00A151C: b12e2002                 sll     %i0, 2, %i0
F00A1520: 8400a001                 inc     %g2
F00A1524: c420e0c4                 st      %g2, [%g3+0xC4]
F00A1528: 053c04638410a1f8         set     unk_F0118DF8, %g2
F00A1530: f0060002                 ld      [%i0+%g2], %i0
F00A1534: 81c7e008                 ret
F00A1538: 81e80000                 restore
