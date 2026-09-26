04096924: 4856                     pea     (a6)
04096926: 2c4f                     movea.l sp,a6
04096928: 2f0a                     move.l  a2,-(sp)
0409692A: 246e0008                 movea.l 8(a6),a2
0409692E: 2f39040c9780             move.l  (_pcb_zone).l,-(sp)
04096934: 61fffffbf220             bsr.l   _zalloc
0409693A: 25400024                 move.l  d0,$24(a2)
0409693E: 487801a0                 pea     ($1A0).w
04096942: 2f00                     move.l  d0,-(sp)
04096944: 61ffffffc4cc             bsr.l   _bzero
0409694A: 246efffc                 movea.l -4(a6),a2
0409694E: 4e5e                     unlk    a6
04096950: 4e75                     rts
