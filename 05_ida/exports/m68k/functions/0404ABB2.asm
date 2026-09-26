0404ABB2: 4856                     pea     (a6)
0404ABB4: 2c4f                     movea.l sp,a6
0404ABB6: 206e0008                 movea.l 8(a6),a0
0404ABBA: 102e000f                 move.b  $F(a6),d0
0404ABBE: 02000001                 andi.b  #1,d0
0404ABC2: efe800c10006             bfins   d0,6(a0){3:1}
0404ABC8: 4e5e                     unlk    a6
0404ABCA: 4e75                     rts
