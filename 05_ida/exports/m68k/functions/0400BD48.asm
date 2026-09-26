0400BD48: 4856                     pea     (a6)
0400BD4A: 2c4f                     movea.l sp,a6
0400BD4C: 206e0008                 movea.l 8(a6),a0
0400BD50: 2f280024                 move.l  $24(a0),-(sp)
0400BD54: 3228001e                 move.w  $1E(a0),d1
0400BD58: 7007                     moveq   #7,d0
0400BD5A: c081                     and.l   d1,d0
0400BD5C: 2240                     movea.l d0,a1
0400BD5E: 48690061                 pea     $61(a1)
0400BD62: e9c11605                 bfextu  d1{24:5},d1
0400BD66: 2f01                     move.l  d1,-(sp)
0400BD68: 2f2e000c                 move.l  $C(a6),-(sp)
0400BD6C: 4879040a62fb             pea     (aSDCHardErrorSn).l; "%s%d%c: hard error sn%d "
0400BD72: 61fffffff5e4             bsr.l   _printf
0400BD78: 4e5e                     unlk    a6
0400BD7A: 4e75                     rts
