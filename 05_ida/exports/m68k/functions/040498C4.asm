040498C4: 4856                     pea     (a6)
040498C6: 2c4f                     movea.l sp,a6
040498C8: 2f0a                     move.l  a2,-(sp)
040498CA: 2079040b5648             movea.l (_active_threads).l,a0
040498D0: 2468000c                 movea.l $C(a0),a2
040498D4: 2f0a                     move.l  a2,-(sp)
040498D6: 61ffffffff98             bsr.l   _retrieve_task_self_fast
040498DC: 2f2a007c                 move.l  $7C(a2),-(sp)
040498E0: 2f00                     move.l  d0,-(sp)
040498E2: 61ffffff7946             bsr.l   _ipc_port_copyout_send
040498E8: 246efffc                 movea.l -4(a6),a2
040498EC: 4e5e                     unlk    a6
040498EE: 4e75                     rts
