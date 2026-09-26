0403164A: 4856                     pea     (a6)
0403164C: 2c4f                     movea.l sp,a6
0403164E: 48780003                 pea     (3).w
04031652: 306e000a                 movea.w $A(a6),a0
04031656: 2f08                     move.l  a0,-(sp)
04031658: 42a7                     clr.l   -(sp)
0403165A: 61ff00000072             bsr.l   _specvp
04031660: 4e5e                     unlk    a6
04031662: 4e75                     rts
