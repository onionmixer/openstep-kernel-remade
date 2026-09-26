040482C6: 4856                     pea     (a6)
040482C8: 2c4f                     movea.l sp,a6
040482CA: 2f39040b67d8             move.l  (_realhost).l,-(sp)
040482D0: 61ffffff8f14             bsr.l   _ipc_port_make_send
040482D6: 2079040b5648             movea.l (_active_threads).l,a0
040482DC: 2068000c                 movea.l $C(a0),a0
040482E0: 2f28007c                 move.l  $7C(a0),-(sp)
040482E4: 2f00                     move.l  d0,-(sp)
040482E6: 61ffffff922a             bsr.l   _ipc_port_copyout_send_compat
040482EC: 4e5e                     unlk    a6
040482EE: 4e75                     rts
