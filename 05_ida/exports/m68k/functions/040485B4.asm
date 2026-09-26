040485B4: 4856                     pea     (a6)
040485B6: 2c4f                     movea.l sp,a6
040485B8: 206e0008                 movea.l 8(a6),a0
040485BC: 2f280138                 move.l  $138(a0),-(sp)
040485C0: 61ffffff8c24             bsr.l   _ipc_port_make_send
040485C6: 4e5e                     unlk    a6
040485C8: 4e75                     rts
