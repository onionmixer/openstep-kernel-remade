0400BD16: 4856                     pea     (a6)
0400BD18: 2c4f                     movea.l sp,a6
0400BD1A: 2f02                     move.l  d2,-(sp)
0400BD1C: 242e0008                 move.l  8(a6),d2
0400BD20: 2f02                     move.l  d2,-(sp)
0400BD22: 4879040a62e8             pea     (aSTableIsFull).l; "%s: table is full\n"
0400BD28: 61fffffff62e             bsr.l   _printf
0400BD2E: 2f02                     move.l  d2,-(sp)
0400BD30: 4879040a62e8             pea     (aSTableIsFull).l; "%s: table is full\n"
0400BD36: 48780003                 pea     (3).w
0400BD3A: 61fffffff71c             bsr.l   _log
0400BD40: 242efffc                 move.l  -4(a6),d2
0400BD44: 4e5e                     unlk    a6
0400BD46: 4e75                     rts
