04072282: 4856                     pea     (a6)
04072284: 2c4f                     movea.l sp,a6
04072286: 42a7                     clr.l   -(sp)
04072288: 2f2e000c                 move.l  $C(a6),-(sp)
0407228C: 306e000a                 movea.w $A(a6),a0
04072290: 2f08                     move.l  a0,-(sp)
04072292: 61ff00000024             bsr.l   _mmrw
04072298: 4e5e                     unlk    a6
0407229A: 4e75                     rts
