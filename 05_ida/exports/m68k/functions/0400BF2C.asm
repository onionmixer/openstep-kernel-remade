0400BF2C: 4856                     pea     (a6)
0400BF2E: 2c4f                     movea.l sp,a6
0400BF30: 222e000c                 move.l  $C(a6),d1
0400BF34: 202e0008                 move.l  8(a6),d0
0400BF38: b280                     cmp.l   d0,d1
0400BF3A: 6f02                     ble.s   loc_400BF3E
0400BF3C: 2001                     move.l  d1,d0
0400BF3E: 4e5e                     unlk    a6
0400BF40: 4e75                     rts
