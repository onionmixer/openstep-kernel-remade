040413C8: 4856                     pea     (a6)
040413CA: 2c4f                     movea.l sp,a6
040413CC: 2f0a                     move.l  a2,-(sp)
040413CE: 246e0008                 movea.l 8(a6),a2
040413D2: 42aa000c                 clr.l   $C(a2)
040413D6: 42aa0008                 clr.l   8(a2)
040413DA: 2f0a                     move.l  a2,-(sp)
040413DC: 61fffffffa1c             bsr.l   _ipc_port_clear_receiver
040413E2: 2f0a                     move.l  a2,-(sp)
040413E4: 61fffffffbfa             bsr.l   _ipc_port_destroy
040413EA: 246efffc                 movea.l -4(a6),a2
040413EE: 4e5e                     unlk    a6
040413F0: 4e75                     rts
