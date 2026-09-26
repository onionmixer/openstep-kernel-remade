04006C40: 4856                     pea     (a6)
04006C42: 2c4f                     movea.l sp,a6
04006C44: 206e0008                 movea.l 8(a6),a0
04006C48: 30280030                 move.w  $30(a0),d0
04006C4C: 723f                     moveq   #$3F,d1 ; '?'
04006C4E: c081                     and.l   d1,d0
04006C50: 43f9040b641c             lea     (_pidhash).l,a1
04006C56: 21710c00003e             move.l  (a1,d0.l*4),$3E(a0)
04006C5C: 23880c00                 move.l  a0,(a1,d0.l*4)
04006C60: 4e5e                     unlk    a6
04006C62: 4e75                     rts
