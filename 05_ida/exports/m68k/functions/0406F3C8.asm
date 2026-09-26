0406F3C8: 4856                     pea     (a6)
0406F3CA: 2c4f                     movea.l sp,a6
0406F3CC: 1039040b6841             move.b  (byte_40B6841).l,d0
0406F3D2: 49c0                     extb.l  d0
0406F3D4: 2240                     movea.l d0,a1
0406F3D6: 43f10a00                 lea     (a1,d0.l*2),a1
0406F3DA: 2009                     move.l  a1,d0
0406F3DC: e980                     asl.l   #4,d0
0406F3DE: 41f9040ae4ac             lea     (_linesw).l,a0
0406F3E4: 2f2e000c                 move.l  $C(a6),-(sp)
0406F3E8: 4879040b67fc             pea     (_cons).l
0406F3EE: 20700808                 movea.l 8(a0,d0.l),a0
0406F3F2: 4e90                     jsr     (a0)
0406F3F4: 4e5e                     unlk    a6
0406F3F6: 4e75                     rts
