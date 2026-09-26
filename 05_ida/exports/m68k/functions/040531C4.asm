040531C4: 4856                     pea     (a6)
040531C6: 2c4f                     movea.l sp,a6
040531C8: 2f02                     move.l  d2,-(sp)
040531CA: 206e0008                 movea.l 8(a6),a0
040531CE: 40c0                     move    sr,d0
040531D0: 46fc2300                 move    #$2300,sr
040531D4: 48c0                     ext.l   d0
040531D6: 52a8003c                 addq.l  #1,$3C(a0)
040531DA: 7402                     moveq   #2,d2
040531DC: 85a80048                 or.l    d2,$48(a0)
040531E0: 40c1                     move    sr,d1
040531E2: 46c0                     move    d0,sr
040531E4: 242efffc                 move.l  -4(a6),d2
040531E8: 4e5e                     unlk    a6
040531EA: 4e75                     rts
