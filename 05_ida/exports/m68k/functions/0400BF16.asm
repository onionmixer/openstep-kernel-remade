0400BF16: 4856                     pea     (a6)
0400BF18: 2c4f                     movea.l sp,a6
0400BF1A: 222e000c                 move.l  $C(a6),d1
0400BF1E: 202e0008                 move.l  8(a6),d0
0400BF22: b280                     cmp.l   d0,d1
0400BF24: 6c02                     bge.s   loc_400BF28
0400BF26: 2001                     move.l  d1,d0
0400BF28: 4e5e                     unlk    a6
0400BF2A: 4e75                     rts
