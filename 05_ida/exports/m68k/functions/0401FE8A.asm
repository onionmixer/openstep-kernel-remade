0401FE8A: 4856                     pea     (a6)
0401FE8C: 2c4f                     movea.l sp,a6
0401FE8E: 2f0a                     move.l  a2,-(sp)
0401FE90: 246e0008                 movea.l 8(a6),a2
0401FE94: 202a0020                 move.l  $20(a2),d0
0401FE98: 670c                     beq.s   loc_401FEA6
0401FE9A: 2f00                     move.l  d0,-(sp)
0401FE9C: 61ffffffda6c             bsr.l   _rtfree
0401FEA2: 42aa0020                 clr.l   $20(a2)
0401FEA6: 246efffc                 movea.l -4(a6),a2
0401FEAA: 4e5e                     unlk    a6
0401FEAC: 4e75                     rts
