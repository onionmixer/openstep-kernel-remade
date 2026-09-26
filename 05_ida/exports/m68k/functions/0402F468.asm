0402F468: 4e56ffd0                 link    a6,#-$30
0402F46C: 206e0008                 movea.l arg_0(a6),a0
0402F470: 7201                     moveq   #1,d1
0402F472: 2d41ffd4                 move.l  d1,var_2C(a6)
0402F476: 42aeffd8                 clr.l   var_28(a6)
0402F47A: 2d68001effdc             move.l  $1E(a0),var_24(a6)
0402F480: 2d680022ffe0             move.l  $22(a0),var_20(a6)
0402F486: 2d680026ffe4             move.l  $26(a0),var_1C(a6)
0402F48C: 42aeffe8                 clr.l   var_18(a6)
0402F490: 2d6e0010ffec             move.l  arg_8(a6),var_14(a6)
0402F496: 2d6e000cfff0             move.l  arg_4(a6),var_10(a6)
0402F49C: 22680006                 movea.l 6(a0),a1
0402F4A0: 486effd0                 pea     var_30(a6)
0402F4A4: 2f08                     move.l  a0,-(sp)
0402F4A6: 2069000c                 movea.l $C(a1),a0
0402F4AA: 4e90                     jsr     (a0)
0402F4AC: 4e5e                     unlk    a6
0402F4AE: 4e75                     rts
