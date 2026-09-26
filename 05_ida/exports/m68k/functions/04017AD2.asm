04017AD2: 4856                     pea     (a6)
04017AD4: 2c4f                     movea.l sp,a6
04017AD6: 206e0008                 movea.l 8(a6),a0
04017ADA: 006801000002             ori.w   #$100,2(a0)
04017AE0: 2f08                     move.l  a0,-(sp)
04017AE2: 61ffffffff42             bsr.l   _bwrite
04017AE8: 4e5e                     unlk    a6
04017AEA: 4e75                     rts
