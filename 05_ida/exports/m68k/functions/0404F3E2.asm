0404F3E2: 4856                     pea     (a6)
0404F3E4: 2c4f                     movea.l sp,a6
0404F3E6: 206e0008                 movea.l 8(a6),a0
0404F3EA: 226e000c                 movea.l $C(a6),a1
0404F3EE: 20280110                 move.l  $110(a0),d0
0404F3F2: 7205                     moveq   #5,d1
0404F3F4: b280                     cmp.l   d0,d1
0404F3F6: 6704                     beq.s   loc_404F3FC
0404F3F8: 4a80                     tst.l   d0
0404F3FA: 6604                     bne.s   loc_404F400
0404F3FC: 7005                     moveq   #5,d0
0404F3FE: 600e                     bra.s   loc_404F40E
0404F400: 22a80128                 move.l  $128(a0),(a1)
0404F404: 2f11                     move.l  (a1),-(sp)
0404F406: 61fffffffedc             bsr.l   _pset_reference
0404F40C: 4280                     clr.l   d0
0404F40E: 4e5e                     unlk    a6
0404F410: 4e75                     rts
