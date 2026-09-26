040691FC: 4856                     pea     (a6)
040691FE: 2c4f                     movea.l sp,a6
04069200: 2f03                     move.l  d3,-(sp)
04069202: 2f02                     move.l  d2,-(sp)
04069204: 242e0008                 move.l  8(a6),d2
04069208: 222e000c                 move.l  $C(a6),d1
0406920C: 08020000                 btst    #0,d2
04069210: 6716                     beq.s   loc_4069228
04069212: 2001                     move.l  d1,d0
04069214: 762b                     moveq   #$2B,d3 ; '+'
04069216: b681                     cmp.l   d1,d3
04069218: 6c02                     bge.s   loc_406921C
0406921A: 702b                     moveq   #$2B,d0 ; '+'
0406921C: 4a80                     tst.l   d0
0406921E: 6c02                     bge.s   loc_4069222
04069220: 4280                     clr.l   d0
04069222: 23c0040b20c4             move.l  d0,(_vol_l).l
04069228: 08020001                 btst    #1,d2
0406922C: 6716                     beq.s   loc_4069244
0406922E: 2001                     move.l  d1,d0
04069230: 762b                     moveq   #$2B,d3 ; '+'
04069232: b680                     cmp.l   d0,d3
04069234: 6c02                     bge.s   loc_4069238
04069236: 702b                     moveq   #$2B,d0 ; '+'
04069238: 4a80                     tst.l   d0
0406923A: 6c02                     bge.s   loc_406923E
0406923C: 4280                     clr.l   d0
0406923E: 23c0040b20c0             move.l  d0,(_vol_r).l
04069244: 242efff8                 move.l  -8(a6),d2
04069248: 262efffc                 move.l  -4(a6),d3
0406924C: 4e5e                     unlk    a6
0406924E: 4e75                     rts
