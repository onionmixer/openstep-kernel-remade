0400146E: 4e560000                 link    a6,#0
04001472: 206e0008                 movea.l arg_0(a6),a0
04001476: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
0400147E: 6710                     beq.s   loc_4001490
04001480: 4e71                     nop
04001482: f4f8                     cpusha  bc
04001484: f510                     pflushan
04001486: 20280004                 move.l  4(a0),d0
0400148A: 4e7b0806                 movec   d0,urp
0400148E: 6004                     bra.s   loc_4001494
04001490: f0104c00                 pmove   (a0),crp
04001494: 4e5e                     unlk    a6
04001496: 4e75                     rts
