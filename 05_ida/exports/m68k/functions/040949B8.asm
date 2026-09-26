040949B8: 4856                     pea     (a6)
040949BA: 2c4f                     movea.l sp,a6
040949BC: 2f02                     move.l  d2,-(sp)
040949BE: 40c1                     move    sr,d1
040949C0: 46fc2600                 move    #$2600,sr
040949C4: 48c1                     ext.l   d1
040949C6: 2079040b651c             movea.l (_scr2).l,a0
040949CC: 2010                     move.l  (a0),d0
040949CE: 74fe                     moveq   #$FFFFFFFE,d2
040949D0: c082                     and.l   d2,d0
040949D2: 2080                     move.l  d0,(a0)
040949D4: 40c0                     move    sr,d0
040949D6: 46c1                     move    d1,sr
040949D8: 242efffc                 move.l  -4(a6),d2
040949DC: 4e5e                     unlk    a6
040949DE: 4e75                     rts
