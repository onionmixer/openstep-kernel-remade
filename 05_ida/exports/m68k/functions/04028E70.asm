04028E70: 4856                     pea     (a6)
04028E72: 2c4f                     movea.l sp,a6
04028E74: 2f0a                     move.l  a2,-(sp)
04028E76: 2f02                     move.l  d2,-(sp)
04028E78: 246e0008                 movea.l 8(a6),a2
04028E7C: 242e000c                 move.l  $C(a6),d2
04028E80: 206e0010                 movea.l $10(a6),a0
04028E84: 48780020                 pea     ($20).w
04028E88: 2f0a                     move.l  a2,-(sp)
04028E8A: 723e                     moveq   #$3E,d1 ; '>'
04028E8C: d2a8002e                 add.l   $2E(a0),d1
04028E90: 2f01                     move.l  d1,-(sp)
04028E92: 61ff00069e98             bsr.l   _bcopy
04028E98: 25420020                 move.l  d2,$20(a2)
04028E9C: 242efff8                 move.l  -8(a6),d2
04028EA0: 246efffc                 movea.l -4(a6),a2
04028EA4: 4e5e                     unlk    a6
04028EA6: 4e75                     rts
