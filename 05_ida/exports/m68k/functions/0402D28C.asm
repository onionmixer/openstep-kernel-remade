0402D28C: 4856                     pea     (a6)
0402D28E: 2c4f                     movea.l sp,a6
0402D290: 206e000c                 movea.l $C(a6),a0
0402D294: 48790402fdd6             pea     (_xdr_void).l
0402D29A: 4879040aef3a             pea     (_rdlnres_discrim).l
0402D2A0: 48680004                 pea     4(a0)
0402D2A4: 2f08                     move.l  a0,-(sp)
0402D2A6: 2f2e0008                 move.l  8(a6),-(sp)
0402D2AA: 61ff00002f3a             bsr.l   _xdr_union
0402D2B0: 2200                     move.l  d0,d1
0402D2B2: 7001                     moveq   #1,d0
0402D2B4: 4a81                     tst.l   d1
0402D2B6: 6602                     bne.s   loc_402D2BA
0402D2B8: 4280                     clr.l   d0
0402D2BA: 4e5e                     unlk    a6
0402D2BC: 4e75                     rts
