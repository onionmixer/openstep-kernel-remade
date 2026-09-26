040485A0: 4856                     pea     (a6)
040485A2: 2c4f                     movea.l sp,a6
040485A4: 206e0008                 movea.l 8(a6),a0
040485A8: 2f10                     move.l  (a0),-(sp)
040485AA: 61ffffff8c3a             bsr.l   _ipc_port_make_send
040485B0: 4e5e                     unlk    a6
040485B2: 4e75                     rts
