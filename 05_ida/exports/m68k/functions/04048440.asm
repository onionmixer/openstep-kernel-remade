04048440: 4856                     pea     (a6)
04048442: 2c4f                     movea.l sp,a6
04048444: 206e000c                 movea.l $C(a6),a0
04048448: 4aae0008                 tst.l   8(a6)
0404844C: 6716                     beq.s   loc_4048464
0404844E: 20bc040b6648             move.l  #$40B6648,(a0)
04048454: 4879040b6648             pea     (_default_pset).l
0404845A: 61ff00006e88             bsr.l   _pset_reference
04048460: 4280                     clr.l   d0
04048462: 6002                     bra.s   loc_4048466
04048464: 7004                     moveq   #4,d0
04048466: 4e5e                     unlk    a6
04048468: 4e75                     rts
