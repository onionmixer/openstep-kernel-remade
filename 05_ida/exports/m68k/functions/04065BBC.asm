04065BBC: 4856                     pea     (a6)
04065BBE: 2c4f                     movea.l sp,a6
04065BC0: 61ff0000cab0             bsr.l   _nbic_configure
04065BC6: 00b900038003040b56d0     ori.l   #$38003,(_intr_mask).l
04065BD0: 2079040c32ec             movea.l (_intrmask).l,a0
04065BD6: 2010                     move.l  (a0),d0
04065BD8: 008000018003             ori.l   #$18003,d0
04065BDE: 2080                     move.l  d0,(a0)
04065BE0: 4879040b2d52             pea     (_bus_dinit).l
04065BE6: 4879040b2cba             pea     (_bus_cinit).l
04065BEC: 61ff00000014             bsr.l   sub_4065C02
04065BF2: 61ff00033590             bsr.l   _setconf
04065BF8: 61ff00000724             bsr.l   _swapconf
04065BFE: 4e5e                     unlk    a6
04065C00: 4e75                     rts
