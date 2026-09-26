04059C6A: 4856                     pea     (a6)
04059C6C: 2c4f                     movea.l sp,a6
04059C6E: 206e0008                 movea.l 8(a6),a0
04059C72: 20280014                 move.l  $14(a0),d0
04059C76: 0680fffff380             addi.l  #-$C80,d0
04059C7C: 7212                     moveq   #$12,d1
04059C7E: b280                     cmp.l   d0,d1
04059C80: 650c                     bcs.s   loc_4059C8E
04059C82: 41f9040b01c0             lea     (unk_40B01C0).l,a0
04059C88: 20300c00                 move.l  (a0,d0.l*4),d0
04059C8C: 6002                     bra.s   loc_4059C90
04059C8E: 4280                     clr.l   d0
04059C90: 4e5e                     unlk    a6
04059C92: 4e75                     rts
