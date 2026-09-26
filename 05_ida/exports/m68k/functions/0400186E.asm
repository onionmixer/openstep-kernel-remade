0400186E: 4e560000                 link    a6,#0
04001872: 23fc0400188c040ad970     move.l  #$400188C,(_probe_recover).l
0400187C: 206e0008                 movea.l arg_0(a6),a0
04001880: 1010                     move.b  (a0),d0
04001882: 42b9040ad970             clr.l   (_probe_recover).l
04001888: 7001                     moveq   #1,d0
0400188A: 6008                     bra.s   loc_4001894
0400188C: 42b9040ad970             clr.l   (_probe_recover).l
04001892: 4280                     clr.l   d0
04001894: 4e5e                     unlk    a6
04001896: 4e75                     rts
