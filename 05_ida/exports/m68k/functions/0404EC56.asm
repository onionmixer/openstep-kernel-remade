0404EC56: 4856                     pea     (a6)
0404EC58: 2c4f                     movea.l sp,a6
0404EC5A: 0cae040b67d80008         cmpi.l  #$40B67D8,8(a6)
0404EC62: 660c                     bne.s   loc_404EC70
0404EC64: 2f2e000c                 move.l  $C(a6),-(sp)
0404EC68: 61ff0004205a             bsr.l   _PMGetPowerStatus
0404EC6E: 6002                     bra.s   loc_404EC72
0404EC70: 7016                     moveq   #$16,d0
0404EC72: 4e5e                     unlk    a6
0404EC74: 4e75                     rts
