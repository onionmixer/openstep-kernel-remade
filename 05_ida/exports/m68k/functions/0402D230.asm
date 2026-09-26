0402D230: 4856                     pea     (a6)
0402D232: 2c4f                     movea.l sp,a6
0402D234: 206e000c                 movea.l $C(a6),a0
0402D238: 48790402fdd6             pea     (_xdr_void).l
0402D23E: 4879040aef2a             pea     (_attrstat_discrim).l
0402D244: 48680004                 pea     4(a0)
0402D248: 2f08                     move.l  a0,-(sp)
0402D24A: 2f2e0008                 move.l  8(a6),-(sp)
0402D24E: 61ff00002f96             bsr.l   _xdr_union
0402D254: 2200                     move.l  d0,d1
0402D256: 7001                     moveq   #1,d0
0402D258: 4a81                     tst.l   d1
0402D25A: 6602                     bne.s   loc_402D25E
0402D25C: 4280                     clr.l   d0
0402D25E: 4e5e                     unlk    a6
0402D260: 4e75                     rts
