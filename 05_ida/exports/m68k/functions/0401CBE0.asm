0401CBE0: 4856                     pea     (a6)
0401CBE2: 2c4f                     movea.l sp,a6
0401CBE4: 226e0008                 movea.l 8(a6),a1
0401CBE8: 2069003e                 movea.l $3E(a1),a0
0401CBEC: 4a88                     tst.l   a0
0401CBEE: 6706                     beq.s   loc_401CBF6
0401CBF0: 2f09                     move.l  a1,-(sp)
0401CBF2: 4e90                     jsr     (a0)
0401CBF4: 6002                     bra.s   loc_401CBF8
0401CBF6: 4280                     clr.l   d0
0401CBF8: 4e5e                     unlk    a6
0401CBFA: 4e75                     rts
