0406F3F8: 4856                     pea     (a6)
0406F3FA: 2c4f                     movea.l sp,a6
0406F3FC: 1039040b6841             move.b  (byte_40B6841).l,d0
0406F402: 49c0                     extb.l  d0
0406F404: 2240                     movea.l d0,a1
0406F406: 43f10a00                 lea     (a1,d0.l*2),a1
0406F40A: 2009                     move.l  a1,d0
0406F40C: e980                     asl.l   #4,d0
0406F40E: 41f9040ae4ac             lea     (_linesw).l,a0
0406F414: 2f2e000c                 move.l  $C(a6),-(sp)
0406F418: 4879040b67fc             pea     (_cons).l
0406F41E: 2070080c                 movea.l $C(a0,d0.l),a0
0406F422: 4e90                     jsr     (a0)
0406F424: 4e5e                     unlk    a6
0406F426: 4e75                     rts
