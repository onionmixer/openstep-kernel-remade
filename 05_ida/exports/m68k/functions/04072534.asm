04072534: 242efffc                 move.l  -4(a6),d2
04072538: 246efff8                 movea.l -8(a6),a2
0407253C: 222efff4                 move.l  -$C(a6),d1
04072540: 40c0                     move    sr,d0
04072542: 46c1                     move    d1,sr
04072544: 4280                     clr.l   d0
04072546: 4e5e                     unlk    a6
04072548: 4e75                     rts
