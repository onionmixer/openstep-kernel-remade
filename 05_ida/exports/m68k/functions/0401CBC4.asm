0401CBC4: 4856                     pea     (a6)
0401CBC6: 2c4f                     movea.l sp,a6
0401CBC8: 226e0008                 movea.l 8(a6),a1
0401CBCC: 2069002e                 movea.l $2E(a1),a0
0401CBD0: 4a88                     tst.l   a0
0401CBD2: 6706                     beq.s   loc_401CBDA
0401CBD4: 2f09                     move.l  a1,-(sp)
0401CBD6: 4e90                     jsr     (a0)
0401CBD8: 6002                     bra.s   loc_401CBDC
0401CBDA: 7006                     moveq   #6,d0
0401CBDC: 4e5e                     unlk    a6
0401CBDE: 4e75                     rts
