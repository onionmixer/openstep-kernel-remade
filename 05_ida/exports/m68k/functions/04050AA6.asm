04050AA6: 4856                     pea     (a6)
04050AA8: 2c4f                     movea.l sp,a6
04050AAA: 2f2e0010                 move.l  $10(a6),-(sp)
04050AAE: 2f2e0008                 move.l  8(a6),-(sp)
04050AB2: 61fffffffcd0             bsr.l   _assert_wait
04050AB8: 42a7                     clr.l   -(sp)
04050ABA: 61ff0000037c             bsr.l   _thread_block_with_continuation
04050AC0: 4e5e                     unlk    a6
04050AC2: 4e75                     rts
