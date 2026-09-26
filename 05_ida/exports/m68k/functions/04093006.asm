04093006: 4e560000                 link    a6,#0
0409300A: 206e0008                 movea.l arg_0(a6),a0
0409300E: 202e000c                 move.l  arg_4(a6),d0
04093012: 6716                     beq.s   loc_409302A
04093014: 1218                     move.b  (a0)+,d1
04093016: 670c                     beq.s   loc_4093024
04093018: b001                     cmp.b   d1,d0
0409301A: 66f8                     bne.s   loc_4093014
0409301C: 5348                     subq.w  #1,a0
0409301E: 2008                     move.l  a0,d0
04093020: 4e5e                     unlk    a6
04093022: 4e75                     rts
04093024: 7000                     moveq   #0,d0
04093026: 4e5e                     unlk    a6
04093028: 4e75                     rts
0409302A: 4a18                     tst.b   (a0)+
0409302C: 66fc                     bne.s   loc_409302A
0409302E: 5348                     subq.w  #1,a0
04093030: 2008                     move.l  a0,d0
04093032: 4e5e                     unlk    a6
04093034: 4e75                     rts
