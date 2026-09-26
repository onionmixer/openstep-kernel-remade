0404EA28: 4856                     pea     (a6)
0404EA2A: 2c4f                     movea.l sp,a6
0404EA2C: 48e73800                 movem.l d2-d4,-(sp)
0404EA30: 282e0008                 move.l  8(a6),d4
0404EA34: 262e000c                 move.l  $C(a6),d3
0404EA38: 242e0014                 move.l  $14(a6),d2
0404EA3C: 2f2e0010                 move.l  $10(a6),-(sp)
0404EA40: 61fffffffd2c             bsr.l   _timeval_to_ns_time
0404EA46: 2f02                     move.l  d2,-(sp)
0404EA48: 2f01                     move.l  d1,-(sp)
0404EA4A: 2f00                     move.l  d0,-(sp)
0404EA4C: 2f03                     move.l  d3,-(sp)
0404EA4E: 2f04                     move.l  d4,-(sp)
0404EA50: 61fffffffae8             bsr.l   _ns_timeout
0404EA56: 4cee001cfff4             movem.l -$C(a6),d2-d4
0404EA5C: 4e5e                     unlk    a6
0404EA5E: 4e75                     rts
