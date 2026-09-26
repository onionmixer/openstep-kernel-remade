0404EA00: 4856                     pea     (a6)
0404EA02: 2c4f                     movea.l sp,a6
0404EA04: 2f02                     move.l  d2,-(sp)
0404EA06: 242e0008                 move.l  8(a6),d2
0404EA0A: 48780001                 pea     (1).w
0404EA0E: 61ff0004369a             bsr.l   _clock_value
0404EA14: 2f02                     move.l  d2,-(sp)
0404EA16: 2f01                     move.l  d1,-(sp)
0404EA18: 2f00                     move.l  d0,-(sp)
0404EA1A: 61fffffffcf6             bsr.l   _ns_time_to_timeval
0404EA20: 242efffc                 move.l  -4(a6),d2
0404EA24: 4e5e                     unlk    a6
0404EA26: 4e75                     rts
