0404829C: 4856                     pea     (a6)
0404829E: 2c4f                     movea.l sp,a6
040482A0: 2f39040b67d8             move.l  (_realhost).l,-(sp)
040482A6: 61ffffff8f3e             bsr.l   _ipc_port_make_send
040482AC: 2079040b5648             movea.l (_active_threads).l,a0
040482B2: 2068000c                 movea.l $C(a0),a0
040482B6: 2f28007c                 move.l  $7C(a0),-(sp)
040482BA: 2f00                     move.l  d0,-(sp)
040482BC: 61ffffff8f6c             bsr.l   _ipc_port_copyout_send
040482C2: 4e5e                     unlk    a6
040482C4: 4e75                     rts
