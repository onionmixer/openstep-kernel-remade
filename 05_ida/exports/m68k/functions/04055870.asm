04055870: 4856                     pea     (a6)
04055872: 2c4f                     movea.l sp,a6
04055874: 42a7                     clr.l   -(sp)
04055876: 2f39040aff38             move.l  (_zone_map_size).l,-(sp)
0405587C: 4879040c2bf4             pea     (_zone_max).l
04055882: 4879040c2bf8             pea     (_zone_min).l
04055888: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0405588E: 61ff00007f74             bsr.l   _kmem_suballoc
04055894: 23c0040aff34             move.l  d0,(_zone_map).l
0405589A: 4e5e                     unlk    a6
0405589C: 4e75                     rts
