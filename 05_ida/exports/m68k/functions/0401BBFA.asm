0401BBFA: 4856                     pea     (a6)
0401BBFC: 2c4f                     movea.l sp,a6
0401BBFE: 206e000c                 movea.l $C(a6),a0
0401BC02: 4290                     clr.l   (a0)
0401BC04: 42a80004                 clr.l   4(a0)
0401BC08: 4e5e                     unlk    a6
0401BC0A: 4e75                     rts
