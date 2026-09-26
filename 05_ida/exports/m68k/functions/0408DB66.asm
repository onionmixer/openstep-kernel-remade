0408DB66: 4856                     pea     (a6)
0408DB68: 2c4f                     movea.l sp,a6
0408DB6A: 206e0008                 movea.l 8(a6),a0
0408DB6E: 2f28001c                 move.l  $1C(a0),-(sp)
0408DB72: 48790408d9aa             pea     (sub_408D9AA).l
0408DB78: 2f2e0010                 move.l  $10(a6),-(sp)
0408DB7C: 2f2e000c                 move.l  $C(a6),-(sp)
0408DB80: 61fffff8edce             bsr.l   _nb_alloc_wrapper
0408DB86: 4e5e                     unlk    a6
0408DB88: 4e75                     rts
