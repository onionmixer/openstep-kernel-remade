04050E08: 4856                     pea     (a6)
04050E0A: 2c4f                     movea.l sp,a6
04050E0C: 2f0a                     move.l  a2,-(sp)
04050E0E: 202e0008                 move.l  8(a6),d0
04050E12: 2079040b5648             movea.l (_active_threads).l,a0
04050E18: 24680030                 movea.l $30(a0),a2
04050E1C: 670a                     beq.s   loc_4050E28
04050E1E: 2f00                     move.l  d0,-(sp)
04050E20: 61ff000000da             bsr.l   _thread_dispatch
04050E26: 584f                     addq.w  #4,sp
04050E28: 40c0                     move    sr,d0
04050E2A: 46fc2000                 move    #$2000,sr
04050E2E: 4e92                     jsr     (a2)
04050E30: 246efffc                 movea.l -4(a6),a2
04050E34: 4e5e                     unlk    a6
04050E36: 4e75                     rts
