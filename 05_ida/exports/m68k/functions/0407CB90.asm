0407CB90: 4856                     pea     (a6)
0407CB92: 2c4f                     movea.l sp,a6
0407CB94: 2f2e0008                 move.l  8(a6),-(sp)
0407CB98: 61fffff8d668             bsr.l   _wakeup
0407CB9E: 4e5e                     unlk    a6
0407CBA0: 4e75                     rts
