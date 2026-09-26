0403242C: 4856                     pea     (a6)
0403242E: 2c4f                     movea.l sp,a6
04032430: 206e0008                 movea.l 8(a6),a0
04032434: 226e000c                 movea.l $C(a6),a1
04032438: 2068002e                 movea.l $2E(a0),a0
0403243C: 20280036                 move.l  $36(a0),d0
04032440: 6604                     bne.s   loc_4032446
04032442: 7002                     moveq   #2,d0
04032444: 6016                     bra.s   loc_403245C
04032446: 2069001c                 movea.l $1C(a1),a0
0403244A: 2f2e0014                 move.l  $14(a6),-(sp)
0403244E: 2f2e0010                 move.l  $10(a6),-(sp)
04032452: 2f09                     move.l  a1,-(sp)
04032454: 2f00                     move.l  d0,-(sp)
04032456: 2068002c                 movea.l $2C(a0),a0
0403245A: 4e90                     jsr     (a0)
0403245C: 4e5e                     unlk    a6
0403245E: 4e75                     rts
