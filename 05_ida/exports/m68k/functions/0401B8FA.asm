0401B8FA: 4856                     pea     (a6)
0401B8FC: 2c4f                     movea.l sp,a6
0401B8FE: 206e0008                 movea.l 8(a6),a0
0401B902: 7039                     moveq   #$39,d0 ; '9'
0401B904: 50d8                     st      (a0)+
0401B906: 51c8fffc                 dbf     d0,loc_401B904
0401B90A: 4240                     clr.w   d0
0401B90C: 5380                     subq.l  #1,d0
0401B90E: 64f4                     bcc.s   loc_401B904
0401B910: 4e5e                     unlk    a6
0401B912: 4e75                     rts
