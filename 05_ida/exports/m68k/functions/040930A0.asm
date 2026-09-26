040930A0: 4e560000                 link    a6,#0
040930A4: 206e0008                 movea.l arg_0(a6),a0
040930A8: 226e000c                 movea.l arg_4(a6),a1
040930AC: 2008                     move.l  a0,d0
040930AE: 10d9                     move.b  (a1)+,(a0)+
040930B0: 66fc                     bne.s   loc_40930AE
040930B2: 4e5e                     unlk    a6
040930B4: 4e75                     rts
