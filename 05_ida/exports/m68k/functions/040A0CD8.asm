040A0CD8: 082e00050004             btst    #5,4(a6)
040A0CDE: 67ff00000010             beq.l   loc_40A0CF0
040A0CE4: 12d8                     move.b  (a0)+,(a1)+
040A0CE6: 5380                     subq.l  #1,d0
040A0CE8: 66fffffffffa             bne.l   loc_40A0CE4
040A0CEE: 4e75                     rts
040A0CF0: 2f01                     move.l  d1,-(sp)
040A0CF2: 2f00                     move.l  d0,-(sp)
040A0CF4: 2f09                     move.l  a1,-(sp)
040A0CF6: 2f08                     move.l  a0,-(sp)
040A0CF8: 4eb90400165e             jsr     _copyoutmsg
040A0CFE: defc000c                 adda.w  #$C,sp
040A0D02: 221f                     move.l  (sp)+,d1
040A0D04: 4e75                     rts
