04052778: 4856                     pea     (a6)
0405277A: 2c4f                     movea.l sp,a6
0405277C: 2079040b5648             movea.l (_active_threads).l,a0
04052782: 2028000c                 move.l  $C(a0),d0
04052786: 4e5e                     unlk    a6
04052788: 4e75                     rts
