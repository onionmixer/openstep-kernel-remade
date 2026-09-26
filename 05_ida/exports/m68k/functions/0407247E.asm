0407247E: 4e560000                 link    a6,#0
04072482: 227c0200e000             movea.l #$200E000,a1
04072488: 4ab9040b1bca             tst.l   (dword_40B1BCA).l
0407248E: 6610                     bne.s   loc_40724A0
04072490: 22bc00000200             move.l  #$200,(a1)
04072496: 23fc00000001040b1bca     move.l  #1,(dword_40B1BCA).l
040724A0: 4e5e                     unlk    a6
040724A2: 4e75                     rts
