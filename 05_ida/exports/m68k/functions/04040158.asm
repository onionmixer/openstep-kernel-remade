04040158: 4856                     pea     (a6)
0404015A: 2c4f                     movea.l sp,a6
0404015C: 206e0008                 movea.l 8(a6),a0
04040160: 5290                     addq.l  #1,(a0)
04040162: 4e5e                     unlk    a6
04040164: 4e75                     rts
