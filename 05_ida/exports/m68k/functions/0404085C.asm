0404085C: 4856                     pea     (a6)
0404085E: 2c4f                     movea.l sp,a6
04040860: 202e0008                 move.l  8(a6),d0
04040864: 7210                     moveq   #$10,d1
04040866: b280                     cmp.l   d0,d1
04040868: 670c                     beq.s   loc_4040876
0404086A: 620e                     bhi.s   loc_404087A
0404086C: 7212                     moveq   #$12,d1
0404086E: b280                     cmp.l   d0,d1
04040870: 6508                     bcs.s   loc_404087A
04040872: 7006                     moveq   #6,d0
04040874: 6010                     bra.s   loc_4040886
04040876: 7005                     moveq   #5,d0
04040878: 600c                     bra.s   loc_4040886
0404087A: 4879040a8593             pea     (aIpcObjectCopyo_0).l; "ipc_object_copyout_type_compat: strange"...
04040880: 61fffffcb3e4             bsr.l   _panic
04040886: 4e5e                     unlk    a6
04040888: 4e75                     rts
