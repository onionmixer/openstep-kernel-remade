04020644: 4856                     pea     (a6)
04020646: 2c4f                     movea.l sp,a6
04020648: 202e0008                 move.l  8(a6),d0
0402064C: 2079040b7bb4             movea.l (_in_ifaddr).l,a0
04020652: 4a88                     tst.l   a0
04020654: 6712                     beq.s   loc_4020668
04020656: b0a80020                 cmp.l   $20(a0),d0
0402065A: 6604                     bne.s   loc_4020660
0402065C: 2008                     move.l  a0,d0
0402065E: 600a                     bra.s   loc_402066A
04020660: 20680040                 movea.l $40(a0),a0
04020664: 4a88                     tst.l   a0
04020666: 66ee                     bne.s   loc_4020656
04020668: 4280                     clr.l   d0
0402066A: 4e5e                     unlk    a6
0402066C: 4e75                     rts
