040484CC: 4856                     pea     (a6)
040484CE: 2c4f                     movea.l sp,a6
040484D0: 2f02                     move.l  d2,-(sp)
040484D2: 206e0008                 movea.l 8(a6),a0
040484D6: 4280                     clr.l   d0
040484D8: 4a88                     tst.l   a0
040484DA: 6716                     beq.s   loc_40484F2
040484DC: 74ff                     moveq   #$FFFFFFFF,d2
040484DE: b488                     cmp.l   a0,d2
040484E0: 6710                     beq.s   loc_40484F2
040484E2: 22280004                 move.l  4(a0),d1
040484E6: 6c0a                     bge.s   loc_40484F2
040484E8: 0c410004                 cmpi.w  #4,d1
040484EC: 6604                     bne.s   loc_40484F2
040484EE: 20280010                 move.l  $10(a0),d0
040484F2: 242efffc                 move.l  -4(a6),d2
040484F6: 4e5e                     unlk    a6
040484F8: 4e75                     rts
