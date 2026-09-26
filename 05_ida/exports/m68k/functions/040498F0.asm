040498F0: 4856                     pea     (a6)
040498F2: 2c4f                     movea.l sp,a6
040498F4: 2f0a                     move.l  a2,-(sp)
040498F6: 2079040b5648             movea.l (_active_threads).l,a0
040498FC: 2468000c                 movea.l $C(a0),a2
04049900: 2f08                     move.l  a0,-(sp)
04049902: 61ffffffff96             bsr.l   _retrieve_thread_self_fast
04049908: 2f2a007c                 move.l  $7C(a2),-(sp)
0404990C: 2f00                     move.l  d0,-(sp)
0404990E: 61ffffff791a             bsr.l   _ipc_port_copyout_send
04049914: 246efffc                 movea.l -4(a6),a2
04049918: 4e5e                     unlk    a6
0404991A: 4e75                     rts
