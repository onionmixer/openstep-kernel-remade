0407392A: 4856                     pea     (a6)
0407392C: 2c4f                     movea.l sp,a6
0407392E: 48780001                 pea     (1).w
04073932: 2f2e000c                 move.l  $C(a6),-(sp)
04073936: 306e000a                 movea.w $A(a6),a0
0407393A: 2f08                     move.l  a0,-(sp)
0407393C: 61ff00000008             bsr.l   _np_open_common
04073942: 4e5e                     unlk    a6
04073944: 4e75                     rts
