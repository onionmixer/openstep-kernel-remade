04028EE6: 4856                     pea     (a6)
04028EE8: 2c4f                     movea.l sp,a6
04028EEA: 206e0008                 movea.l 8(a6),a0
04028EEE: 202e000c                 move.l  $C(a6),d0
04028EF2: 0240fbff                 andi.w  #$FBFF,d0
04028EF6: 2068002e                 movea.l $2E(a0),a0
04028EFA: 082800020080             btst    #2,$80(a0)
04028F00: 6704                     beq.s   loc_4028F06
04028F02: 00400400                 ori.w   #$400,d0
04028F06: 4e5e                     unlk    a6
04028F08: 4e75                     rts
