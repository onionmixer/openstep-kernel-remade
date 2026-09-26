0405FFA4: 4856                     pea     (a6)
0405FFA6: 2c4f                     movea.l sp,a6
0405FFA8: 48e72038                 movem.l d2/a2-a4,-(sp)
0405FFAC: 286e0008                 movea.l 8(a6),a4
0405FFB0: 266e000c                 movea.l $C(a6),a3
0405FFB4: 2414                     move.l  (a4),d2
0405FFB6: 2f2e0010                 move.l  $10(a6),-(sp)
0405FFBA: 61fffffffab0             bsr.l   _vm_object_allocate
0405FFC0: 2440                     movea.l d0,a2
0405FFC2: 584f                     addq.w  #4,sp
0405FFC4: 4a8a                     tst.l   a2
0405FFC6: 660c                     bne.s   loc_405FFD4
0405FFC8: 4879040a9811             pea     (aVmObjectShadow).l; "vm_object_shadow: no object for shadowi"...
0405FFCE: 61fffffabc96             bsr.l   _panic
0405FFD4: 2542001c                 move.l  d2,$1C(a2)
0405FFD8: 25530020                 move.l  (a3),$20(a2)
0405FFDC: 4293                     clr.l   (a3)
0405FFDE: 288a                     move.l  a2,(a4)
0405FFE0: 4cee1c04fff0             movem.l -$10(a6),d2/a2-a4
0405FFE6: 4e5e                     unlk    a6
0405FFE8: 4e75                     rts
