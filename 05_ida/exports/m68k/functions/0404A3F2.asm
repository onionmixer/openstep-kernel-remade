0404A3F2: 4856                     pea     (a6)
0404A3F4: 2c4f                     movea.l sp,a6
0404A3F6: 202e0008                 move.l  8(a6),d0
0404A3FA: 670e                     beq.s   loc_404A40A
0404A3FC: 2040                     movea.l d0,a0
0404A3FE: 5148                     subq.w  #8,a0
0404A400: 2f10                     move.l  (a0),-(sp)
0404A402: 2f08                     move.l  a0,-(sp)
0404A404: 61fffffffebe             bsr.l   _kfree
0404A40A: 4e5e                     unlk    a6
0404A40C: 4e75                     rts
