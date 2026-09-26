04006700: 4856                     pea     (a6)
04006702: 2c4f                     movea.l sp,a6
04006704: 206e0008                 movea.l 8(a6),a0
04006708: 23e80080040b57d4         move.l  $80(a0),(dword_40B57D4).l
04006710: 2068000c                 movea.l $C(a0),a0
04006714: 23e80030040b57d0         move.l  $30(a0),(_active_u).l
0400671C: 4e5e                     unlk    a6
0400671E: 4e75                     rts
