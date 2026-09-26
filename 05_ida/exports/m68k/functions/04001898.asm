04001898: 4e560000                 link    a6,#0
0400189C: 23fc040018b6040ad970     move.l  #$40018B6,(_probe_recover).l
040018A6: 206e0008                 movea.l arg_0(a6),a0
040018AA: 2010                     move.l  (a0),d0
040018AC: 42b9040ad970             clr.l   (_probe_recover).l
040018B2: 7001                     moveq   #1,d0
040018B4: 6008                     bra.s   loc_40018BE
040018B6: 42b9040ad970             clr.l   (_probe_recover).l
040018BC: 4280                     clr.l   d0
040018BE: 4e5e                     unlk    a6
040018C0: 4e75                     rts
