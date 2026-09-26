040325DA: 4856                     pea     (a6)
040325DC: 2c4f                     movea.l sp,a6
040325DE: 206e0008                 movea.l 8(a6),a0
040325E2: 2068002e                 movea.l $2E(a0),a0
040325E6: 22680036                 movea.l $36(a0),a1
040325EA: 4a89                     tst.l   a1
040325EC: 6604                     bne.s   loc_40325F2
040325EE: 7016                     moveq   #$16,d0
040325F0: 6010                     bra.s   loc_4032602
040325F2: 2069001c                 movea.l $1C(a1),a0
040325F6: 2f2e000c                 move.l  $C(a6),-(sp)
040325FA: 2f09                     move.l  a1,-(sp)
040325FC: 20680064                 movea.l $64(a0),a0
04032600: 4e90                     jsr     (a0)
04032602: 4e5e                     unlk    a6
04032604: 4e75                     rts
