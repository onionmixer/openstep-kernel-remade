04001440: 4e560000                 link    a6,#0
04001444: 202e0008                 move.l  arg_0(a6),d0
04001448: 206e000c                 movea.l arg_4(a6),a0
0400144C: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04001454: 6710                     beq.s   loc_4001466
04001456: 4e7a1001                 movec   dfc,d1
0400145A: 4e7b0001                 movec   d0,dfc
0400145E: f548                     ptestw  (a0)
04001460: 4e7b1001                 movec   d1,dfc
04001464: 6004                     bra.s   loc_400146A
04001466: f0102008                 ploadw  d0,(a0)
0400146A: 4e5e                     unlk    a6
0400146C: 4e75                     rts
