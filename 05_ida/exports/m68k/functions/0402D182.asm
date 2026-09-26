0402D182: 4856                     pea     (a6)
0402D184: 2c4f                     movea.l sp,a6
0402D186: 206e000c                 movea.l $C(a6),a0
0402D18A: 48790402fdd6             pea     (_xdr_void).l
0402D190: 4879040aef1a             pea     (_rdres_discrim).l
0402D196: 48680004                 pea     4(a0)
0402D19A: 2f08                     move.l  a0,-(sp)
0402D19C: 2f2e0008                 move.l  8(a6),-(sp)
0402D1A0: 61ff00003044             bsr.l   _xdr_union
0402D1A6: 2200                     move.l  d0,d1
0402D1A8: 7001                     moveq   #1,d0
0402D1AA: 4a81                     tst.l   d1
0402D1AC: 6602                     bne.s   loc_402D1B0
0402D1AE: 4280                     clr.l   d0
0402D1B0: 4e5e                     unlk    a6
0402D1B2: 4e75                     rts
