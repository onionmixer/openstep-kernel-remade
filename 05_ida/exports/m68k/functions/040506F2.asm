040506F2: 4856                     pea     (a6)
040506F4: 2c4f                     movea.l sp,a6
040506F6: 42a7                     clr.l   -(sp)
040506F8: 48780001                 pea     (1).w
040506FC: 2f2e0008                 move.l  8(a6),-(sp)
04050700: 61ff00000154             bsr.l   _clear_wait
04050706: 4e5e                     unlk    a6
04050708: 4e75                     rts
