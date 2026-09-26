0401D362: 4856                     pea     (a6)
0401D364: 2c4f                     movea.l sp,a6
0401D366: 41f9040b6de8             lea     (_rawcb).l,a0
0401D36C: 23c8040b6dec             move.l  a0,(dword_40B6DEC).l
0401D372: 2088                     move.l  a0,(a0)
0401D374: 7032                     moveq   #$32,d0 ; '2'
0401D376: 23c0040b5a70             move.l  d0,(dword_40B5A70).l
0401D37C: 4e5e                     unlk    a6
0401D37E: 4e75                     rts
