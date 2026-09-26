0401C170: 4856                     pea     (a6)
0401C172: 2c4f                     movea.l sp,a6
0401C174: 206e0008                 movea.l 8(a6),a0
0401C178: 4aa80016                 tst.l   $16(a0)
0401C17C: 56c0                     sne     d0
0401C17E: 49c0                     extb.l  d0
0401C180: 4480                     neg.l   d0
0401C182: 4e5e                     unlk    a6
0401C184: 4e75                     rts
