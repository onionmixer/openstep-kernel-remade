0401CCD2: 4856                     pea     (a6)
0401CCD4: 2c4f                     movea.l sp,a6
0401CCD6: 206e0008                 movea.l 8(a6),a0
0401CCDA: 216e000c004a             move.l  $C(a6),$4A(a0)
0401CCE0: 4e5e                     unlk    a6
0401CCE2: 4e75                     rts
