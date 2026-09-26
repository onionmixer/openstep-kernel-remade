0407BD9C: 4856                     pea     (a6)
0407BD9E: 2c4f                     movea.l sp,a6
0407BDA0: 4ab9040b4fda             tst.l   (dword_40B4FDA).l
0407BDA6: 6616                     bne.s   loc_407BDBE
0407BDA8: 41f9040b4fd2             lea     (dword_40B4FD2).l,a0
0407BDAE: 23c8040b4fd6             move.l  a0,(dword_40B4FD6).l
0407BDB4: 2088                     move.l  a0,(a0)
0407BDB6: 7001                     moveq   #1,d0
0407BDB8: 23c0040b4fda             move.l  d0,(dword_40B4FDA).l
0407BDBE: 4e5e                     unlk    a6
0407BDC0: 4e75                     rts
