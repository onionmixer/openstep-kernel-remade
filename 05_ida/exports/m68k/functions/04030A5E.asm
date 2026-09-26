04030A5E: 4856                     pea     (a6)
04030A60: 2c4f                     movea.l sp,a6
04030A62: 206e000c                 movea.l $C(a6),a0
04030A66: 42a7                     clr.l   -(sp)
04030A68: 4879040af0ae             pea     (unk_40AF0AE).l
04030A6E: 48680004                 pea     4(a0)
04030A72: 2f08                     move.l  a0,-(sp)
04030A74: 2f2e0008                 move.l  8(a6),-(sp)
04030A78: 61fffffff76c             bsr.l   _xdr_union
04030A7E: 2200                     move.l  d0,d1
04030A80: 4280                     clr.l   d0
04030A82: 4a81                     tst.l   d1
04030A84: 6702                     beq.s   loc_4030A88
04030A86: 7001                     moveq   #1,d0
04030A88: 4e5e                     unlk    a6
04030A8A: 4e75                     rts
