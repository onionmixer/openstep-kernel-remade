0402DA4E: 4856                     pea     (a6)
0402DA50: 2c4f                     movea.l sp,a6
0402DA52: 48780028                 pea     ($28).w
0402DA56: 2f2e0008                 move.l  8(a6),-(sp)
0402DA5A: 61ff0001c868             bsr.l   _kfree
0402DA60: 4e5e                     unlk    a6
0402DA62: 4e75                     rts
