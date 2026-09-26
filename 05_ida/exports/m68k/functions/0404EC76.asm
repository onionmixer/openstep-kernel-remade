0404EC76: 4856                     pea     (a6)
0404EC78: 2c4f                     movea.l sp,a6
0404EC7A: 0cae040b67d80008         cmpi.l  #$40B67D8,8(a6)
0404EC82: 6610                     bne.s   loc_404EC94
0404EC84: 2f2e0010                 move.l  $10(a6),-(sp)
0404EC88: 2f2e000c                 move.l  $C(a6),-(sp)
0404EC8C: 61ff00042056             bsr.l   _PMSetPowerManagement
0404EC92: 6002                     bra.s   loc_404EC96
0404EC94: 7016                     moveq   #$16,d0
0404EC96: 4e5e                     unlk    a6
0404EC98: 4e75                     rts
