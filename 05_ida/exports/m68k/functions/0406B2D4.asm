0406B2D4: 4e56ffe0                 link    a6,#-$20
0406B2D8: 48e72030                 movem.l d2/a2-a3,-(sp)
0406B2DC: 246e0008                 movea.l arg_0(a6),a2
0406B2E0: 74ef                     moveq   #$FFFFFFEF,d2
0406B2E2: d48e                     add.l   a6,d2
0406B2E4: 72f0                     moveq   #$FFFFFFF0,d1
0406B2E6: c481                     and.l   d1,d2
0406B2E8: 42a7                     clr.l   -(sp)
0406B2EA: 42a7                     clr.l   -(sp)
0406B2EC: 4878000a                 pea     ($A).w
0406B2F0: 2f3c00040000             move.l  #$40000,-(sp)
0406B2F6: 61ff0002d910             bsr.l   _pmap_kernel
0406B2FC: 2f00                     move.l  d0,-(sp)
0406B2FE: 48780010                 pea     ($10).w
0406B302: 2f02                     move.l  d2,-(sp)
0406B304: 47ea011e                 lea     $11E(a2),a3
0406B308: 2f0b                     move.l  a3,-(sp)
0406B30A: d4fc0026                 adda.w  #$26,a2 ; '&'
0406B30E: 2f0a                     move.l  a2,-(sp)
0406B310: 61ffffffb302             bsr.l   _dma_list
0406B316: defc0020                 adda.w  #$20,sp ; ' '
0406B31A: 2ebc00040000             move.l  #$40000,(sp)
0406B320: 2f0b                     move.l  a3,-(sp)
0406B322: 2f0a                     move.l  a2,-(sp)
0406B324: 61ffffffb5e4             bsr.l   _dma_start
0406B32A: 4878000a                 pea     ($A).w
0406B32E: 61ff0002704a             bsr.l   _delay
0406B334: 2f0a                     move.l  a2,-(sp)
0406B336: 61ffffffbd20             bsr.l   _dma_abort
0406B33C: 4cee0c04ffd4             movem.l var_2C(a6),d2/a2-a3
0406B342: 4e5e                     unlk    a6
0406B344: 4e75                     rts
