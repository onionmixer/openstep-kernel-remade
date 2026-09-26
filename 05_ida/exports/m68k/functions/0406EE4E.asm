0406EE4E: 4856                     pea     (a6)
0406EE50: 2c4f                     movea.l sp,a6
0406EE52: 202e0008                 move.l  8(a6),d0
0406EE56: 41f9040b13c6             lea     (_fd_density_info).l,a0
0406EE5C: 4a90                     tst.l   (a0)
0406EE5E: 6712                     beq.s   loc_406EE72
0406EE60: b090                     cmp.l   (a0),d0
0406EE62: 6606                     bne.s   loc_406EE6A
0406EE64: 20280004                 move.l  4(a0),d0
0406EE68: 600a                     bra.s   loc_406EE74
0406EE6A: 5048                     addq.w  #8,a0
0406EE6C: 5848                     addq.w  #4,a0
0406EE6E: 4a90                     tst.l   (a0)
0406EE70: 66ee                     bne.s   loc_406EE60
0406EE72: 4280                     clr.l   d0
0406EE74: 4e5e                     unlk    a6
0406EE76: 4e75                     rts
