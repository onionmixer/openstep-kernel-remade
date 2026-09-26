04092DF6: 4e560000                 link    a6,#0
04092DFA: 206e0008                 movea.l arg_0(a6),a0
04092DFE: 226e000c                 movea.l arg_4(a6),a1
04092E02: 202e0010                 move.l  arg_8(a6),d0
04092E06: 5380                     subq.l  #1,d0
04092E08: 12d8                     move.b  (a0)+,(a1)+
04092E0A: 51c8fffc                 dbf     d0,loc_4092E08
04092E0E: 4e5e                     unlk    a6
04092E10: 4e75                     rts
