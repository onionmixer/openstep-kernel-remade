04053ABE: 4856                     pea     (a6)
04053AC0: 2c4f                     movea.l sp,a6
04053AC2: 4ab9040aff28             tst.l   (_thread_collect_max_rate).l
04053AC8: 660a                     bne.s   loc_4053AD4
04053ACA: 23f9040af7e4040aff28     move.l  (_hz).l,(_thread_collect_max_rate).l
04053AD4: 4ab9040aff20             tst.l   (_thread_collect_allowed).l
04053ADA: 6722                     beq.s   loc_4053AFE
04053ADC: 2039040aff24             move.l  (_thread_collect_last_tick).l,d0
04053AE2: d0b9040aff28             add.l   (_thread_collect_max_rate).l,d0
04053AE8: 2239040c2450             move.l  (_sched_tick).l,d1
04053AEE: b081                     cmp.l   d1,d0
04053AF0: 640c                     bcc.s   loc_4053AFE
04053AF2: 23c1040aff24             move.l  d1,(_thread_collect_last_tick).l
04053AF8: 61ffffffffbc             bsr.l   _thread_collect_scan
04053AFE: 4e5e                     unlk    a6
04053B00: 4e75                     rts
