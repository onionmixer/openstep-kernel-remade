040929C6: 4856                     pea     (a6)
040929C8: 2c4f                     movea.l sp,a6
040929CA: 202e0008                 move.l  8(a6),d0
040929CE: 7201                     moveq   #1,d1
040929D0: b280                     cmp.l   d0,d1
040929D2: 670e                     beq.s   loc_40929E2
040929D4: 72ff                     moveq   #$FFFFFFFF,d1
040929D6: b280                     cmp.l   d0,d1
040929D8: 6708                     beq.s   loc_40929E2
040929DA: b0b9040b5dd0             cmp.l   (dword_40B5DD0).l,d0
040929E0: 6604                     bne.s   loc_40929E6
040929E2: 7001                     moveq   #1,d0
040929E4: 6002                     bra.s   loc_40929E8
040929E6: 4280                     clr.l   d0
040929E8: 4e5e                     unlk    a6
040929EA: 4e75                     rts
