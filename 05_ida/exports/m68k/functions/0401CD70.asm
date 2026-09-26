0401CD70: 4856                     pea     (a6)
0401CD72: 2c4f                     movea.l sp,a6
0401CD74: 206e0008                 movea.l 8(a6),a0
0401CD78: 2028005a                 move.l  $5A(a0),d0
0401CD7C: 4e5e                     unlk    a6
0401CD7E: 4e75                     rts
