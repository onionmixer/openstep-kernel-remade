0408DB46: 4856                     pea     (a6)
0408DB48: 2c4f                     movea.l sp,a6
0408DB4A: 2f0a                     move.l  a2,-(sp)
0408DB4C: 246e0008                 movea.l 8(a6),a2
0408DB50: 2f2a001c                 move.l  $1C(a2),-(sp)
0408DB54: 61fffffffe54             bsr.l   sub_408D9AA
0408DB5A: 42aa0004                 clr.l   4(a2)
0408DB5E: 246efffc                 movea.l -4(a6),a2
0408DB62: 4e5e                     unlk    a6
0408DB64: 4e75                     rts
