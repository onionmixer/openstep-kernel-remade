0400153E: 4e560000                 link    a6,#0
04001542: 206e0008                 movea.l arg_0(a6),a0
04001546: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
0400154E: 6704                     beq.s   loc_4001554
04001550: 4e71                     nop
04001552: f4f0                     cpushp  bc,(a0)
04001554: 4e5e                     unlk    a6
04001556: 4e75                     rts
