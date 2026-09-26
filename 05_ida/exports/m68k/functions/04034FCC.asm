04034FCC: 4856                     pea     (a6)
04034FCE: 2c4f                     movea.l sp,a6
04034FD0: 2f2e000c                 move.l  $C(a6),-(sp)
04034FD4: 222e0008                 move.l  8(a6),d1
04034FD8: 0681000000d4             addi.l  #$D4,d1
04034FDE: 2f01                     move.l  d1,-(sp)
04034FE0: 4879040a67f5             pea     (aSS).l; "%s: %s\n"
04034FE6: 48780003                 pea     (3).w
04034FEA: 61fffffd646c             bsr.l   _log
04034FF0: 4e5e                     unlk    a6
04034FF2: 4e75                     rts
