F0099788: 9de3bf98                 save    %sp, -0x68, %sp
F009978C: b12e2008                 sll     %i0, 8, %i0
F0099790: b0162002                 bset    2, %i0
F0099794: 808ea001                 btst    1, %i2
F0099798: 073c04f6                 sethi   %hi(_ioptes), %g3
F009979C: 05004000                 sethi   0x1000000, %g2
F00997A0: b2064002                 add     %i1, %g2, %i1
F00997A4: b336600c                 srl     %i1, 12, %i1
F00997A8: c400e308                 ld      [%g3+%lo(_ioptes)], %g2
F00997AC: b32e6002                 sll     %i1, 2, %i1
F00997B0: 02800003                 be      loc_F00997BC
F00997B4: 86008019                 add     %g2, %i1, %g3
F00997B8: b0162004                 bset    4, %i0
F00997BC: 053c0464                 sethi   %hi(_cache), %g2
F00997C0: c400a330                 ld      [%g2+%lo(_cache)], %g2
F00997C4: 8400bffe                 inc     -2, %g2
F00997C8: 80a0a001                 cmp     %g2, 1
F00997CC: 08800008                 bleu    loc_F00997EC
F00997D0: 053c0464                 sethi   %hi(_vac), %g2
F00997D4: c400a334                 ld      [%g2+%lo(_vac)], %g2
F00997D8: 80a0a000                 cmp     %g2, 0
F00997DC: 02800005                 be      loc_F00997F0
F00997E0: 808ea002                 btst    2, %i2
F00997E4: 22800004                 be,a    locret_F00997F4
F00997E8: f020c000                 st      %i0, [%g3]
F00997EC: b0162080                 bset    0x80, %i0
F00997F0: f020c000                 st      %i0, [%g3]
F00997F4: 81c7e008                 ret
F00997F8: 81e80000                 restore
