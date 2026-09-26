0400ABB0: 4856                     pea     (a6)
0400ABB2: 2c4f                     movea.l sp,a6
0400ABB4: 2f0a                     move.l  a2,-(sp)
0400ABB6: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400ABBC: 24680024                 movea.l $24(a0),a2
0400ABC0: 61ffffffd00e             bsr.l   _suser
0400ABC6: 4a80                     tst.l   d0
0400ABC8: 6706                     beq.s   loc_400ABD0
0400ABCA: 23d2040b5cb0             move.l  (a2),(_hostid).l
0400ABD0: 246efffc                 movea.l -4(a6),a2
0400ABD4: 4e5e                     unlk    a6
0400ABD6: 4e75                     rts
