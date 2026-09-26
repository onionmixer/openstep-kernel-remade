04030042: 4856                     pea     (a6)
04030044: 2c4f                     movea.l sp,a6
04030046: 2f2e000c                 move.l  $C(a6),-(sp)
0403004A: 2f2e0008                 move.l  8(a6),-(sp)
0403004E: 61fffffffdbc             bsr.l   _xdr_long
04030054: 4e5e                     unlk    a6
04030056: 4e75                     rts
