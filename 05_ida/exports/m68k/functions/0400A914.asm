0400A914: 4856                     pea     (a6)
0400A916: 2c4f                     movea.l sp,a6
0400A918: 206e0008                 movea.l 8(a6),a0
0400A91C: 226e000c                 movea.l $C(a6),a1
0400A920: 2211                     move.l  (a1),d1
0400A922: 9390                     sub.l   d1,(a0)
0400A924: 22290004                 move.l  4(a1),d1
0400A928: 93a80004                 sub.l   d1,4(a0)
0400A92C: 2f08                     move.l  a0,-(sp)
0400A92E: 61ff00000008             bsr.l   _timevalfix
0400A934: 4e5e                     unlk    a6
0400A936: 4e75                     rts
