04001DFA: 9080                     sub.l   d0,d0
04001DFC: 302a0040                 move.w  $40(a2),d0
04001E00: 2f00                     move.l  d0,-(sp)
04001E02: 2f2a0042                 move.l  $42(a2),-(sp)
04001E06: 2f0f                     move.l  sp,-(sp)
04001E08: 4e7a8800                 movec   usp,a0
04001E0C: 2f08                     move.l  a0,-(sp)
04001E0E: 2f0a                     move.l  a2,-(sp)
04001E10: 4eb90409382c             jsr     _nmi
04001E16: dffc00000014             adda.l  #$14,sp
04001E1C: 4e75                     rts
