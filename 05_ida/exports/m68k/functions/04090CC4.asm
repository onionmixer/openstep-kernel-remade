04090CC4: 4856                     pea     (a6)
04090CC6: 2c4f                     movea.l sp,a6
04090CC8: 206e0008                 movea.l 8(a6),a0
04090CCC: 20bc000000ff             move.l  #$FF,(a0)
04090CD2: 217c000000ff0004         move.l  #$FF,4(a0)
04090CDA: 42a80008                 clr.l   8(a0)
04090CDE: 4280                     clr.l   d0
04090CE0: 4e5e                     unlk    a6
04090CE2: 4e75                     rts
