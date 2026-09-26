0405278A: 4856                     pea     (a6)
0405278C: 2c4f                     movea.l sp,a6
0405278E: 2079040b5648             movea.l (_active_threads).l,a0
04052794: 2068000c                 movea.l $C(a0),a0
04052798: 20280008                 move.l  8(a0),d0
0405279C: 4e5e                     unlk    a6
0405279E: 4e75                     rts
