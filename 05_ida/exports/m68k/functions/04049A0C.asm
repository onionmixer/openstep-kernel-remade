04049A0C: 4856                     pea     (a6)
04049A0E: 2c4f                     movea.l sp,a6
04049A10: 2f0a                     move.l  a2,-(sp)
04049A12: 2079040b5648             movea.l (_active_threads).l,a0
04049A18: 2468000c                 movea.l $C(a0),a2
04049A1C: 2f08                     move.l  a0,-(sp)
04049A1E: 61fffffffe7a             bsr.l   _retrieve_thread_self_fast
04049A24: 2f2a007c                 move.l  $7C(a2),-(sp)
04049A28: 2f00                     move.l  d0,-(sp)
04049A2A: 61ffffff7ae6             bsr.l   _ipc_port_copyout_send_compat
04049A30: 246efffc                 movea.l -4(a6),a2
04049A34: 4e5e                     unlk    a6
04049A36: 4e75                     rts
