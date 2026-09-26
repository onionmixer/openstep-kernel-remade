0402546E: 4856                     pea     (a6)
04025470: 2c4f                     movea.l sp,a6
04025472: 41f9040b6a18             lea     (_udb).l,a0
04025478: 23c8040b6a1c             move.l  a0,(dword_40B6A1C).l
0402547E: 2088                     move.l  a0,(a0)
04025480: 4e5e                     unlk    a6
04025482: 4e75                     rts
