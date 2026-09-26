04002238: 4e560000                 link    a6,#0
0400223C: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04002244: 6706                     beq.s   loc_400224C
04002246: 4e71                     nop
04002248: f4f8                     cpusha  bc
0400224A: 600a                     bra.s   loc_4002256
0400224C: 2039040ad964             move.l  (_cache).l,d0
04002252: 4e7b0002                 movec   d0,cacr
04002256: 4e5e                     unlk    a6
04002258: 4e75                     rts
