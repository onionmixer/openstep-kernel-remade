040484FA: 4856                     pea     (a6)
040484FC: 2c4f                     movea.l sp,a6
040484FE: 2f02                     move.l  d2,-(sp)
04048500: 206e0008                 movea.l 8(a6),a0
04048504: 4280                     clr.l   d0
04048506: 4a88                     tst.l   a0
04048508: 6716                     beq.s   loc_4048520
0404850A: 74ff                     moveq   #$FFFFFFFF,d2
0404850C: b488                     cmp.l   a0,d2
0404850E: 6710                     beq.s   loc_4048520
04048510: 22280004                 move.l  4(a0),d1
04048514: 6c0a                     bge.s   loc_4048520
04048516: 0c410005                 cmpi.w  #5,d1
0404851A: 6604                     bne.s   loc_4048520
0404851C: 20280010                 move.l  $10(a0),d0
04048520: 242efffc                 move.l  -4(a6),d2
04048524: 4e5e                     unlk    a6
04048526: 4e75                     rts
