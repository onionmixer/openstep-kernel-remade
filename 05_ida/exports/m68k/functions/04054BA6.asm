04054BA6: 4856                     pea     (a6)
04054BA8: 2c4f                     movea.l sp,a6
04054BAA: 206e0008                 movea.l 8(a6),a0
04054BAE: 4290                     clr.l   (a0)
04054BB0: 42a80004                 clr.l   4(a0)
04054BB4: 42a8000c                 clr.l   $C(a0)
04054BB8: 42a80008                 clr.l   8(a0)
04054BBC: 4e5e                     unlk    a6
04054BBE: 4e75                     rts
