0409178E: 4856                     pea     (a6)
04091790: 2c4f                     movea.l sp,a6
04091792: 2f02                     move.l  d2,-(sp)
04091794: 122e000b                 move.b  $B(a6),d1
04091798: e9c10604                 bfextu  d1{24:4},d0
0409179C: 2040                     movea.l d0,a0
0409179E: 41f00c00                 lea     (a0,d0.l*4),a0
040917A2: 2008                     move.l  a0,d0
040917A4: 740f                     moveq   #$F,d2
040917A6: c282                     and.l   d2,d1
040917A8: 2041                     movea.l d1,a0
040917AA: 41f00a00                 lea     (a0,d0.l*2),a0
040917AE: 2008                     move.l  a0,d0
040917B0: 242efffc                 move.l  -4(a6),d2
040917B4: 4e5e                     unlk    a6
040917B6: 4e75                     rts
