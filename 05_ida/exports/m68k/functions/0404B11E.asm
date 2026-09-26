0404B11E: 4856                     pea     (a6)
0404B120: 2c4f                     movea.l sp,a6
0404B122: 206e0008                 movea.l 8(a6),a0
0404B126: 217c0404b0f00008         move.l  #$404B0F0,8(a0)
0404B12E: 21480010                 move.l  a0,$10(a0)
0404B132: 42a8001c                 clr.l   $1C(a0)
0404B136: 4e5e                     unlk    a6
0404B138: 4e75                     rts
