040519B8: 4856                     pea     (a6)
040519BA: 2c4f                     movea.l sp,a6
040519BC: 2079040b5648             movea.l (_active_threads).l,a0
040519C2: 4aa80060                 tst.l   $60(a0)
040519C6: 6d0a                     blt.s   loc_40519D2
040519C8: 2f08                     move.l  a0,-(sp)
040519CA: 61ff000001ce             bsr.l   _thread_depress_abort
040519D0: 584f                     addq.w  #4,sp
040519D2: 42a7                     clr.l   -(sp)
040519D4: 61ff0004502c             bsr.l   _thread_syscall_return
040519DA: 4e5e                     unlk    a6
040519DC: 4e75                     rts
