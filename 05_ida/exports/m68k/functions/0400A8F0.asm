0400A8F0: 4856                     pea     (a6)
0400A8F2: 2c4f                     movea.l sp,a6
0400A8F4: 206e0008                 movea.l 8(a6),a0
0400A8F8: 226e000c                 movea.l $C(a6),a1
0400A8FC: 2211                     move.l  (a1),d1
0400A8FE: d390                     add.l   d1,(a0)
0400A900: 22290004                 move.l  4(a1),d1
0400A904: d3a80004                 add.l   d1,4(a0)
0400A908: 2f08                     move.l  a0,-(sp)
0400A90A: 61ff0000002c             bsr.l   _timevalfix
0400A910: 4e5e                     unlk    a6
0400A912: 4e75                     rts
