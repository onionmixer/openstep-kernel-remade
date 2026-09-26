04098C08: 4856                     pea     (a6)
04098C0A: 2c4f                     movea.l sp,a6
04098C0C: 2039040c2d18             move.l  (_kernel_pmap).l,d0
04098C12: 4e5e                     unlk    a6
04098C14: 4e75                     rts
