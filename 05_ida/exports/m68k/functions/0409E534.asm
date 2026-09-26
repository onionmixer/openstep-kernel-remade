0409E534: 2f00                     move.l  d0,-(sp)
0409E536: 4280                     clr.l   d0
0409E538: 61ff0000052e             bsr.l   dnrm_lp
0409E53E: e9ee1082ff83             bfextu  -$7D(a6){2:2},d1
0409E544: 4841                     swap    d1
0409E546: 322f0002                 move.w  4+var_2(sp),d1
0409E54A: 4841                     swap    d1
0409E54C: 61ff0000015c             bsr.l   round
0409E552: 303c0001                 move.w  #1,d0
0409E556: 91680000                 sub.w   d0,0(a0)
0409E55A: 2248                     movea.l a0,a1
0409E55C: 206e000c                 movea.l $C(a6),a0
0409E560: 584f                     addq.w  #4,sp
0409E562: 4e75                     rts
