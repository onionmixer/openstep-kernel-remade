0404F740: 4856                     pea     (a6)
0404F742: 2c4f                     movea.l sp,a6
0404F744: 42a7                     clr.l   -(sp)
0404F746: 2f2e0010                 move.l  $10(a6),-(sp)
0404F74A: 2f2e000c                 move.l  $C(a6),-(sp)
0404F74E: 2f2e0008                 move.l  8(a6),-(sp)
0404F752: 61fffffffe44             bsr.l   _processor_set_things
0404F758: 4e5e                     unlk    a6
0404F75A: 4e75                     rts
