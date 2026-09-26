0400CDDE: 4856                     pea     (a6)
0400CDE0: 2c4f                     movea.l sp,a6
0400CDE2: 2f02                     move.l  d2,-(sp)
0400CDE4: 242e0008                 move.l  8(a6),d2
0400CDE8: 2f02                     move.l  d2,-(sp)
0400CDEA: 61ff00000018             bsr.l   _ttywait
0400CDF0: 48780001                 pea     (1).w
0400CDF4: 2f02                     move.l  d2,-(sp)
0400CDF6: 61ff00000082             bsr.l   _ttyflush
0400CDFC: 242efffc                 move.l  -4(a6),d2
0400CE00: 4e5e                     unlk    a6
0400CE02: 4e75                     rts
