0402466A: 4856                     pea     (a6)
0402466C: 2c4f                     movea.l sp,a6
0402466E: 7001                     moveq   #1,d0
04024670: 23c0040bbd28             move.l  d0,(_tcp_iss).l
04024676: 41f9040b7da0             lea     (_tcb).l,a0
0402467C: 23c8040b7da4             move.l  a0,(dword_40B7DA4).l
04024682: 2088                     move.l  a0,(a0)
04024684: 4e5e                     unlk    a6
04024686: 4e75                     rts
