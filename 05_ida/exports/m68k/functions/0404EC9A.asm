0404EC9A: 4856                     pea     (a6)
0404EC9C: 2c4f                     movea.l sp,a6
0404EC9E: 0cae040b67d80008         cmpi.l  #$40B67D8,8(a6)
0404ECA6: 6608                     bne.s   loc_404ECB0
0404ECA8: 61ff00042044             bsr.l   _PMRestoreDefaults
0404ECAE: 6002                     bra.s   loc_404ECB2
0404ECB0: 7016                     moveq   #$16,d0
0404ECB2: 4e5e                     unlk    a6
0404ECB4: 4e75                     rts
