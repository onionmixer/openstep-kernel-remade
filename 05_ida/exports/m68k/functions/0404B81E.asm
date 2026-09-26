0404B81E: 4856                     pea     (a6)
0404B820: 2c4f                     movea.l sp,a6
0404B822: 2f0a                     move.l  a2,-(sp)
0404B824: 2f02                     move.l  d2,-(sp)
0404B826: 246e0008                 movea.l 8(a6),a2
0404B82A: 242e000c                 move.l  $C(a6),d2
0404B82E: 2f0a                     move.l  a2,-(sp)
0404B830: 61ffffffffce             bsr.l   _firstsect
0404B836: 2042                     movea.l d2,a0
0404B838: 91c0                     suba.l  d0,a0
0404B83A: 2008                     move.l  a0,d0
0404B83C: 4c3c0800f0f0f0f1         muls.l  #$F0F0F0F1,d0
0404B844: e480                     asr.l   #2,d0
0404B846: 222a0030                 move.l  $30(a2),d1
0404B84A: 5381                     subq.l  #1,d1
0404B84C: b280                     cmp.l   d0,d1
0404B84E: 6306                     bls.s   loc_404B856
0404B850: 7044                     moveq   #$44,d0 ; 'D'
0404B852: d082                     add.l   d2,d0
0404B854: 6002                     bra.s   loc_404B858
0404B856: 4280                     clr.l   d0
0404B858: 242efff8                 move.l  -8(a6),d2
0404B85C: 246efffc                 movea.l -4(a6),a2
0404B860: 4e5e                     unlk    a6
0404B862: 4e75                     rts
