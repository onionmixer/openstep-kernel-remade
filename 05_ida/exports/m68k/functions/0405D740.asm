0405D740: 4856                     pea     (a6)
0405D742: 2c4f                     movea.l sp,a6
0405D744: 2f02                     move.l  d2,-(sp)
0405D746: 242e000c                 move.l  $C(a6),d2
0405D74A: 2202                     move.l  d2,d1
0405D74C: d2ae0010                 add.l   $10(a6),d1
0405D750: 2039040b59dc             move.l  (_page_mask).l,d0
0405D756: d280                     add.l   d0,d1
0405D758: 4680                     not.l   d0
0405D75A: c280                     and.l   d0,d1
0405D75C: 2f01                     move.l  d1,-(sp)
0405D75E: c480                     and.l   d0,d2
0405D760: 2f02                     move.l  d2,-(sp)
0405D762: 2f2e0008                 move.l  8(a6),-(sp)
0405D766: 61ff00001368             bsr.l   _vm_map_remove
0405D76C: 242efffc                 move.l  -4(a6),d2
0405D770: 4e5e                     unlk    a6
0405D772: 4e75                     rts
