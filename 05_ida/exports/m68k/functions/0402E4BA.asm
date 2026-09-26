0402E4BA: 4856                     pea     (a6)
0402E4BC: 2c4f                     movea.l sp,a6
0402E4BE: 206e0008                 movea.l 8(a6),a0
0402E4C2: 226e000c                 movea.l $C(a6),a1
0402E4C6: 20680008                 movea.l 8(a0),a0
0402E4CA: 22e80028                 move.l  $28(a0),(a1)+
0402E4CE: 22e8002c                 move.l  $2C(a0),(a1)+
0402E4D2: 22a80030                 move.l  $30(a0),(a1)
0402E4D6: 4e5e                     unlk    a6
0402E4D8: 4e75                     rts
