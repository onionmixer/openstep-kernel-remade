04053844: 4856                     pea     (a6)
04053846: 2c4f                     movea.l sp,a6
04053848: 4879040b6648             pea     (_default_pset).l
0405384E: 2f2e0008                 move.l  8(a6),-(sp)
04053852: 61ffffffffe6             bsr.l   _thread_assign
04053858: 4e5e                     unlk    a6
0405385A: 4e75                     rts
