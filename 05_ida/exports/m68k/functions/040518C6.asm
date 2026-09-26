040518C6: 4856                     pea     (a6)
040518C8: 2c4f                     movea.l sp,a6
040518CA: 2079040b6004             movea.l (_processor_ptr).l,a0
040518D0: 4280                     clr.l   d0
040518D2: 4aa80104                 tst.l   $104(a0)
040518D6: 6e0a                     bgt.s   loc_40518E2
040518D8: 20680128                 movea.l $128(a0),a0
040518DC: 4aa80104                 tst.l   $104(a0)
040518E0: 6f02                     ble.s   loc_40518E4
040518E2: 7001                     moveq   #1,d0
040518E4: 2f00                     move.l  d0,-(sp)
040518E6: 61ff0004511a             bsr.l   _thread_syscall_return
040518EC: 4e5e                     unlk    a6
040518EE: 4e75                     rts
