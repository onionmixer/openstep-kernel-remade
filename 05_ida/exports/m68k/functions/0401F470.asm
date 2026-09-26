0401F470: 4856                     pea     (a6)
0401F472: 2c4f                     movea.l sp,a6
0401F474: 202e0008                 move.l  8(a6),d0
0401F478: 2079040b7bb4             movea.l (_in_ifaddr).l,a0
0401F47E: 4a88                     tst.l   a0
0401F480: 6712                     beq.s   loc_401F494
0401F482: b0a80030                 cmp.l   $30(a0),d0
0401F486: 6604                     bne.s   loc_401F48C
0401F488: 2008                     move.l  a0,d0
0401F48A: 600a                     bra.s   loc_401F496
0401F48C: 20680040                 movea.l $40(a0),a0
0401F490: 4a88                     tst.l   a0
0401F492: 66ee                     bne.s   loc_401F482
0401F494: 4280                     clr.l   d0
0401F496: 4e5e                     unlk    a6
0401F498: 4e75                     rts
