040072CC: 4856                     pea     (a6)
040072CE: 2c4f                     movea.l sp,a6
040072D0: 206e0008                 movea.l 8(a6),a0
040072D4: 4a88                     tst.l   a0
040072D6: 6604                     bne.s   loc_40072DC
040072D8: 4280                     clr.l   d0
040072DA: 600a                     bra.s   loc_40072E6
040072DC: 2068000c                 movea.l $C(a0),a0
040072E0: 20680030                 movea.l $30(a0),a0
040072E4: 2010                     move.l  (a0),d0
040072E6: 4e5e                     unlk    a6
040072E8: 4e75                     rts
