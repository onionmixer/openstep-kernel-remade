0400BF42: 4856                     pea     (a6)
0400BF44: 2c4f                     movea.l sp,a6
0400BF46: 222e000c                 move.l  $C(a6),d1
0400BF4A: 202e0008                 move.l  8(a6),d0
0400BF4E: b280                     cmp.l   d0,d1
0400BF50: 6402                     bcc.s   loc_400BF54
0400BF52: 2001                     move.l  d1,d0
0400BF54: 4e5e                     unlk    a6
0400BF56: 4e75                     rts
