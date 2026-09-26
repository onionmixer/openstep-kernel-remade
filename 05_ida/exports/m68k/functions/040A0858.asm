040A0858: 4a80                     tst.l   d0
040A085A: 66ff00000024             bne.l   loc_40A0880
040A0860: 4a81                     tst.l   d1
040A0862: 66ff0000000a             bne.l   loc_40A086E
040A0868: 60ff00000030             bra.l   locret_40A089A
040A086E: 2f03                     move.l  d3,-(sp)
040A0870: c141                     exg     d0,d1
040A0872: edc03000                 bfffo   d0{0:32},d3
040A0876: e7a8                     lsl.l   d3,d0
040A0878: 261f                     move.l  (sp)+,d3
040A087A: 60ff0000001e             bra.l   locret_40A089A
040A0880: 48e71600                 movem.l d3/d5-d6,-(sp)
040A0884: edc03000                 bfffo   d0{0:32},d3
040A0888: e7a8                     lsl.l   d3,d0
040A088A: 2c01                     move.l  d1,d6
040A088C: e7a9                     lsl.l   d3,d1
040A088E: 7a20                     moveq   #$20,d5 ; ' '
040A0890: 9a83                     sub.l   d3,d5
040A0892: eaae                     lsr.l   d5,d6
040A0894: 8086                     or.l    d6,d0
040A0896: 4cdf0068                 movem.l (sp)+,d3/d5-d6
040A089A: 4e75                     rts
