040702AA: 4856                     pea     (a6)
040702AC: 2c4f                     movea.l sp,a6
040702AE: 1039040b6841             move.b  (byte_40B6841).l,d0
040702B4: 49c0                     extb.l  d0
040702B6: 2240                     movea.l d0,a1
040702B8: 43f10a00                 lea     (a1,d0.l*2),a1
040702BC: 2009                     move.l  a1,d0
040702BE: e980                     asl.l   #4,d0
040702C0: 41f9040ae4ac             lea     (_linesw).l,a0
040702C6: 4879040b67fc             pea     (_cons).l
040702CC: 2f2e0008                 move.l  8(a6),-(sp)
040702D0: 20700814                 movea.l $14(a0,d0.l),a0
040702D4: 4e90                     jsr     (a0)
040702D6: 4e5e                     unlk    a6
040702D8: 4e75                     rts
