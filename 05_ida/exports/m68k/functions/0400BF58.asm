0400BF58: 4856                     pea     (a6)
0400BF5A: 2c4f                     movea.l sp,a6
0400BF5C: 222e000c                 move.l  $C(a6),d1
0400BF60: 202e0008                 move.l  8(a6),d0
0400BF64: b280                     cmp.l   d0,d1
0400BF66: 6302                     bls.s   loc_400BF6A
0400BF68: 2001                     move.l  d1,d0
0400BF6A: 4e5e                     unlk    a6
0400BF6C: 4e75                     rts
