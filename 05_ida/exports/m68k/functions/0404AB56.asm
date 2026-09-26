0404AB56: 4856                     pea     (a6)
0404AB58: 2c4f                     movea.l sp,a6
0404AB5A: 48780008                 pea     (8).w
0404AB5E: 2f2e0008                 move.l  8(a6),-(sp)
0404AB62: 61fffffff760             bsr.l   _kfree
0404AB68: 4e5e                     unlk    a6
0404AB6A: 4e75                     rts
