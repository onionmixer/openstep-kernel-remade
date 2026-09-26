04019CCE: 4856                     pea     (a6)
04019CD0: 2c4f                     movea.l sp,a6
04019CD2: 2f0a                     move.l  a2,-(sp)
04019CD4: 246e0008                 movea.l 8(a6),a2
04019CD8: 48780400                 pea     ($400).w
04019CDC: 2f12                     move.l  (a2),-(sp)
04019CDE: 61ff000305e4             bsr.l   _kfree
04019CE4: 4292                     clr.l   (a2)
04019CE6: 246efffc                 movea.l -4(a6),a2
04019CEA: 4e5e                     unlk    a6
04019CEC: 4e75                     rts
