04013CFA: 4856                     pea     (a6)
04013CFC: 2c4f                     movea.l sp,a6
04013CFE: 206e0008                 movea.l 8(a6),a0
04013D02: 30280006                 move.w  6(a0),d0
04013D06: 0240fff5                 andi.w  #$FFF5,d0
04013D0A: 00400004                 ori.w   #4,d0
04013D0E: 31400006                 move.w  d0,6(a0)
04013D12: 4868004e                 pea     $4E(a0)
04013D16: 61ffffff64ea             bsr.l   _wakeup
04013D1C: 4e5e                     unlk    a6
04013D1E: 4e75                     rts
