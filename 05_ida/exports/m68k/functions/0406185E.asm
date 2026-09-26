0406185E: 4856                     pea     (a6)
04061860: 2c4f                     movea.l sp,a6
04061862: 226e0008                 movea.l 8(a6),a1
04061866: 206e000c                 movea.l $C(a6),a0
0406186A: 2f280022                 move.l  $22(a0),-(sp)
0406186E: 2f290022                 move.l  $22(a1),-(sp)
04061872: 61ff00037688             bsr.l   _pmap_copy_page
04061878: 4e5e                     unlk    a6
0406187A: 4e75                     rts
