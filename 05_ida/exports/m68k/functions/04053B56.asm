04053B56: 4856                     pea     (a6)
04053B58: 2c4f                     movea.l sp,a6
04053B5A: 4ab9040aff14             tst.l   (_stack_check_usage).l
04053B60: 6718                     beq.s   loc_4053B7A
04053B62: 2f2e0008                 move.l  8(a6),-(sp)
04053B66: 61ffffffff9a             bsr.l   _stack_usage
04053B6C: b0b9040aff18             cmp.l   (_stack_max_usage).l,d0
04053B72: 6306                     bls.s   loc_4053B7A
04053B74: 23c0040aff18             move.l  d0,(_stack_max_usage).l
04053B7A: 4e5e                     unlk    a6
04053B7C: 4e75                     rts
