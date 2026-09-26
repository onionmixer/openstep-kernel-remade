04018584: 4856                     pea     (a6)
04018586: 2c4f                     movea.l sp,a6
04018588: 206e0008                 movea.l 8(a6),a0
0401858C: 20280040                 move.l  $40(a0),d0
04018590: 670c                     beq.s   loc_401859E
04018592: 42a80040                 clr.l   $40(a0)
04018596: 2f00                     move.l  d0,-(sp)
04018598: 61ff00002b2c             bsr.l   _vn_rele
0401859E: 4e5e                     unlk    a6
040185A0: 4e75                     rts
