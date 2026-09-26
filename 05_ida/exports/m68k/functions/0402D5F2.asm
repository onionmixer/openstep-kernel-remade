0402D5F2: 4856                     pea     (a6)
0402D5F4: 2c4f                     movea.l sp,a6
0402D5F6: 206e000c                 movea.l $C(a6),a0
0402D5FA: 48790402fdd6             pea     (_xdr_void).l
0402D600: 4879040aef4a             pea     (_diropres_discrim).l
0402D606: 48680004                 pea     4(a0)
0402D60A: 2f08                     move.l  a0,-(sp)
0402D60C: 2f2e0008                 move.l  8(a6),-(sp)
0402D610: 61ff00002bd4             bsr.l   _xdr_union
0402D616: 2200                     move.l  d0,d1
0402D618: 7001                     moveq   #1,d0
0402D61A: 4a81                     tst.l   d1
0402D61C: 6602                     bne.s   loc_402D620
0402D61E: 4280                     clr.l   d0
0402D620: 4e5e                     unlk    a6
0402D622: 4e75                     rts
