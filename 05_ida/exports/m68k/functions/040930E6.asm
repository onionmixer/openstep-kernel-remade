040930E6: 4e560000                 link    a6,#0
040930EA: 206e0008                 movea.l arg_0(a6),a0
040930EE: 70ff                     moveq   #$FFFFFFFF,d0
040930F0: 5280                     addq.l  #1,d0
040930F2: 4a18                     tst.b   (a0)+
040930F4: 66fa                     bne.s   loc_40930F0
040930F6: 4e5e                     unlk    a6
040930F8: 4e75                     rts
