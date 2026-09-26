04073910: 4856                     pea     (a6)
04073912: 2c4f                     movea.l sp,a6
04073914: 42a7                     clr.l   -(sp)
04073916: 2f2e000c                 move.l  $C(a6),-(sp)
0407391A: 306e000a                 movea.w $A(a6),a0
0407391E: 2f08                     move.l  a0,-(sp)
04073920: 61ff00000024             bsr.l   _np_open_common
04073926: 4e5e                     unlk    a6
04073928: 4e75                     rts
