040458F0: 4856                     pea     (a6)
040458F2: 2c4f                     movea.l sp,a6
040458F4: 42a7                     clr.l   -(sp)
040458F6: 61ff0005110a             bsr.l   _thread_syscall_return
040458FC: 4e5e                     unlk    a6
040458FE: 4e75                     rts
