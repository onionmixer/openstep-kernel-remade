0407E900: 4856                     pea     (a6)
0407E902: 2c4f                     movea.l sp,a6
0407E904: 2f0a                     move.l  a2,-(sp)
0407E906: 226e0008                 movea.l 8(a6),a1
0407E90A: 206e000c                 movea.l $C(a6),a0
0407E90E: 45f08a00                 lea     (a0,a0.l*2),a2
0407E912: 200a                     move.l  a2,d0
0407E914: eb80                     asl.l   #5,d0
0407E916: d088                     add.l   a0,d0
0407E918: 41f9040c5e78             lea     (_sd_sdd).l,a0
0407E91E: 41f00a00                 lea     (a0,d0.l*2),a0
0407E922: 2288                     move.l  a0,(a1)
0407E924: 2089                     move.l  a1,(a0)
0407E926: 72fe                     moveq   #$FFFFFFFE,d1
0407E928: c3a90008                 and.l   d1,8(a1)
0407E92C: 246efffc                 movea.l -4(a6),a2
0407E930: 4e5e                     unlk    a6
0407E932: 4e75                     rts
