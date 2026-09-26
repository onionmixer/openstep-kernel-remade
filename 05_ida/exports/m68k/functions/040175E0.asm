040175E0: 4856                     pea     (a6)
040175E2: 2c4f                     movea.l sp,a6
040175E4: 2f02                     move.l  d2,-(sp)
040175E6: 206e0008                 movea.l 8(a6),a0
040175EA: 242e000c                 move.l  $C(a6),d2
040175EE: 6d10                     blt.s   loc_4017600
040175F0: 2002                     move.l  d2,d0
040175F2: e680                     asr.l   #3,d0
040175F4: 2200                     move.l  d0,d1
040175F6: e781                     asl.l   #3,d1
040175F8: 9481                     sub.l   d1,d2
040175FA: 2202                     move.l  d2,d1
040175FC: 03b00800                 bclr    d1,(a0,d0.l)
04017600: 242efffc                 move.l  -4(a6),d2
04017604: 4e5e                     unlk    a6
04017606: 4e75                     rts
