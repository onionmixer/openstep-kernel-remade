0404F77A: 4856                     pea     (a6)
0404F77C: 2c4f                     movea.l sp,a6
0404F77E: 2f0a                     move.l  a2,-(sp)
0404F780: 206e0008                 movea.l 8(a6),a0
0404F784: 226e000c                 movea.l $C(a6),a1
0404F788: 2290                     move.l  (a0),(a1)
0404F78A: 23480004                 move.l  a0,4(a1)
0404F78E: 2451                     movea.l (a1),a2
0404F790: 25490004                 move.l  a1,4(a2)
0404F794: 2089                     move.l  a1,(a0)
0404F796: 246efffc                 movea.l -4(a6),a2
0404F79A: 4e5e                     unlk    a6
0404F79C: 4e75                     rts
