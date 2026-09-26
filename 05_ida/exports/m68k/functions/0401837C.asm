0401837C: 4856                     pea     (a6)
0401837E: 2c4f                     movea.l sp,a6
04018380: 2f02                     move.l  d2,-(sp)
04018382: 242e0008                 move.l  8(a6),d2
04018386: 2f02                     move.l  d2,-(sp)
04018388: 61fffffff762             bsr.l   _brelse
0401838E: 2f02                     move.l  d2,-(sp)
04018390: 61ff000001f2             bsr.l   sub_4018584
04018396: 242efffc                 move.l  -4(a6),d2
0401839A: 4e5e                     unlk    a6
0401839C: 4e75                     rts
