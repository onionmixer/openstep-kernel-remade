0401C2CE: 4856                     pea     (a6)
0401C2D0: 2c4f                     movea.l sp,a6
0401C2D2: 2f2e0008                 move.l  8(a6),-(sp)
0401C2D6: 61ff00000924             bsr.l   _if_private
0401C2DC: 4e5e                     unlk    a6
0401C2DE: 4e75                     rts
