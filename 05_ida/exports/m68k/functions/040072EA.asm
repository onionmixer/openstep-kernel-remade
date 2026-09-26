040072EA: 4856                     pea     (a6)
040072EC: 2c4f                     movea.l sp,a6
040072EE: 206e0008                 movea.l 8(a6),a0
040072F2: 4a88                     tst.l   a0
040072F4: 6604                     bne.s   loc_40072FA
040072F6: 4280                     clr.l   d0
040072F8: 6008                     bra.s   loc_4007302
040072FA: 2068000c                 movea.l $C(a0),a0
040072FE: 20280030                 move.l  $30(a0),d0
04007302: 4e5e                     unlk    a6
04007304: 4e75                     rts
