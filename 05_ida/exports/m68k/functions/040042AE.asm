040042AE: 4856                     pea     (a6)
040042B0: 2c4f                     movea.l sp,a6
040042B2: 206e0008                 movea.l 8(a6),a0
040042B6: 22680012                 movea.l $12(a0),a1
040042BA: 2f2e0010                 move.l  $10(a6),-(sp)
040042BE: 2f2e000c                 move.l  $C(a6),-(sp)
040042C2: 2f08                     move.l  a0,-(sp)
040042C4: 20690004                 movea.l 4(a1),a0
040042C8: 4e90                     jsr     (a0)
040042CA: 4e5e                     unlk    a6
040042CC: 4e75                     rts
