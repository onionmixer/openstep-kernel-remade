040411B2: 4856                     pea     (a6)
040411B4: 2c4f                     movea.l sp,a6
040411B6: 2f2e000c                 move.l  $C(a6),-(sp)
040411BA: 2f2e0008                 move.l  8(a6),-(sp)
040411BE: 61ffffffae8a             bsr.l   _ipc_entry_lookup
040411C4: 2040                     movea.l d0,a0
040411C6: 4a88                     tst.l   a0
040411C8: 6716                     beq.s   loc_40411E0
040411CA: 082800010001             btst    #1,1(a0)
040411D0: 670e                     beq.s   loc_40411E0
040411D2: 20680004                 movea.l 4(a0),a0
040411D6: 5290                     addq.l  #1,(a0)
040411D8: 52a8001c                 addq.l  #1,$1C(a0)
040411DC: 2008                     move.l  a0,d0
040411DE: 6002                     bra.s   loc_40411E2
040411E0: 4280                     clr.l   d0
040411E2: 4e5e                     unlk    a6
040411E4: 4e75                     rts
