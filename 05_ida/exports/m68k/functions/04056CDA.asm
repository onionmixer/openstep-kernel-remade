04056CDA: 4856                     pea     (a6)
04056CDC: 2c4f                     movea.l sp,a6
04056CDE: 206e000c                 movea.l $C(a6),a0
04056CE2: 4a88                     tst.l   a0
04056CE4: 6604                     bne.s   loc_4056CEA
04056CE6: 7064                     moveq   #$64,d0 ; 'd'
04056CE8: 6008                     bra.s   loc_4056CF2
04056CEA: 2f2e0010                 move.l  $10(a6),-(sp)
04056CEE: 4e90                     jsr     (a0)
04056CF0: 4280                     clr.l   d0
04056CF2: 4e5e                     unlk    a6
04056CF4: 4e75                     rts
