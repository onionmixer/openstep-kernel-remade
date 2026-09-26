04050742: 4856                     pea     (a6)
04050744: 2c4f                     movea.l sp,a6
04050746: 2f0b                     move.l  a3,-(sp)
04050748: 2f0a                     move.l  a2,-(sp)
0405074A: 246e0008                 movea.l 8(a6),a2
0405074E: 257c040506f20130         move.l  #$40506F2,$130(a2)
04050756: 254a0134                 move.l  a2,$134(a2)
0405075A: 486a0110                 pea     $110(a2)
0405075E: 47f90404b11e             lea     (_init_timeout_element).l,a3
04050764: 4e93                     jsr     (a3)
04050766: 257c04051b600160         move.l  #$4051B60,$160(a2)
0405076E: 254a0164                 move.l  a2,$164(a2)
04050772: 486a0140                 pea     $140(a2)
04050776: 4e93                     jsr     (a3)
04050778: 246efff8                 movea.l -8(a6),a2
0405077C: 266efffc                 movea.l -4(a6),a3
04050780: 4e5e                     unlk    a6
04050782: 4e75                     rts
