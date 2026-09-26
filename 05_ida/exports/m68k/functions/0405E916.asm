0405E916: 4856                     pea     (a6)
0405E918: 2c4f                     movea.l sp,a6
0405E91A: 2f0a                     move.l  a2,-(sp)
0405E91C: 246e000c                 movea.l $C(a6),a2
0405E920: 2f0a                     move.l  a2,-(sp)
0405E922: 2f2e0008                 move.l  8(a6),-(sp)
0405E926: 61ffffffe7c6             bsr.l   _vm_fault_unwire
0405E92C: 426a0026                 clr.w   $26(a2)
0405E930: 246efffc                 movea.l -4(a6),a2
0405E934: 4e5e                     unlk    a6
0405E936: 4e75                     rts
