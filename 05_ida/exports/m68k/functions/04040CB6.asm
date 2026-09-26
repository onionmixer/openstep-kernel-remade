04040CB6: 4856                     pea     (a6)
04040CB8: 2c4f                     movea.l sp,a6
04040CBA: 206e0008                 movea.l 8(a6),a0
04040CBE: 226e0010                 movea.l $10(a6),a1
04040CC2: 20280024                 move.l  $24(a0),d0
04040CC6: 216e000c0024             move.l  $C(a6),$24(a0)
04040CCC: 2280                     move.l  d0,(a1)
04040CCE: 4e5e                     unlk    a6
04040CD0: 4e75                     rts
