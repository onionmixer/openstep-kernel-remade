0401CCE4: 4856                     pea     (a6)
0401CCE6: 2c4f                     movea.l sp,a6
0401CCE8: 206e0008                 movea.l 8(a6),a0
0401CCEC: 216e000c0042             move.l  $C(a6),$42(a0)
0401CCF2: 4e5e                     unlk    a6
0401CCF4: 4e75                     rts
