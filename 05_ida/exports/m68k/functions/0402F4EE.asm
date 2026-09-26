0402F4EE: 4e56ffd0                 link    a6,#-$30
0402F4F2: 206e0008                 movea.l arg_0(a6),a0
0402F4F6: 7201                     moveq   #1,d1
0402F4F8: 2d41ffd4                 move.l  d1,var_2C(a6)
0402F4FC: 42aeffd8                 clr.l   var_28(a6)
0402F500: 2d68001effdc             move.l  $1E(a0),var_24(a6)
0402F506: 2d680022ffe0             move.l  $22(a0),var_20(a6)
0402F50C: 2d680026ffe4             move.l  $26(a0),var_1C(a6)
0402F512: 7204                     moveq   #4,d1
0402F514: 2d41ffe8                 move.l  d1,var_18(a6)
0402F518: 22680006                 movea.l 6(a0),a1
0402F51C: 486effd0                 pea     var_30(a6)
0402F520: 2f08                     move.l  a0,-(sp)
0402F522: 2069000c                 movea.l $C(a1),a0
0402F526: 4e90                     jsr     (a0)
0402F528: 4e5e                     unlk    a6
0402F52A: 4e75                     rts
