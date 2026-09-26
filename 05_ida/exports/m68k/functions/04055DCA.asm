04055DCA: 4856                     pea     (a6)
04055DCC: 2c4f                     movea.l sp,a6
04055DCE: 61fffffff612             bsr.l   _zone_free_space_reclaim
04055DD4: 4e5e                     unlk    a6
04055DD6: 4e75                     rts
