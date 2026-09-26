04054124: 4856                     pea     (a6)
04054126: 2c4f                     movea.l sp,a6
04054128: 2f03                     move.l  d3,-(sp)
0405412A: 2f02                     move.l  d2,-(sp)
0405412C: 242e0008                 move.l  8(a6),d2
04054130: 262e000c                 move.l  $C(a6),d3
04054134: 48780001                 pea     (1).w
04054138: 61ff0003df70             bsr.l   _clock_value
0405413E: d283                     add.l   d3,d1
04054140: d182                     addx.l  d2,d0
04054142: 242efff8                 move.l  -8(a6),d2
04054146: 262efffc                 move.l  -4(a6),d3
0405414A: 4e5e                     unlk    a6
0405414C: 4e75                     rts
