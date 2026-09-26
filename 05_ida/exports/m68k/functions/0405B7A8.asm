0405B7A8: 4856                     pea     (a6)
0405B7AA: 2c4f                     movea.l sp,a6
0405B7AC: 206e0008                 movea.l 8(a6),a0
0405B7B0: 20280014                 move.l  $14(a0),d0
0405B7B4: 0680fffff830             addi.l  #-$7D0,d0
0405B7BA: 7267                     moveq   #$67,d1 ; 'g'
0405B7BC: b280                     cmp.l   d0,d1
0405B7BE: 650c                     bcs.s   loc_405B7CC
0405B7C0: 41f9040b03f0             lea     (unk_40B03F0).l,a0
0405B7C6: 20300c00                 move.l  (a0,d0.l*4),d0
0405B7CA: 6002                     bra.s   loc_405B7CE
0405B7CC: 4280                     clr.l   d0
0405B7CE: 4e5e                     unlk    a6
0405B7D0: 4e75                     rts
