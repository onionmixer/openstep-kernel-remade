04043218: 4856                     pea     (a6)
0404321A: 2c4f                     movea.l sp,a6
0404321C: 2f0a                     move.l  a2,-(sp)
0404321E: 206e0008                 movea.l 8(a6),a0
04043222: 226e000c                 movea.l $C(a6),a1
04043226: 246e0010                 movea.l $10(a6),a2
0404322A: 20680004                 movea.l 4(a0),a0
0404322E: 4a88                     tst.l   a0
04043230: 6706                     beq.s   loc_4043238
04043232: 22a80010                 move.l  $10(a0),(a1)
04043236: 2488                     move.l  a0,(a2)
04043238: 4a88                     tst.l   a0
0404323A: 56c0                     sne     d0
0404323C: 49c0                     extb.l  d0
0404323E: 4480                     neg.l   d0
04043240: 246efffc                 movea.l -4(a6),a2
04043244: 4e5e                     unlk    a6
04043246: 4e75                     rts
