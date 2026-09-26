04092232: 4856                     pea     (a6)
04092234: 2c4f                     movea.l sp,a6
04092236: 202e0008                 move.l  8(a6),d0
0409223A: 670e                     beq.s   loc_409224A
0409223C: 7201                     moveq   #1,d1
0409223E: b280                     cmp.l   d0,d1
04092240: 6610                     bne.s   loc_4092252
04092242: 203c040ad8ca             move.l  #$40AD8CA,d0
04092248: 600a                     bra.s   loc_4092254
0409224A: 203c040ad8da             move.l  #$40AD8DA,d0
04092250: 6002                     bra.s   loc_4092254
04092252: 4280                     clr.l   d0
04092254: 4e5e                     unlk    a6
04092256: 4e75                     rts
