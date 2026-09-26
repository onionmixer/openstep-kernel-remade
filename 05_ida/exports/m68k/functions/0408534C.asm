0408534C: 4856                     pea     (a6)
0408534E: 2c4f                     movea.l sp,a6
04085350: 48780133                 pea     ($133).w
04085354: 2f2e000c                 move.l  $C(a6),-(sp)
04085358: 2f2e0008                 move.l  8(a6),-(sp)
0408535C: 61fffffffdb0             bsr.l   sub_408510E
04085362: 4e5e                     unlk    a6
04085364: 4e75                     rts
