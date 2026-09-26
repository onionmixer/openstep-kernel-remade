0407DCC4: 4856                     pea     (a6)
0407DCC6: 2c4f                     movea.l sp,a6
0407DCC8: 48e73020                 movem.l d2-d3/a2,-(sp)
0407DCCC: 246e0008                 movea.l 8(a6),a2
0407DCD0: 2f2a00c6                 move.l  $C6(a2),-(sp)
0407DCD4: 2052                     movea.l (a2),a0
0407DCD6: 2f280008                 move.l  8(a0),-(sp)
0407DCDA: 61ffffffe842             bsr.l   _scsi_sensemsg
0407DCE0: 206a00c6                 movea.l $C6(a2),a0
0407DCE4: 12280003                 move.b  3(a0),d1
0407DCE8: 7618                     moveq   #$18,d3
0407DCEA: e7a1                     asl.l   d3,d1
0407DCEC: 20280004                 move.l  4(a0),d0
0407DCF0: e088                     lsr.l   #8,d0
0407DCF2: 2401                     move.l  d1,d2
0407DCF4: 8480                     or.l    d0,d2
0407DCF6: 504f                     addq.w  #8,sp
0407DCF8: 082a0002000b             btst    #2,$B(a2)
0407DCFE: 675c                     beq.s   loc_407DD5C
0407DD00: 206a00d2                 movea.l $D2(a2),a0
0407DD04: 2202                     move.l  d2,d1
0407DD06: 4c6a1001000e             divu.l  $E(a2),d1
0407DD0C: 34680070                 movea.w $70(a0),a2
0407DD10: b5c1                     cmpa.l  d1,a2
0407DD12: 6e3e                     bgt.s   loc_407DD52
0407DD14: d0fc00be                 adda.w  #$BE,a0
0407DD18: 93c9                     suba.l  a1,a1
0407DD1A: 928a                     sub.l   a2,d1
0407DD1C: b290                     cmp.l   (a0),d1
0407DD1E: 6f18                     ble.s   loc_407DD38
0407DD20: d0fc002e                 adda.w  #$2E,a0 ; '.'
0407DD24: 5249                     addq.w  #1,a1
0407DD26: 2010                     move.l  (a0),d0
0407DD28: 76ff                     moveq   #$FFFFFFFF,d3
0407DD2A: b680                     cmp.l   d0,d3
0407DD2C: 670a                     beq.s   loc_407DD38
0407DD2E: 7608                     moveq   #8,d3
0407DD30: b689                     cmp.l   a1,d3
0407DD32: 6704                     beq.s   loc_407DD38
0407DD34: b280                     cmp.l   d0,d1
0407DD36: 6ee8                     bgt.s   loc_407DD20
0407DD38: 92a8ffd2                 sub.l   -$2E(a0),d1
0407DD3C: 2f01                     move.l  d1,-(sp)
0407DD3E: 48690060                 pea     $60(a1)
0407DD42: 2f02                     move.l  d2,-(sp)
0407DD44: 4879040ab8a9             pea     (aScsiBlockInErr).l; "    SCSI Block in error = %d; Partition"...
0407DD4A: 61fffff8d60c             bsr.l   _printf
0407DD50: 6018                     bra.s   loc_407DD6A
0407DD52: 2f02                     move.l  d2,-(sp)
0407DD54: 4879040ab8e4             pea     (aScsiBlockInErr_0).l; "    SCSI Block in error = %d (front por"...
0407DD5A: 6008                     bra.s   loc_407DD64
0407DD5C: 2f02                     move.l  d2,-(sp)
0407DD5E: 4879040ab910             pea     (aScsiBlockInErr_1).l; "    SCSI Block in error = %d (no valid "...
0407DD64: 61fffff8d5f2             bsr.l   _printf
0407DD6A: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
0407DD70: 4e5e                     unlk    a6
0407DD72: 4e75                     rts
