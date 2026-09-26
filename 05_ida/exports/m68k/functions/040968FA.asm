040968FA: 4856                     pea     (a6)
040968FC: 2c4f                     movea.l sp,a6
040968FE: 4879040ac96a             pea     (aPcb).l; "pcb"
04096904: 42a7                     clr.l   -(sp)
04096906: 48786800                 pea     ($6800).w
0409690A: 2f3c00034000             move.l  #$34000,-(sp)
04096910: 487801a0                 pea     ($1A0).w
04096914: 61fffffbe6cc             bsr.l   _zinit
0409691A: 23c0040c9780             move.l  d0,(_pcb_zone).l
04096920: 4e5e                     unlk    a6
04096922: 4e75                     rts
