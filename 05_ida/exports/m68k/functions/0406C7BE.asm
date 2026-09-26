0406C7BE: 4856                     pea     (a6)
0406C7C0: 2c4f                     movea.l sp,a6
0406C7C2: 206e0008                 movea.l 8(a6),a0
0406C7C6: 22680022                 movea.l $22(a0),a1
0406C7CA: 30290004                 move.w  4(a1),d0
0406C7CE: c1fc0262                 muls.w  #$262,d0
0406C7D2: 2f08                     move.l  a0,-(sp)
0406C7D4: 0680040c376c             addi.l  #$40C376C,d0
0406C7DA: 2f00                     move.l  d0,-(sp)
0406C7DC: 61ffffffed68             bsr.l   _fd_slave
0406C7E2: 4e5e                     unlk    a6
0406C7E4: 4e75                     rts
