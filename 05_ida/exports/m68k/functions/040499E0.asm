040499E0: 4856                     pea     (a6)
040499E2: 2c4f                     movea.l sp,a6
040499E4: 2f0a                     move.l  a2,-(sp)
040499E6: 2079040b5648             movea.l (_active_threads).l,a0
040499EC: 2468000c                 movea.l $C(a0),a2
040499F0: 2f0a                     move.l  a2,-(sp)
040499F2: 61ffffffff58             bsr.l   _retrieve_task_notify
040499F8: 2f2a007c                 move.l  $7C(a2),-(sp)
040499FC: 2f00                     move.l  d0,-(sp)
040499FE: 61ffffff7b5e             bsr.l   _ipc_port_copyout_receiver
04049A04: 246efffc                 movea.l -4(a6),a2
04049A08: 4e5e                     unlk    a6
04049A0A: 4e75                     rts
