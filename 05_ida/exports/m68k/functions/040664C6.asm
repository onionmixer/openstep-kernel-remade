040664C6: 4856                     pea     (a6)
040664C8: 2c4f                     movea.l sp,a6
040664CA: 2f0a                     move.l  a2,-(sp)
040664CC: 246e0008                 movea.l 8(a6),a2
040664D0: 202a0038                 move.l  $38(a2),d0
040664D4: 6710                     beq.s   loc_40664E6
040664D6: 48780110                 pea     ($110).w
040664DA: 2f00                     move.l  d0,-(sp)
040664DC: 61fffffe3de6             bsr.l   _kfree
040664E2: 42aa0038                 clr.l   $38(a2)
040664E6: 246efffc                 movea.l -4(a6),a2
040664EA: 4e5e                     unlk    a6
040664EC: 4e75                     rts
