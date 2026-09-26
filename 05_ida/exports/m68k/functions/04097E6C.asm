04097E6C: 4856                     pea     (a6)
04097E6E: 2c4f                     movea.l sp,a6
04097E70: 2f02                     move.l  d2,-(sp)
04097E72: 202e0008                 move.l  8(a6),d0
04097E76: 671c                     beq.s   loc_4097E94
04097E78: 40c2                     move    sr,d2
04097E7A: 46fc2300                 move    #$2300,sr
04097E7E: 48c2                     ext.l   d2
04097E80: 2f2e0010                 move.l  $10(a6),-(sp)
04097E84: 2f2e000c                 move.l  $C(a6),-(sp)
04097E88: 2f00                     move.l  d0,-(sp)
04097E8A: 61fffffffdc4             bsr.l   _pmap_remove_range
04097E90: 40c0                     move    sr,d0
04097E92: 46c2                     move    d2,sr
04097E94: 242efffc                 move.l  -4(a6),d2
04097E98: 4e5e                     unlk    a6
04097E9A: 4e75                     rts
