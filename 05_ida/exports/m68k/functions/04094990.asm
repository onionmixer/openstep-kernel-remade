04094990: 4856                     pea     (a6)
04094992: 2c4f                     movea.l sp,a6
04094994: 2f02                     move.l  d2,-(sp)
04094996: 40c1                     move    sr,d1
04094998: 46fc2600                 move    #$2600,sr
0409499C: 48c1                     ext.l   d1
0409499E: 2079040b651c             movea.l (_scr2).l,a0
040949A4: 2010                     move.l  (a0),d0
040949A6: 7401                     moveq   #1,d2
040949A8: 8082                     or.l    d2,d0
040949AA: 2080                     move.l  d0,(a0)
040949AC: 40c0                     move    sr,d0
040949AE: 46c1                     move    d1,sr
040949B0: 242efffc                 move.l  -4(a6),d2
040949B4: 4e5e                     unlk    a6
040949B6: 4e75                     rts
