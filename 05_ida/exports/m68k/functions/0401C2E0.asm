0401C2E0: 4856                     pea     (a6)
0401C2E2: 2c4f                     movea.l sp,a6
0401C2E4: 2f2e0008                 move.l  8(a6),-(sp)
0401C2E8: 61ff00000912             bsr.l   _if_private
0401C2EE: 2040                     movea.l d0,a0
0401C2F0: 20280006                 move.l  6(a0),d0
0401C2F4: 4e5e                     unlk    a6
0401C2F6: 4e75                     rts
