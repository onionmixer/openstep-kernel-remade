04019B5E: 4856                     pea     (a6)
04019B60: 2c4f                     movea.l sp,a6
04019B62: 2f0a                     move.l  a2,-(sp)
04019B64: 206e0008                 movea.l 8(a6),a0
04019B68: 21500004                 move.l  (a0),4(a0)
04019B6C: 45e80008                 lea     8(a0),a2
04019B70: 2f0a                     move.l  a2,-(sp)
04019B72: 48780400                 pea     ($400).w
04019B76: 2f280004                 move.l  4(a0),-(sp)
04019B7A: 2f2e000c                 move.l  $C(a6),-(sp)
04019B7E: 61fffffe7aaa             bsr.l   _copystr
04019B84: 5392                     subq.l  #1,(a2)
04019B86: 246efffc                 movea.l -4(a6),a2
04019B8A: 4e5e                     unlk    a6
04019B8C: 4e75                     rts
