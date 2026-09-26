F0079504: 9de3bf98                 save    %sp, -0x68, %sp
F0079508: 133c0443                 sethi   %hi(_zone_gc_max_rate), %o1
F007950C: d00260a0                 ld      [%o1+%lo(_zone_gc_max_rate)], %o0
F0079510: 80a22000                 cmp     %o0, 0
F0079514: 12800006                 bne     loc_F007952C
F0079518: 113c0443                 sethi   -0xFEEF400, %o0
F007951C: 113c043e                 sethi   %hi(_hz), %o0
F0079520: d00223e0                 ld      [%o0+%lo(_hz)], %o0
F0079524: d02260a0                 st      %o0, [%o1+%lo(_zone_gc_max_rate)]
F0079528: 113c0443                 sethi   -0xFEEF400, %o0
F007952C: d0022098                 ld      [%o0+0x98], %o0
F0079530: 80a22000                 cmp     %o0, 0
F0079534: 0280000c                 be      locret_F0079564
F0079538: d40260a0                 ld      [%o1+0xA0], %o2
F007953C: 173c0443                 sethi   %hi(_zone_gc_last_tick), %o3
F0079540: d002e09c                 ld      [%o3+%lo(_zone_gc_last_tick)], %o0
F0079544: 133c04f0                 sethi   %hi(_sched_tick), %o1
F0079548: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F007954C: 9002000a                 add     %o0, %o2, %o0
F0079550: 80a24008                 cmp     %o1, %o0
F0079554: 08800004                 bleu    locret_F0079564
F0079558: 01000000                 nop
F007955C: 7fffff89                 call    _zone_gc
F0079560: d222e09c                 st      %o1, [%o3+%lo(_zone_gc_last_tick)]
F0079564: 81c7e008                 ret
F0079568: 81e80000                 restore
