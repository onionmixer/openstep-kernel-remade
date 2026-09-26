040028FA: 4856                     pea     (a6)
040028FC: 2c4f                     movea.l sp,a6
040028FE: 2079040af5be             movea.l (_mounttab).l,a0
04002904: 4a88                     tst.l   a0
04002906: 6708                     beq.s   loc_4002910
04002908: 2068001c                 movea.l $1C(a0),a0
0400290C: 4a88                     tst.l   a0
0400290E: 66f8                     bne.s   loc_4002908
04002910: 4280                     clr.l   d0
04002912: 4e5e                     unlk    a6
04002914: 4e75                     rts
