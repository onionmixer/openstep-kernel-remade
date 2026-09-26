04014600: 4856                     pea     (a6)
04014602: 2c4f                     movea.l sp,a6
04014604: 2f0a                     move.l  a2,-(sp)
04014606: 2f02                     move.l  d2,-(sp)
04014608: 246e0008                 movea.l 8(a6),a2
0401460C: 082a00000015             btst    #0,$15(a2)
04014612: 670e                     beq.s   loc_4014622
04014614: 4879040a6472             pea     (aSbflush).l; "sbflush"
0401461A: 61ffffff764a             bsr.l   _panic
04014620: 584f                     addq.w  #4,sp
04014622: 4a6a0004                 tst.w   4(a2)
04014626: 6716                     beq.s   loc_401463E
04014628: 4282                     clr.l   d2
0401462A: 3412                     move.w  (a2),d2
0401462C: 2f02                     move.l  d2,-(sp)
0401462E: 2f0a                     move.l  a2,-(sp)
04014630: 61ff00000034             bsr.l   _sbdrop
04014636: 504f                     addq.w  #8,sp
04014638: 4a6a0004                 tst.w   4(a2)
0401463C: 66ec                     bne.s   loc_401462A
0401463E: 4a52                     tst.w   (a2)
04014640: 660c                     bne.s   loc_401464E
04014642: 4a6a0004                 tst.w   4(a2)
04014646: 6606                     bne.s   loc_401464E
04014648: 4aaa000c                 tst.l   $C(a2)
0401464C: 670c                     beq.s   loc_401465A
0401464E: 4879040a647a             pea     (aSbflush2).l; "sbflush 2"
04014654: 61ffffff7610             bsr.l   _panic
0401465A: 242efff8                 move.l  -8(a6),d2
0401465E: 246efffc                 movea.l -4(a6),a2
04014662: 4e5e                     unlk    a6
04014664: 4e75                     rts
