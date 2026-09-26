040967BE: 4856                     pea     (a6)
040967C0: 2c4f                     movea.l sp,a6
040967C2: 206e0008                 movea.l 8(a6),a0
040967C6: 202e000c                 move.l  $C(a6),d0
040967CA: 22680024                 movea.l $24(a0),a1
040967CE: 21400028                 move.l  d0,$28(a0)
040967D2: 068000000ff4             addi.l  #$FF4,d0
040967D8: 23400038                 move.l  d0,$38(a1)
040967DC: 2340003c                 move.l  d0,$3C(a1)
040967E0: 237c04001b2c0024         move.l  #$4001B2C,$24(a1)
040967E8: 236e00100028             move.l  $10(a6),$28(a1)
040967EE: 4e5e                     unlk    a6
040967F0: 4e75                     rts
