04053EDE: 4856                     pea     (a6)
04053EE0: 2c4f                     movea.l sp,a6
04053EE2: 2f39040b5648             move.l  (_active_threads).l,-(sp)
04053EE8: 61ffffffe8b6             bsr.l   _stack_privilege
04053EEE: 61ffffffff80             bsr.l   _swapin_thread_continue
