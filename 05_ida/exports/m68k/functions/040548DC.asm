040548DC: 4856                     pea     (a6)
040548DE: 2c4f                     movea.l sp,a6
040548E0: 2f39040b5648             move.l  (_active_threads).l,-(sp)
040548E6: 61ffffffdeb8             bsr.l   _stack_privilege
040548EC: 61fffffffeee             bsr.l   sub_40547DC
040548F2: 4e5e                     unlk    a6
040548F4: 4e75                     rts
