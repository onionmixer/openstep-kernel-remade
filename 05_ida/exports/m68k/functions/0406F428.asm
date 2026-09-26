0406F428: 4856                     pea     (a6)
0406F42A: 2c4f                     movea.l sp,a6
0406F42C: 1039040b6841             move.b  (byte_40B6841).l,d0
0406F432: 49c0                     extb.l  d0
0406F434: 2240                     movea.l d0,a1
0406F436: 43f10a00                 lea     (a1,d0.l*2),a1
0406F43A: 2009                     move.l  a1,d0
0406F43C: e980                     asl.l   #4,d0
0406F43E: 41f9040ae4ac             lea     (_linesw).l,a0
0406F444: 2f2e000c                 move.l  $C(a6),-(sp)
0406F448: 4879040b67fc             pea     (_cons).l
0406F44E: 20700828                 movea.l $28(a0,d0.l),a0
0406F452: 4e90                     jsr     (a0)
0406F454: 4e5e                     unlk    a6
0406F456: 4e75                     rts
