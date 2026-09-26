0405DE4E: 4856                     pea     (a6)
0405DE50: 2c4f                     movea.l sp,a6
0405DE52: 2f02                     move.l  d2,-(sp)
0405DE54: 206e0008                 movea.l 8(a6),a0
0405DE58: 4aa80014                 tst.l   $14(a0)
0405DE5C: 6708                     beq.s   loc_405DE66
0405DE5E: 2039040c2d30             move.l  (_vm_map_entry_zone).l,d0
0405DE64: 6006                     bra.s   loc_405DE6C
0405DE66: 2039040c2d34             move.l  (_vm_map_kentry_zone).l,d0
0405DE6C: 2f00                     move.l  d0,-(sp)
0405DE6E: 61ffffff7ce6             bsr.l   _zalloc
0405DE74: 2400                     move.l  d0,d2
0405DE76: 584f                     addq.w  #4,sp
0405DE78: 660c                     bne.s   loc_405DE86
0405DE7A: 4879040a96c6             pea     (aVmMapEntryCrea).l; "vm_map_entry_create"
0405DE80: 61fffffadde4             bsr.l   _panic
0405DE86: 2002                     move.l  d2,d0
0405DE88: 242efffc                 move.l  -4(a6),d2
0405DE8C: 4e5e                     unlk    a6
0405DE8E: 4e75                     rts
