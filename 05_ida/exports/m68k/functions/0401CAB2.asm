0401CAB2: 4856                     pea     (a6)
0401CAB4: 2c4f                     movea.l sp,a6
0401CAB6: 226e0008                 movea.l 8(a6),a1
0401CABA: 20690032                 movea.l $32(a1),a0
0401CABE: 4a88                     tst.l   a0
0401CAC0: 670e                     beq.s   loc_401CAD0
0401CAC2: 2f2e0010                 move.l  $10(a6),-(sp)
0401CAC6: 2f2e000c                 move.l  $C(a6),-(sp)
0401CACA: 2f09                     move.l  a1,-(sp)
0401CACC: 4e90                     jsr     (a0)
0401CACE: 6002                     bra.s   loc_401CAD2
0401CAD0: 7006                     moveq   #6,d0
0401CAD2: 4e5e                     unlk    a6
0401CAD4: 4e75                     rts
