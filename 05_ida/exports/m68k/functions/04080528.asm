04080528: 4856                     pea     (a6)
0408052A: 2c4f                     movea.l sp,a6
0408052C: 7001                     moveq   #1,d0
0408052E: 4840                     swap    d0
04080530: 4aae0008                 tst.l   8(a6)
04080534: 6604                     bne.s   loc_408053A
04080536: 700c                     moveq   #$C,d0
04080538: 4840                     swap    d0
0408053A: 4e5e                     unlk    a6
0408053C: 4e75                     rts
