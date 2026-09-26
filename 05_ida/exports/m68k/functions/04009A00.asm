04009A00: 4856                     pea     (a6)
04009A02: 2c4f                     movea.l sp,a6
04009A04: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04009A0A: 20680024                 movea.l $24(a0),a0
04009A0E: 48780004                 pea     (4).w
04009A12: 2f10                     move.l  (a0),-(sp)
04009A14: 2079040b57d0             movea.l (_active_u).l,a0
04009A1A: 7218                     moveq   #$18,d1
04009A1C: d290                     add.l   (a0),d1
04009A1E: 2f01                     move.l  d1,-(sp)
04009A20: 61ffffff7c3c             bsr.l   _copyoutmsg
04009A26: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04009A2C: 11400064                 move.b  d0,$64(a0)
04009A30: 4e5e                     unlk    a6
04009A32: 4e75                     rts
