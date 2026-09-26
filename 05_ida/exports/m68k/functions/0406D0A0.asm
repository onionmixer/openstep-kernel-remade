0406D0A0: 4856                     pea     (a6)
0406D0A2: 2c4f                     movea.l sp,a6
0406D0A4: 206e0008                 movea.l 8(a6),a0
0406D0A8: 102e000f                 move.b  $F(a6),d0
0406D0AC: 4600                     not.b   d0
0406D0AE: c0280025                 and.b   $25(a0),d0
0406D0B2: 11400025                 move.b  d0,$25(a0)
0406D0B6: 2050                     movea.l (a0),a0
0406D0B8: 11400008                 move.b  d0,8(a0)
0406D0BC: 4e5e                     unlk    a6
0406D0BE: 4e75                     rts
