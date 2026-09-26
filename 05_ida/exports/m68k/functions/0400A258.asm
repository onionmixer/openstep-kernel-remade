0400A258: 4856                     pea     (a6)
0400A25A: 2c4f                     movea.l sp,a6
0400A25C: 4280                     clr.l   d0
0400A25E: 41f9040b6540             lea     (_qs).l,a0
0400A264: 21480004                 move.l  a0,dword_40B6544-_qs(a0)
0400A268: 2088                     move.l  a0,(a0)
0400A26A: 5048                     addq.w  #8,a0
0400A26C: 5280                     addq.l  #1,d0
0400A26E: 721f                     moveq   #$1F,d1
0400A270: b280                     cmp.l   d0,d1
0400A272: 6cf0                     bge.s   loc_400A264
0400A274: 4e5e                     unlk    a6
0400A276: 4e75                     rts
