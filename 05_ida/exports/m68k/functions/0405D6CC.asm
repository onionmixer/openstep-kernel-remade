0405D6CC: 4856                     pea     (a6)
0405D6CE: 2c4f                     movea.l sp,a6
0405D6D0: 48780001                 pea     (1).w
0405D6D4: 2f39040c2d14             move.l  (_kernel_object).l,-(sp)
0405D6DA: 48780001                 pea     (1).w
0405D6DE: 2f2e0010                 move.l  $10(a6),-(sp)
0405D6E2: 2f2e000c                 move.l  $C(a6),-(sp)
0405D6E6: 2f2e0008                 move.l  8(a6),-(sp)
0405D6EA: 61fffffffd5c             bsr.l   sub_405D448
0405D6F0: 4e5e                     unlk    a6
0405D6F2: 4e75                     rts
