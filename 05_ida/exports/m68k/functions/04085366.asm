04085366: 4856                     pea     (a6)
04085368: 2c4f                     movea.l sp,a6
0408536A: 48780135                 pea     ($135).w
0408536E: 2f2e000c                 move.l  $C(a6),-(sp)
04085372: 2f2e0008                 move.l  8(a6),-(sp)
04085376: 61fffffffd96             bsr.l   sub_408510E
0408537C: 4e5e                     unlk    a6
0408537E: 4e75                     rts
