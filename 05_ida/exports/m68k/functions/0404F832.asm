0404F832: 4856                     pea     (a6)
0404F834: 2c4f                     movea.l sp,a6
0404F836: 2f0a                     move.l  a2,-(sp)
0404F838: 206e0008                 movea.l 8(a6),a0
0404F83C: 226e000c                 movea.l $C(a6),a1
0404F840: 2091                     move.l  (a1),(a0)
0404F842: 21490004                 move.l  a1,4(a0)
0404F846: 2451                     movea.l (a1),a2
0404F848: 25480004                 move.l  a0,4(a2)
0404F84C: 2288                     move.l  a0,(a1)
0404F84E: 246efffc                 movea.l -4(a6),a2
0404F852: 4e5e                     unlk    a6
0404F854: 4e75                     rts
