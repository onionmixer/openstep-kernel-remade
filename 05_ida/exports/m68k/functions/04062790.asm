04062790: 4856                     pea     (a6)
04062792: 2c4f                     movea.l sp,a6
04062794: 206e0008                 movea.l 8(a6),a0
04062798: 5368000e                 subq.w  #1,$E(a0)
0406279C: 4e5e                     unlk    a6
0406279E: 4e75                     rts
