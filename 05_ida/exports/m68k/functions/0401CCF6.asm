0401CCF6: 4856                     pea     (a6)
0401CCF8: 2c4f                     movea.l sp,a6
0401CCFA: 206e0008                 movea.l 8(a6),a0
0401CCFE: 216e000c004e             move.l  $C(a6),$4E(a0)
0401CD04: 4e5e                     unlk    a6
0401CD06: 4e75                     rts
