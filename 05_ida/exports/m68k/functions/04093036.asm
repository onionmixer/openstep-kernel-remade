04093036: 4e560000                 link    a6,#0
0409303A: 206e0008                 movea.l arg_0(a6),a0
0409303E: 226e000c                 movea.l arg_4(a6),a1
04093042: 222e0010                 move.l  arg_8(a6),d1
04093046: 2008                     move.l  a0,d0
04093048: 5381                     subq.l  #1,d1
0409304A: 6d0c                     blt.s   loc_4093058
0409304C: 10d9                     move.b  (a1)+,(a0)+
0409304E: 66f8                     bne.s   loc_4093048
04093050: 6002                     bra.s   loc_4093054
04093052: 4218                     clr.b   (a0)+
04093054: 5381                     subq.l  #1,d1
04093056: 6cfa                     bge.s   loc_4093052
04093058: 4e5e                     unlk    a6
0409305A: 4e75                     rts
