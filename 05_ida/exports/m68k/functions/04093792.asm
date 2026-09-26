04093792: 4856                     pea     (a6)
04093794: 2c4f                     movea.l sp,a6
04093796: 42a7                     clr.l   -(sp)
04093798: 2f2e0008                 move.l  8(a6),-(sp)
0409379C: 2f39040aff10             move.l  (_kernel_task).l,-(sp)
040937A2: 61fffffbff9a             bsr.l   _kernel_thread
040937A8: 4e5e                     unlk    a6
040937AA: 4e75                     rts
