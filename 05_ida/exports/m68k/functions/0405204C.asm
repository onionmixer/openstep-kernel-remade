0405204C: 4856                     pea     (a6)
0405204E: 2c4f                     movea.l sp,a6
04052050: 206e0008                 movea.l 8(a6),a0
04052054: 4a88                     tst.l   a0
04052056: 6702                     beq.s   loc_405205A
04052058: 5290                     addq.l  #1,(a0)
0405205A: 4e5e                     unlk    a6
0405205C: 4e75                     rts
