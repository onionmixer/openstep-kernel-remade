0401C2BC: 4856                     pea     (a6)
0401C2BE: 2c4f                     movea.l sp,a6
0401C2C0: 2f2e0008                 move.l  8(a6),-(sp)
0401C2C4: 61ff00000936             bsr.l   _if_private
0401C2CA: 4e5e                     unlk    a6
0401C2CC: 4e75                     rts
