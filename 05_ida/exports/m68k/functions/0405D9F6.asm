0405D9F6: 4856                     pea     (a6)
0405D9F8: 2c4f                     movea.l sp,a6
0405D9FA: 2f2e0014                 move.l  $14(a6),-(sp)
0405D9FE: 2f39040c2d14             move.l  (_kernel_object).l,-(sp)
0405DA04: 48780001                 pea     (1).w
0405DA08: 2f2e0010                 move.l  $10(a6),-(sp)
0405DA0C: 2f2e000c                 move.l  $C(a6),-(sp)
0405DA10: 2f2e0008                 move.l  8(a6),-(sp)
0405DA14: 61fffffffa32             bsr.l   sub_405D448
0405DA1A: 4e5e                     unlk    a6
0405DA1C: 4e75                     rts
