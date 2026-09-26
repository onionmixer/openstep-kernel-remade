0404EA60: 4856                     pea     (a6)
0404EA62: 2c4f                     movea.l sp,a6
0404EA64: 48e73800                 movem.l d2-d4,-(sp)
0404EA68: 282e0008                 move.l  8(a6),d4
0404EA6C: 262e000c                 move.l  $C(a6),d3
0404EA70: 242e0014                 move.l  $14(a6),d2
0404EA74: 2f2e0010                 move.l  $10(a6),-(sp)
0404EA78: 61fffffffcf4             bsr.l   _timeval_to_ns_time
0404EA7E: 2f02                     move.l  d2,-(sp)
0404EA80: 2f01                     move.l  d1,-(sp)
0404EA82: 2f00                     move.l  d0,-(sp)
0404EA84: 2f03                     move.l  d3,-(sp)
0404EA86: 2f04                     move.l  d4,-(sp)
0404EA88: 61fffffffaf4             bsr.l   _ns_abstimeout
0404EA8E: 4cee001cfff4             movem.l -$C(a6),d2-d4
0404EA94: 4e5e                     unlk    a6
0404EA96: 4e75                     rts
