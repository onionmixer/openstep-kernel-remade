0403BFDA: 4856                     pea     (a6)
0403BFDC: 2c4f                     movea.l sp,a6
0403BFDE: 206e0008                 movea.l 8(a6),a0
0403BFE2: 226e000c                 movea.l $C(a6),a1
0403BFE6: 2068002e                 movea.l $2E(a0),a0
0403BFEA: 30680064                 movea.w $64(a0),a0
0403BFEE: 2288                     move.l  a0,(a1)
0403BFF0: 4280                     clr.l   d0
0403BFF2: 4e5e                     unlk    a6
0403BFF4: 4e75                     rts
