0404C44A: 4856                     pea     (a6)
0404C44C: 2c4f                     movea.l sp,a6
0404C44E: 226e0008                 movea.l 8(a6),a1
0404C452: 206e000c                 movea.l $C(a6),a0
0404C456: 20a9000c                 move.l  $C(a1),(a0)
0404C45A: 4280                     clr.l   d0
0404C45C: 4e5e                     unlk    a6
0404C45E: 4e75                     rts
