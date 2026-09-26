04001498: 4e560000                 link    a6,#0
0400149C: 206e0008                 movea.l arg_0(a6),a0
040014A0: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
040014A8: 670c                     beq.s   loc_40014B6
040014AA: 2010                     move.l  (a0),d0
040014AC: 4e7b0005                 movec   d0,itt1
040014B0: 4e7b0007                 movec   d0,dtt1
040014B4: 6004                     bra.s   loc_40014BA
040014B6: f0100c00                 pmove   (a0),tt1
040014BA: 4e5e                     unlk    a6
040014BC: 4e75                     rts
