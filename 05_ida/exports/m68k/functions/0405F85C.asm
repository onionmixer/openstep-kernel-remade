0405F85C: 4856                     pea     (a6)
0405F85E: 2c4f                     movea.l sp,a6
0405F860: 2f2e0008                 move.l  8(a6),-(sp)
0405F864: 61ffffffff8a             bsr.l   _vm_phys_to_vm_page
0405F86A: 4e5e                     unlk    a6
0405F86C: 4e75                     rts
