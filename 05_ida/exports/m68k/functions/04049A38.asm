04049A38: 4856                     pea     (a6)
04049A3A: 2c4f                     movea.l sp,a6
04049A3C: 2f0a                     move.l  a2,-(sp)
04049A3E: 2079040b5648             movea.l (_active_threads).l,a0
04049A44: 2468000c                 movea.l $C(a0),a2
04049A48: 2f08                     move.l  a0,-(sp)
04049A4A: 61ffffffff36             bsr.l   _retrieve_thread_reply
04049A50: 2f2a007c                 move.l  $7C(a2),-(sp)
04049A54: 2f00                     move.l  d0,-(sp)
04049A56: 61ffffff7b06             bsr.l   _ipc_port_copyout_receiver
04049A5C: 246efffc                 movea.l -4(a6),a2
04049A60: 4e5e                     unlk    a6
04049A62: 4e75                     rts
