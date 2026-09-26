0405FFEA: 4856                     pea     (a6)
0405FFEC: 2c4f                     movea.l sp,a6
0405FFEE: 206e0008                 movea.l 8(a6),a0
0405FFF2: 216e000c0024             move.l  $C(a6),$24(a0)
0405FFF8: 216e00100028             move.l  $10(a6),$28(a0)
0405FFFE: 4e5e                     unlk    a6
04060000: 4e75                     rts
