0404DFC2: 4856                     pea     (a6)
0404DFC4: 2c4f                     movea.l sp,a6
0404DFC6: 206e0008                 movea.l 8(a6),a0
0404DFCA: 2050                     movea.l (a0),a0
0404DFCC: 216e000c0014             move.l  $C(a6),$14(a0)
0404DFD2: 4e5e                     unlk    a6
0404DFD4: 4e75                     rts
