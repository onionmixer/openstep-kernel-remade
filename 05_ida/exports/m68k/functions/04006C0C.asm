04006C0C: 4856                     pea     (a6)
04006C0E: 2c4f                     movea.l sp,a6
04006C10: 222e0008                 move.l  8(a6),d1
04006C14: 703f                     moveq   #$3F,d0 ; '?'
04006C16: c081                     and.l   d1,d0
04006C18: 41f9040b641c             lea     (_pidhash).l,a0
04006C1E: 22700c00                 movea.l (a0,d0.l*4),a1
04006C22: 4a89                     tst.l   a1
04006C24: 6714                     beq.s   loc_4006C3A
04006C26: 30690030                 movea.w $30(a1),a0
04006C2A: b288                     cmp.l   a0,d1
04006C2C: 6604                     bne.s   loc_4006C32
04006C2E: 2009                     move.l  a1,d0
04006C30: 600a                     bra.s   loc_4006C3C
04006C32: 2269003e                 movea.l $3E(a1),a1
04006C36: 4a89                     tst.l   a1
04006C38: 66ec                     bne.s   loc_4006C26
04006C3A: 4280                     clr.l   d0
04006C3C: 4e5e                     unlk    a6
04006C3E: 4e75                     rts
