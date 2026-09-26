F00A1450: 9de3bf98                 save    %sp, -0x68, %sp
F00A1454: 073c04f78610e270         set     _pmap_info, %g3
F00A145C: c400e0bc                 ld      [%g3+0xBC], %g2
F00A1460: 8400a001                 inc     %g2
F00A1464: c420e0bc                 st      %g2, [%g3+0xBC]
F00A1468: c606600c                 ld      [%i1+0xC], %g3
F00A146C: 80a60003                 cmp     %i0, %g3
F00A1470: 12800004                 bne     loc_F00A1480
F00A1474: c4066010                 ld      [%i1+0x10], %g2
F00A1478: 10800003                 ba      loc_F00A1484
F00A147C: c4262004                 st      %g2, [%i0+4]
F00A1480: c420e010                 st      %g2, [%g3+0x10]
F00A1484: 80a60002                 cmp     %i0, %g2
F00A1488: 32800003                 bne,a   loc_F00A1494
F00A148C: c620a00c                 st      %g3, [%g2+0xC]
F00A1490: c6260000                 st      %g3, [%i0]
F00A1494: c4062008                 ld      [%i0+8], %g2
F00A1498: 8400bfff                 inc     -1, %g2
F00A149C: c4262008                 st      %g2, [%i0+8]
F00A14A0: 81c7e008                 ret
F00A14A4: 81e80000                 restore
