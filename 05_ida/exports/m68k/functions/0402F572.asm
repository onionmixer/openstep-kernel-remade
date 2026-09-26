0402F572: 4e56ffd0                 link    a6,#-$30
0402F576: 206e0008                 movea.l arg_0(a6),a0
0402F57A: 7201                     moveq   #1,d1
0402F57C: 2d41ffd4                 move.l  d1,var_2C(a6)
0402F580: 42aeffd8                 clr.l   var_28(a6)
0402F584: 2d68001effdc             move.l  $1E(a0),var_24(a6)
0402F58A: 2d680022ffe0             move.l  $22(a0),var_20(a6)
0402F590: 2d680026ffe4             move.l  $26(a0),var_1C(a6)
0402F596: 2d41ffe8                 move.l  d1,var_18(a6)
0402F59A: 22680006                 movea.l 6(a0),a1
0402F59E: 486effd0                 pea     var_30(a6)
0402F5A2: 2f08                     move.l  a0,-(sp)
0402F5A4: 2069000c                 movea.l $C(a1),a0
0402F5A8: 4e90                     jsr     (a0)
0402F5AA: 4e5e                     unlk    a6
0402F5AC: 4e75                     rts
