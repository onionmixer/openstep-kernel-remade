0404EC12: 4856                     pea     (a6)
0404EC14: 2c4f                     movea.l sp,a6
0404EC16: 0cae040b67d80008         cmpi.l  #$40B67D8,8(a6)
0404EC1E: 6610                     bne.s   loc_404EC30
0404EC20: 2f2e0010                 move.l  $10(a6),-(sp)
0404EC24: 2f2e000c                 move.l  $C(a6),-(sp)
0404EC28: 61ff0004207e             bsr.l   _PMSetPowerState
0404EC2E: 6002                     bra.s   loc_404EC32
0404EC30: 7016                     moveq   #$16,d0
0404EC32: 4e5e                     unlk    a6
0404EC34: 4e75                     rts
