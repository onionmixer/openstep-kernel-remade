0400DC3E: 4856                     pea     (a6)
0400DC40: 2c4f                     movea.l sp,a6
0400DC42: 2f0a                     move.l  a2,-(sp)
0400DC44: 246e0008                 movea.l 8(a6),a2
0400DC48: 2f0a                     move.l  a2,-(sp)
0400DC4A: 61fffffff192             bsr.l   _ttywflush
0400DC50: 422a0045                 clr.b   $45(a2)
0400DC54: 246efffc                 movea.l -4(a6),a2
0400DC58: 4e5e                     unlk    a6
0400DC5A: 4e75                     rts
