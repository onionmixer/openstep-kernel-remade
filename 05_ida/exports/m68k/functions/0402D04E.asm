0402D04E: 4856                     pea     (a6)
0402D050: 2c4f                     movea.l sp,a6
0402D052: 206e0008                 movea.l 8(a6),a0
0402D056: 7201                     moveq   #1,d1
0402D058: 21410004                 move.l  d1,4(a0)
0402D05C: 2f08                     move.l  a0,-(sp)
0402D05E: 61fffffdd1a2             bsr.l   _wakeup
0402D064: 4e5e                     unlk    a6
0402D066: 4e75                     rts
