040A0D06: 082e00050004             btst    #5,4(a6)
040A0D0C: 67ff00000010             beq.l   loc_40A0D1E
040A0D12: 12d8                     move.b  (a0)+,(a1)+
040A0D14: 5380                     subq.l  #1,d0
040A0D16: 66fffffffffa             bne.l   loc_40A0D12
040A0D1C: 4e75                     rts
040A0D1E: 2f01                     move.l  d1,-(sp)
040A0D20: 2f00                     move.l  d0,-(sp)
040A0D22: 2f09                     move.l  a1,-(sp)
040A0D24: 2f08                     move.l  a0,-(sp)
040A0D26: 4eb9040016d0             jsr     _copyinmsg
040A0D2C: defc000c                 adda.w  #$C,sp
040A0D30: 221f                     move.l  (sp)+,d1
040A0D32: 4e75                     rts
