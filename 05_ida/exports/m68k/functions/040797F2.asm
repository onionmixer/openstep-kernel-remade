040797F2: 4856                     pea     (a6)
040797F4: 2c4f                     movea.l sp,a6
040797F6: 48e70038                 movem.l a2-a4,-(sp)
040797FA: 47f9040c3e18             lea     (_od_drive).l,a3
04079800: b7fc040c3e58             cmpa.l  #$40C3E58,a3
04079806: 646e                     bcc.s   loc_4079876
04079808: 49f9040c3e36             lea     (unk_40C3E36).l,a4
0407980E: 45f9040c3e30             lea     (word_40C3E30).l,a2
04079814: 0c14ffff                 cmpi.b  #$FF,(a4)
04079818: 6648                     bne.s   loc_4079862
0407981A: 206b0008                 movea.l 8(a3),a0
0407981E: 0828000500d8             btst    #5,$D8(a0)
04079824: 673c                     beq.s   loc_4079862
04079826: 2008                     move.l  a0,d0
04079828: 0480040c3ec8             subi.l  #$40C3EC8,d0
0407982E: 4c3c0800da6c0965         muls.l  #$DA6C0965,d0
04079836: e580                     asl.l   #2,d0
04079838: 42a7                     clr.l   -(sp)
0407983A: 42a7                     clr.l   -(sp)
0407983C: 42a7                     clr.l   -(sp)
0407983E: 42a7                     clr.l   -(sp)
04079840: 42a7                     clr.l   -(sp)
04079842: 42a7                     clr.l   -(sp)
04079844: 42a7                     clr.l   -(sp)
04079846: 42a7                     clr.l   -(sp)
04079848: 487800f3                 pea     ($F3).w
0407984C: 72f8                     moveq   #$FFFFFFF8,d1
0407984E: c280                     and.l   d0,d1
04079850: 2f01                     move.l  d1,-(sp)
04079852: 61ffffffee66             bsr.l   _od_cmd
04079858: 0252dfff                 andi.w  #$DFFF,(a2)
0407985C: 4214                     clr.b   (a4)
0407985E: defc0028                 adda.w  #$28,sp ; '('
04079862: d8fc0020                 adda.w  #$20,a4 ; ' '
04079866: d4fc0020                 adda.w  #$20,a2 ; ' '
0407986A: d6fc0020                 adda.w  #$20,a3 ; ' '
0407986E: b7fc040c3e58             cmpa.l  #$40C3E58,a3
04079874: 659e                     bcs.s   loc_4079814
04079876: 2f39040b5648             move.l  (_active_threads).l,-(sp)
0407987C: 61fffffd94c2             bsr.l   _thread_terminate
04079882: 61fffffd98a0             bsr.l   _thread_halt_self
04079888: 4cee1c00fff4             movem.l -$C(a6),a2-a4
0407988E: 4e5e                     unlk    a6
04079890: 4e75                     rts
