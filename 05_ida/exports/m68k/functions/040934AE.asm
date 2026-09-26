040934AE: 4856                     pea     (a6)
040934B0: 2c4f                     movea.l sp,a6
040934B2: 102e000b                 move.b  $B(a6),d0
040934B6: 0c000020                 cmpi.b  #$20,d0 ; ' '
040934BA: 6710                     beq.s   loc_40934CC
040934BC: 4a00                     tst.b   d0
040934BE: 670c                     beq.s   loc_40934CC
040934C0: 0c000009                 cmpi.b  #9,d0
040934C4: 6706                     beq.s   loc_40934CC
040934C6: 0c00002c                 cmpi.b  #$2C,d0 ; ','
040934CA: 6604                     bne.s   loc_40934D0
040934CC: 7001                     moveq   #1,d0
040934CE: 6002                     bra.s   loc_40934D2
040934D0: 4280                     clr.l   d0
040934D2: 4e5e                     unlk    a6
040934D4: 4e75                     rts
