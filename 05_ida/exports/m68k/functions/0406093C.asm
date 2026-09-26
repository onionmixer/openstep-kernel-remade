0406093C: 4856                     pea     (a6)
0406093E: 2c4f                     movea.l sp,a6
04060940: 2f2e0008                 move.l  8(a6),-(sp)
04060944: 61ff00002b30             bsr.l   _vnode_alloc
0406094A: 4e5e                     unlk    a6
0406094C: 4e75                     rts
