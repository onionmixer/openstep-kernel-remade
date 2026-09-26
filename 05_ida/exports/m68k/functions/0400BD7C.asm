0400BD7C: 4856                     pea     (a6)
0400BD7E: 2c4f                     movea.l sp,a6
0400BD80: 42a7                     clr.l   -(sp)
0400BD82: 42a7                     clr.l   -(sp)
0400BD84: 2f2e0008                 move.l  8(a6),-(sp)
0400BD88: 61ff00000022             bsr.l   sub_400BDAC
0400BD8E: 4280                     clr.l   d0
0400BD90: 4e5e                     unlk    a6
0400BD92: 4e75                     rts
