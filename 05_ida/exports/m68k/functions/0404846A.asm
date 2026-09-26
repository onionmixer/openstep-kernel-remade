0404846A: 4856                     pea     (a6)
0404846C: 2c4f                     movea.l sp,a6
0404846E: 206e000c                 movea.l $C(a6),a0
04048472: 4aae0008                 tst.l   8(a6)
04048476: 6716                     beq.s   loc_404848E
04048478: 20bc040b6648             move.l  #$40B6648,(a0)
0404847E: 4879040b6648             pea     (_default_pset).l
04048484: 61ff00006e5e             bsr.l   _pset_reference
0404848A: 4280                     clr.l   d0
0404848C: 6002                     bra.s   loc_4048490
0404848E: 7004                     moveq   #4,d0
04048490: 4e5e                     unlk    a6
04048492: 4e75                     rts
