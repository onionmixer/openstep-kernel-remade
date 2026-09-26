0401C186: 4856                     pea     (a6)
0401C188: 2c4f                     movea.l sp,a6
0401C18A: 48780600                 pea     ($600).w
0401C18E: 61ff00000770             bsr.l   _nb_alloc
0401C194: 4e5e                     unlk    a6
0401C196: 4e75                     rts
