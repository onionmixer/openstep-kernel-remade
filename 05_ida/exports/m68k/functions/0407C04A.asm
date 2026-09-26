0407C04A: 4856                     pea     (a6)
0407C04C: 2c4f                     movea.l sp,a6
0407C04E: 226e0008                 movea.l 8(a6),a1
0407C052: 20690010                 movea.l $10(a1),a0
0407C056: 20680018                 movea.l $18(a0),a0
0407C05A: 137c0002005a             move.b  #2,$5A(a1)
0407C060: 22680014                 movea.l $14(a0),a1
0407C064: 2f08                     move.l  a0,-(sp)
0407C066: 20690012                 movea.l $12(a1),a0
0407C06A: 4e90                     jsr     (a0)
0407C06C: 4e5e                     unlk    a6
0407C06E: 4e75                     rts
