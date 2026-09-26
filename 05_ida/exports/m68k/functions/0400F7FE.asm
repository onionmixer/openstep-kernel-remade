0400F7FE: 4856                     pea     (a6)
0400F800: 2c4f                     movea.l sp,a6
0400F802: 2f0a                     move.l  a2,-(sp)
0400F804: 2f02                     move.l  d2,-(sp)
0400F806: 246e0008                 movea.l 8(a6),a2
0400F80A: 242e000c                 move.l  $C(a6),d2
0400F80E: 600e                     bra.s   loc_400F81E
0400F810: 2f02                     move.l  d2,-(sp)
0400F812: 49c0                     extb.l  d0
0400F814: 2f00                     move.l  d0,-(sp)
0400F816: 61fffffff0da             bsr.l   _ttyoutput
0400F81C: 504f                     addq.w  #8,sp
0400F81E: 101a                     move.b  (a2)+,d0
0400F820: 66ee                     bne.s   loc_400F810
0400F822: 242efff8                 move.l  -8(a6),d2
0400F826: 246efffc                 movea.l -4(a6),a2
0400F82A: 4e5e                     unlk    a6
0400F82C: 4e75                     rts
