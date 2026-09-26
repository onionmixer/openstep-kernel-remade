04041302: 4856                     pea     (a6)
04041304: 2c4f                     movea.l sp,a6
04041306: 206e0008                 movea.l 8(a6),a0
0404130A: 52a8001c                 addq.l  #1,$1C(a0)
0404130E: 5290                     addq.l  #1,(a0)
04041310: 2008                     move.l  a0,d0
04041312: 4e5e                     unlk    a6
04041314: 4e75                     rts
