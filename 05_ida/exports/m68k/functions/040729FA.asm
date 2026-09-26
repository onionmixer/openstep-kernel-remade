040729FA: 4856                     pea     (a6)
040729FC: 2c4f                     movea.l sp,a6
040729FE: 206e0008                 movea.l 8(a6),a0
04072A02: 10280104                 move.b  $104(a0),d0
04072A06: 00000001                 ori.b   #1,d0
04072A0A: 11400104                 move.b  d0,$104(a0)
04072A0E: 42a7                     clr.l   -(sp)
04072A10: 42a7                     clr.l   -(sp)
04072A12: 4868011b                 pea     $11B(a0)
04072A16: 61fffffddf38             bsr.l   _thread_wakeup_prim
04072A1C: 4e5e                     unlk    a6
04072A1E: 4e75                     rts
