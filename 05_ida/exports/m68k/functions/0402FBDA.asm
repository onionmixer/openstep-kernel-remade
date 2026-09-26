0402FBDA: 4856                     pea     (a6)
0402FBDC: 2c4f                     movea.l sp,a6
0402FBDE: 206e0008                 movea.l 8(a6),a0
0402FBE2: 226e000c                 movea.l $C(a6),a1
0402FBE6: 2f2e0010                 move.l  $10(a6),-(sp)
0402FBEA: 720c                     moveq   #$C,d1
0402FBEC: d2a8002e                 add.l   $2E(a0),d1
0402FBF0: 2f01                     move.l  d1,-(sp)
0402FBF2: 4e91                     jsr     (a1)
0402FBF4: 4e5e                     unlk    a6
0402FBF6: 4e75                     rts
