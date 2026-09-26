0402E46C: 4856                     pea     (a6)
0402E46E: 2c4f                     movea.l sp,a6
0402E470: 42a7                     clr.l   -(sp)
0402E472: 2f2e0024                 move.l  $24(a6),-(sp)
0402E476: 2f2e0020                 move.l  $20(a6),-(sp)
0402E47A: 2f2e001c                 move.l  $1C(a6),-(sp)
0402E47E: 2f2e0018                 move.l  $18(a6),-(sp)
0402E482: 2f2e0014                 move.l  $14(a6),-(sp)
0402E486: 2f2e0010                 move.l  $10(a6),-(sp)
0402E48A: 2f2e000c                 move.l  $C(a6),-(sp)
0402E48E: 2f2e0008                 move.l  8(a6),-(sp)
0402E492: 61fffffff9fc             bsr.l   _clntkudp_callit_addr
0402E498: 4e5e                     unlk    a6
0402E49A: 4e75                     rts
