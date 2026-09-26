0400A202: 4856                     pea     (a6)
0400A204: 2c4f                     movea.l sp,a6
0400A206: 2f02                     move.l  d2,-(sp)
0400A208: 202e0008                 move.l  8(a6),d0
0400A20C: 40c2                     move    sr,d2
0400A20E: 46fc2700                 move    #$2700,sr
0400A212: 48c2                     ext.l   d2
0400A214: 42a7                     clr.l   -(sp)
0400A216: 42a7                     clr.l   -(sp)
0400A218: 2f00                     move.l  d0,-(sp)
0400A21A: 61ff00046734             bsr.l   _thread_wakeup_prim
0400A220: 40c0                     move    sr,d0
0400A222: 46c2                     move    d2,sr
0400A224: 242efffc                 move.l  -4(a6),d2
0400A228: 4e5e                     unlk    a6
0400A22A: 4e75                     rts
