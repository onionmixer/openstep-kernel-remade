0407C070: 4856                     pea     (a6)
0407C072: 2c4f                     movea.l sp,a6
0407C074: 226e0008                 movea.l 8(a6),a1
0407C078: 20690018                 movea.l $18(a1),a0
0407C07C: 7201                     moveq   #1,d1
0407C07E: b2b9040c5bf4             cmp.l   (_scsi_ndevices).l,d1
0407C084: 6606                     bne.s   loc_407C08C
0407C086: 022900ef0024             andi.b  #$EF,$24(a1)
0407C08C: 20680014                 movea.l $14(a0),a0
0407C090: 2f09                     move.l  a1,-(sp)
0407C092: 2050                     movea.l (a0),a0
0407C094: 4e90                     jsr     (a0)
0407C096: 4e5e                     unlk    a6
0407C098: 4e75                     rts
