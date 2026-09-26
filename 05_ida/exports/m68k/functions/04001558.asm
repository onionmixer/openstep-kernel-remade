04001558: 4e560000                 link    a6,#0
0400155C: 206e0008                 movea.l arg_0(a6),a0
04001560: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04001568: 6706                     beq.s   loc_4001570
0400156A: 4e71                     nop
0400156C: f4f0                     cpushp  bc,(a0)
0400156E: 600a                     bra.s   loc_400157A
04001570: 2039040ad964             move.l  (_cache).l,d0
04001576: 4e7b0002                 movec   d0,cacr
0400157A: 4e5e                     unlk    a6
0400157C: 4e75                     rts
