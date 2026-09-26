040411E6: 4856                     pea     (a6)
040411E8: 2c4f                     movea.l sp,a6
040411EA: 206e0008                 movea.l 8(a6),a0
040411EE: 52a80014                 addq.l  #1,$14(a0)
040411F2: 52a80018                 addq.l  #1,$18(a0)
040411F6: 5290                     addq.l  #1,(a0)
040411F8: 2008                     move.l  a0,d0
040411FA: 4e5e                     unlk    a6
040411FC: 4e75                     rts
