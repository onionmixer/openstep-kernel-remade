0401CAD6: 4856                     pea     (a6)
0401CAD8: 2c4f                     movea.l sp,a6
0401CADA: 226e0008                 movea.l 8(a6),a1
0401CADE: 20690036                 movea.l $36(a1),a0
0401CAE2: 4a88                     tst.l   a0
0401CAE4: 670e                     beq.s   loc_401CAF4
0401CAE6: 2f2e0010                 move.l  $10(a6),-(sp)
0401CAEA: 2f2e000c                 move.l  $C(a6),-(sp)
0401CAEE: 2f09                     move.l  a1,-(sp)
0401CAF0: 4e90                     jsr     (a0)
0401CAF2: 6002                     bra.s   loc_401CAF6
0401CAF4: 7006                     moveq   #6,d0
0401CAF6: 4e5e                     unlk    a6
0401CAF8: 4e75                     rts
