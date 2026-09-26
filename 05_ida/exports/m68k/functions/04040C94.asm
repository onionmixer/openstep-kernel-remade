04040C94: 4856                     pea     (a6)
04040C96: 2c4f                     movea.l sp,a6
04040C98: 206e0008                 movea.l 8(a6),a0
04040C9C: 222e0010                 move.l  $10(a6),d1
04040CA0: 22680028                 movea.l $28(a0),a1
04040CA4: 41f11e00                 lea     (a1,d1.l*8),a0
04040CA8: 2010                     move.l  (a0),d0
04040CAA: 42a80004                 clr.l   4(a0)
04040CAE: 2091                     move.l  (a1),(a0)
04040CB0: 2281                     move.l  d1,(a1)
04040CB2: 4e5e                     unlk    a6
04040CB4: 4e75                     rts
