0404DFD6: 4856                     pea     (a6)
0404DFD8: 2c4f                     movea.l sp,a6
0404DFDA: 206e0008                 movea.l 8(a6),a0
0404DFDE: 2050                     movea.l (a0),a0
0404DFE0: 4aae000c                 tst.l   $C(a6)
0404DFE4: 56c1                     sne     d1
0404DFE6: 49c1                     extb.l  d1
0404DFE8: 4481                     neg.l   d1
0404DFEA: 10280034                 move.b  $34(a0),d0
0404DFEE: efc01681                 bfins   d1,d0{26:1}
0404DFF2: 11400034                 move.b  d0,$34(a0)
0404DFF6: 4e5e                     unlk    a6
0404DFF8: 4e75                     rts
