0404A362: 4856                     pea     (a6)
0404A364: 2c4f                     movea.l sp,a6
0404A366: 222e0008                 move.l  8(a6),d1
0404A36A: 4c2e1800000c             muls.l  $C(a6),d1
0404A370: 2f01                     move.l  d1,-(sp)
0404A372: 61ffffffffb0             bsr.l   _malloc
0404A378: 4e5e                     unlk    a6
0404A37A: 4e75                     rts
