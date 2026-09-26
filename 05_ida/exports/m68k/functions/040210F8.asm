040210F8: 4856                     pea     (a6)
040210FA: 2c4f                     movea.l sp,a6
040210FC: 2f0a                     move.l  a2,-(sp)
040210FE: 206e0008                 movea.l 8(a6),a0
04021102: 226e000c                 movea.l $C(a6),a1
04021106: 21490010                 move.l  a1,$10(a0)
0402110A: 2169000c000c             move.l  $C(a1),$C(a0)
04021110: 2469000c                 movea.l $C(a1),a2
04021114: 25480010                 move.l  a0,$10(a2)
04021118: 2348000c                 move.l  a0,$C(a1)
0402111C: 246efffc                 movea.l -4(a6),a2
04021120: 4e5e                     unlk    a6
04021122: 4e75                     rts
