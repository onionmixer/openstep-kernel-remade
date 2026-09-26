0407AA4C: 4856                     pea     (a6)
0407AA4E: 2c4f                     movea.l sp,a6
0407AA50: 23ee0008040b2014         move.l  8(a6),(_od_alert_abort).l
0407AA58: 4e5e                     unlk    a6
0407AA5A: 4e75                     rts
