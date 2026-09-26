04030796: 4856                     pea     (a6)
04030798: 2c4f                     movea.l sp,a6
0403079A: 206e0008                 movea.l 8(a6),a0
0403079E: 202e000c                 move.l  $C(a6),d0
040307A2: 20ae0014                 move.l  $14(a6),(a0)
040307A6: 217c040af08e0004         move.l  #$40AF08E,4(a0)
040307AE: 21400010                 move.l  d0,$10(a0)
040307B2: 2140000c                 move.l  d0,$C(a0)
040307B6: 216e00100014             move.l  $10(a6),$14(a0)
040307BC: 4e5e                     unlk    a6
040307BE: 4e75                     rts
