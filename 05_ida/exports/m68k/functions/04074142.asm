04074142: 4856                     pea     (a6)
04074144: 2c4f                     movea.l sp,a6
04074146: 48780001                 pea     (1).w
0407414A: 2f2e000c                 move.l  $C(a6),-(sp)
0407414E: 306e000a                 movea.w $A(a6),a0
04074152: 2f08                     move.l  a0,-(sp)
04074154: 61ff00000008             bsr.l   _np_select_common
0407415A: 4e5e                     unlk    a6
0407415C: 4e75                     rts
