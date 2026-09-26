0405FA6C: 4856                     pea     (a6)
0405FA6E: 2c4f                     movea.l sp,a6
0405FA70: 2f03                     move.l  d3,-(sp)
0405FA72: 2f02                     move.l  d2,-(sp)
0405FA74: 262e0008                 move.l  8(a6),d3
0405FA78: 2f39040c320c             move.l  (_vm_object_zone).l,-(sp)
0405FA7E: 61ffffff60d6             bsr.l   _zalloc
0405FA84: 2400                     move.l  d0,d2
0405FA86: 2f02                     move.l  d2,-(sp)
0405FA88: 2f03                     move.l  d3,-(sp)
0405FA8A: 61ff00000012             bsr.l   __vm_object_allocate
0405FA90: 2002                     move.l  d2,d0
0405FA92: 242efff8                 move.l  -8(a6),d2
0405FA96: 262efffc                 move.l  -4(a6),d3
0405FA9A: 4e5e                     unlk    a6
0405FA9C: 4e75                     rts
