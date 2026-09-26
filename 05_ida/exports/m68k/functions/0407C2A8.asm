0407C2A8: 4856                     pea     (a6)
0407C2AA: 2c4f                     movea.l sp,a6
0407C2AC: 206e0008                 movea.l 8(a6),a0
0407C2B0: 202e000c                 move.l  $C(a6),d0
0407C2B4: 22680018                 movea.l $18(a0),a1
0407C2B8: 0c8020006409             cmpi.l  #$20006409,d0
0407C2BE: 6718                     beq.s   loc_407C2D8
0407C2C0: 20690014                 movea.l $14(a1),a0
0407C2C4: 2f2e0014                 move.l  $14(a6),-(sp)
0407C2C8: 2f2e0010                 move.l  $10(a6),-(sp)
0407C2CC: 2f00                     move.l  d0,-(sp)
0407C2CE: 2f09                     move.l  a1,-(sp)
0407C2D0: 20680004                 movea.l 4(a0),a0
0407C2D4: 4e90                     jsr     (a0)
0407C2D6: 6018                     bra.s   loc_407C2F0
0407C2D8: 20690014                 movea.l $14(a1),a0
0407C2DC: 4879040ab571             pea     (aBusReset).l; "bus reset"
0407C2E2: 48780001                 pea     (1).w
0407C2E6: 2f09                     move.l  a1,-(sp)
0407C2E8: 20680008                 movea.l 8(a0),a0
0407C2EC: 4e90                     jsr     (a0)
0407C2EE: 4280                     clr.l   d0
0407C2F0: 4e5e                     unlk    a6
0407C2F2: 4e75                     rts
