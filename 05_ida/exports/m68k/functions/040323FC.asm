040323FC: 4856                     pea     (a6)
040323FE: 2c4f                     movea.l sp,a6
04032400: 206e0008                 movea.l 8(a6),a0
04032404: 2068002e                 movea.l $2E(a0),a0
04032408: 22680036                 movea.l $36(a0),a1
0403240C: 4a89                     tst.l   a1
0403240E: 6604                     bne.s   loc_4032414
04032410: 4280                     clr.l   d0
04032412: 6014                     bra.s   loc_4032428
04032414: 2069001c                 movea.l $1C(a1),a0
04032418: 2f2e0010                 move.l  $10(a6),-(sp)
0403241C: 2f2e000c                 move.l  $C(a6),-(sp)
04032420: 2f09                     move.l  a1,-(sp)
04032422: 2068001c                 movea.l $1C(a0),a0
04032426: 4e90                     jsr     (a0)
04032428: 4e5e                     unlk    a6
0403242A: 4e75                     rts
