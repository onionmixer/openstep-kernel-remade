040800A2: 4856                     pea     (a6)
040800A4: 2c4f                     movea.l sp,a6
040800A6: 2f02                     move.l  d2,-(sp)
040800A8: 2039040b20c4             move.l  (_vol_l).l,d0
040800AE: 742b                     moveq   #$2B,d2 ; '+'
040800B0: 9480                     sub.l   d0,d2
040800B2: 2002                     move.l  d2,d0
040800B4: e180                     asl.l   #8,d0
040800B6: 2239040b20c0             move.l  (_vol_r).l,d1
040800BC: 742b                     moveq   #$2B,d2 ; '+'
040800BE: 9481                     sub.l   d1,d2
040800C0: 2202                     move.l  d2,d1
040800C2: 8081                     or.l    d1,d0
040800C4: 242efffc                 move.l  -4(a6),d2
040800C8: 4e5e                     unlk    a6
040800CA: 4e75                     rts
