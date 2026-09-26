0406A9D4: 4856                     pea     (a6)
0406A9D6: 2c4f                     movea.l sp,a6
0406A9D8: 2f02                     move.l  d2,-(sp)
0406A9DA: 222e0008                 move.l  8(a6),d1
0406A9DE: 2079040c3640             movea.l (_evg).l,a0
0406A9E4: 7001                     moveq   #1,d0
0406A9E6: 7403                     moveq   #3,d2
0406A9E8: b481                     cmp.l   d1,d2
0406A9EA: 6d02                     blt.s   loc_406A9EE
0406A9EC: 2001                     move.l  d1,d0
0406A9EE: 2140001c                 move.l  d0,$1C(a0)
0406A9F2: 42a7                     clr.l   -(sp)
0406A9F4: 2f39040c3610             move.l  (_currentScreen).l,-(sp)
0406A9FA: 48780003                 pea     (3).w
0406A9FE: 61fffffffe6a             bsr.l   _evdispatch
0406AA04: 242efffc                 move.l  -4(a6),d2
0406AA08: 4e5e                     unlk    a6
0406AA0A: 4e75                     rts
