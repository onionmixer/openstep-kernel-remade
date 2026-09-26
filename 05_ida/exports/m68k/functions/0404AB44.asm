0404AB44: 4856                     pea     (a6)
0404AB46: 2c4f                     movea.l sp,a6
0404AB48: 48780008                 pea     (8).w
0404AB4C: 61fffffff6b2             bsr.l   _kalloc
0404AB52: 4e5e                     unlk    a6
0404AB54: 4e75                     rts
