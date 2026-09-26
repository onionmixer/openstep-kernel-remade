0402D828: 4856                     pea     (a6)
0402D82A: 2c4f                     movea.l sp,a6
0402D82C: 206e000c                 movea.l $C(a6),a0
0402D830: 48790402fdd6             pea     (_xdr_void).l
0402D836: 4879040aef5a             pea     (_statfs_discrim).l
0402D83C: 48680004                 pea     4(a0)
0402D840: 2f08                     move.l  a0,-(sp)
0402D842: 2f2e0008                 move.l  8(a6),-(sp)
0402D846: 61ff0000299e             bsr.l   _xdr_union
0402D84C: 2200                     move.l  d0,d1
0402D84E: 7001                     moveq   #1,d0
0402D850: 4a81                     tst.l   d1
0402D852: 6602                     bne.s   loc_402D856
0402D854: 4280                     clr.l   d0
0402D856: 4e5e                     unlk    a6
0402D858: 4e75                     rts
