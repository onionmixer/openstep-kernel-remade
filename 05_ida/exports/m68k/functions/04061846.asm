04061846: 4856                     pea     (a6)
04061848: 2c4f                     movea.l sp,a6
0406184A: 206e0008                 movea.l 8(a6),a0
0406184E: 2f280022                 move.l  $22(a0),-(sp)
04061852: 61ff000376c4             bsr.l   _pmap_zero_page
04061858: 7001                     moveq   #1,d0
0406185A: 4e5e                     unlk    a6
0406185C: 4e75                     rts
