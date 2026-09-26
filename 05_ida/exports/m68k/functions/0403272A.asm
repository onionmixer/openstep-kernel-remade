0403272A: 4856                     pea     (a6)
0403272C: 2c4f                     movea.l sp,a6
0403272E: 206e0008                 movea.l 8(a6),a0
04032732: 226e000c                 movea.l $C(a6),a1
04032736: 20680014                 movea.l $14(a0),a0
0403273A: 7001                     moveq   #1,d0
0403273C: 222e0010                 move.l  $10(a6),d1
04032740: e3a0                     asl.l   d1,d0
04032742: 5380                     subq.l  #1,d0
04032744: 222e0014                 move.l  $14(a6),d1
04032748: e3a0                     asl.l   d1,d0
0403274A: 81318800                 or.b    d0,(a1,a0.l)
0403274E: 4e5e                     unlk    a6
04032750: 4e75                     rts
