040499B4: 4856                     pea     (a6)
040499B6: 2c4f                     movea.l sp,a6
040499B8: 2f0a                     move.l  a2,-(sp)
040499BA: 2079040b5648             movea.l (_active_threads).l,a0
040499C0: 2468000c                 movea.l $C(a0),a2
040499C4: 2f0a                     move.l  a2,-(sp)
040499C6: 61fffffffea8             bsr.l   _retrieve_task_self_fast
040499CC: 2f2a007c                 move.l  $7C(a2),-(sp)
040499D0: 2f00                     move.l  d0,-(sp)
040499D2: 61ffffff7b3e             bsr.l   _ipc_port_copyout_send_compat
040499D8: 246efffc                 movea.l -4(a6),a2
040499DC: 4e5e                     unlk    a6
040499DE: 4e75                     rts
