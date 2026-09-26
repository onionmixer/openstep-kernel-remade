040967F2: 4856                     pea     (a6)
040967F4: 2c4f                     movea.l sp,a6
040967F6: 206e0008                 movea.l 8(a6),a0
040967FA: 20280028                 move.l  $28(a0),d0
040967FE: 42a80028                 clr.l   $28(a0)
04096802: 4e5e                     unlk    a6
04096804: 4e75                     rts
