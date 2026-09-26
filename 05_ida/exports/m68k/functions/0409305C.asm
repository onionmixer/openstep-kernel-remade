0409305C: 4e560000                 link    a6,#0
04093060: 206e0008                 movea.l arg_0(a6),a0
04093064: 226e000c                 movea.l arg_4(a6),a1
04093068: 2008                     move.l  a0,d0
0409306A: 4a18                     tst.b   (a0)+
0409306C: 66fc                     bne.s   loc_409306A
0409306E: 5348                     subq.w  #1,a0
04093070: 10d9                     move.b  (a1)+,(a0)+
04093072: 66fc                     bne.s   loc_4093070
04093074: 4e5e                     unlk    a6
04093076: 4e75                     rts
