04055D86: 4856                     pea     (a6)
04055D88: 2c4f                     movea.l sp,a6
04055D8A: 4ab9040aff4c             tst.l   (_zone_gc_max_rate).l
04055D90: 660a                     bne.s   loc_4055D9C
04055D92: 23f9040af7e4040aff4c     move.l  (_hz).l,(_zone_gc_max_rate).l
04055D9C: 4ab9040aff44             tst.l   (_zone_gc_allowed).l
04055DA2: 6722                     beq.s   loc_4055DC6
04055DA4: 2039040aff48             move.l  (_zone_gc_last_tick).l,d0
04055DAA: d0b9040aff4c             add.l   (_zone_gc_max_rate).l,d0
04055DB0: 2239040c2450             move.l  (_sched_tick).l,d1
04055DB6: b081                     cmp.l   d1,d0
04055DB8: 640c                     bcc.s   loc_4055DC6
04055DBA: 23c1040aff48             move.l  d1,(_zone_gc_last_tick).l
04055DC0: 61ffffffff3a             bsr.l   _zone_gc
04055DC6: 4e5e                     unlk    a6
04055DC8: 4e75                     rts
