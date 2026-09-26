0405188E: 4856                     pea     (a6)
04051890: 2c4f                     movea.l sp,a6
04051892: 42a7                     clr.l   -(sp)
04051894: 42a7                     clr.l   -(sp)
04051896: 2f2e0008                 move.l  8(a6),-(sp)
0405189A: 61fffffff0b4             bsr.l   _thread_wakeup_prim
040518A0: 4e5e                     unlk    a6
040518A2: 4e75                     rts
