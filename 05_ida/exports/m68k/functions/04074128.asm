04074128: 4856                     pea     (a6)
0407412A: 2c4f                     movea.l sp,a6
0407412C: 42a7                     clr.l   -(sp)
0407412E: 2f2e000c                 move.l  $C(a6),-(sp)
04074132: 306e000a                 movea.w $A(a6),a0
04074136: 2f08                     move.l  a0,-(sp)
04074138: 61ff00000024             bsr.l   _np_select_common
0407413E: 4e5e                     unlk    a6
04074140: 4e75                     rts
