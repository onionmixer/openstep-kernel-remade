040518B6: 4856                     pea     (a6)
040518B8: 2c4f                     movea.l sp,a6
040518BA: 42a7                     clr.l   -(sp)
040518BC: 61fffffff57a             bsr.l   _thread_block_with_continuation
040518C2: 4e5e                     unlk    a6
040518C4: 4e75                     rts
