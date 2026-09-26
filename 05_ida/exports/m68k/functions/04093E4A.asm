04093E4A: 4856                     pea     (a6)
04093E4C: 2c4f                     movea.l sp,a6
04093E4E: 42a7                     clr.l   -(sp)
04093E50: 48780001                 pea     (1).w
04093E54: 486e000c                 pea     $C(a6)
04093E58: 2f2e0008                 move.l  8(a6),-(sp)
04093E5C: 61fffff776f2             bsr.l   _prf
04093E62: 4e5e                     unlk    a6
04093E64: 4e75                     rts
