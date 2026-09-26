040493A0: 4856                     pea     (a6)
040493A2: 2c4f                     movea.l sp,a6
040493A4: 2f02                     move.l  d2,-(sp)
040493A6: 206e0008                 movea.l 8(a6),a0
040493AA: 40c0                     move    sr,d0
040493AC: 46fc2300                 move    #$2300,sr
040493B0: 48c0                     ext.l   d0
040493B2: 7401                     moveq   #1,d2
040493B4: 85a80048                 or.l    d2,$48(a0)
040493B8: 40c1                     move    sr,d1
040493BA: 46c0                     move    d0,sr
040493BC: 242efffc                 move.l  -4(a6),d2
040493C0: 4e5e                     unlk    a6
040493C2: 4e75                     rts
