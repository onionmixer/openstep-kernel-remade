0405DE90: 4856                     pea     (a6)
0405DE92: 2c4f                     movea.l sp,a6
0405DE94: 206e0008                 movea.l 8(a6),a0
0405DE98: 4aa80014                 tst.l   $14(a0)
0405DE9C: 6708                     beq.s   loc_405DEA6
0405DE9E: 2039040c2d30             move.l  (_vm_map_entry_zone).l,d0
0405DEA4: 6006                     bra.s   loc_405DEAC
0405DEA6: 2039040c2d34             move.l  (_vm_map_kentry_zone).l,d0
0405DEAC: 2f2e000c                 move.l  $C(a6),-(sp)
0405DEB0: 2f00                     move.l  d0,-(sp)
0405DEB2: 61ffffff7d48             bsr.l   _zfree
0405DEB8: 4e5e                     unlk    a6
0405DEBA: 4e75                     rts
