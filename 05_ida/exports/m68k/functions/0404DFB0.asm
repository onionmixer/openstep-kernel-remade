0404DFB0: 4856                     pea     (a6)
0404DFB2: 2c4f                     movea.l sp,a6
0404DFB4: 206e0008                 movea.l 8(a6),a0
0404DFB8: 2050                     movea.l (a0),a0
0404DFBA: 20280014                 move.l  $14(a0),d0
0404DFBE: 4e5e                     unlk    a6
0404DFC0: 4e75                     rts
