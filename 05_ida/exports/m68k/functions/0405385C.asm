0405385C: 4856                     pea     (a6)
0405385E: 2c4f                     movea.l sp,a6
04053860: 226e0008                 movea.l 8(a6),a1
04053864: 206e000c                 movea.l $C(a6),a0
04053868: 20a90178                 move.l  $178(a1),(a0)
0405386C: 2f10                     move.l  (a0),-(sp)
0405386E: 61ffffffba74             bsr.l   _pset_reference
04053874: 4280                     clr.l   d0
04053876: 4e5e                     unlk    a6
04053878: 4e75                     rts
