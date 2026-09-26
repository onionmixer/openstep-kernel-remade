040A0CC0: 518f                     subq.l  #8,sp
040A0CC2: 2e88                     move.l  a0,(sp)
040A0CC4: 4e7a8801                 movec   vbr,a0
040A0CC8: 2f6800240004             move.l  $24(a0),8+var_4(sp)
040A0CCE: 205f                     movea.l (sp)+,a0
040A0CD0: 4e75                     rts
