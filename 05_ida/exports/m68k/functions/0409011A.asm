0409011A: 4856                     pea     (a6)
0409011C: 2c4f                     movea.l sp,a6
0409011E: 206e0008                 movea.l 8(a6),a0
04090122: 2250                     movea.l (a0),a1
04090124: 4290                     clr.l   (a0)
04090126: 48690022                 pea     $22(a1)
0409012A: 61fffff83f2a             bsr.l   _sbwakeup
04090130: 4e5e                     unlk    a6
04090132: 4e75                     rts
