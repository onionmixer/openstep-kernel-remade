0401C2F8: 4856                     pea     (a6)
0401C2FA: 2c4f                     movea.l sp,a6
0401C2FC: 2f2e0008                 move.l  8(a6),-(sp)
0401C300: 61ff000008fa             bsr.l   _if_private
0401C306: 2040                     movea.l d0,a0
0401C308: 2028000a                 move.l  $A(a0),d0
0401C30C: 4e5e                     unlk    a6
0401C30E: 4e75                     rts
