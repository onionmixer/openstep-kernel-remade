04053D8A: 4856                     pea     (a6)
04053D8C: 2c4f                     movea.l sp,a6
04053D8E: 2039040b5648             move.l  (_active_threads).l,d0
04053D94: 4e5e                     unlk    a6
04053D96: 4e75                     rts
