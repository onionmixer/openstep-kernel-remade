04001412: 4e560000                 link    a6,#0
04001416: 202e0008                 move.l  arg_0(a6),d0
0400141A: 206e000c                 movea.l arg_4(a6),a0
0400141E: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04001426: 6710                     beq.s   loc_4001438
04001428: 4e7a1001                 movec   dfc,d1
0400142C: 4e7b0001                 movec   d0,dfc
04001430: f568                     ptestr  (a0)
04001432: 4e7b1001                 movec   d1,dfc
04001436: 6004                     bra.s   loc_400143C
04001438: f0102208                 ploadr  d0,(a0)
0400143C: 4e5e                     unlk    a6
0400143E: 4e75                     rts
