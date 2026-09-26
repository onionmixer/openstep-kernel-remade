0402F52C: 4e56ffd0                 link    a6,#-$30
0402F530: 226e0008                 movea.l arg_0(a6),a1
0402F534: 7201                     moveq   #1,d1
0402F536: 2d41ffd4                 move.l  d1,var_2C(a6)
0402F53A: 2d41ffd8                 move.l  d1,var_28(a6)
0402F53E: 2d41ffdc                 move.l  d1,var_24(a6)
0402F542: 2d6e000cffe0             move.l  arg_4(a6),var_20(a6)
0402F548: 20690006                 movea.l 6(a1),a0
0402F54C: 486effd0                 pea     var_30(a6)
0402F550: 2f09                     move.l  a1,-(sp)
0402F552: 2068000c                 movea.l $C(a0),a0
0402F556: 4e90                     jsr     (a0)
0402F558: 4e5e                     unlk    a6
0402F55A: 4e75                     rts
