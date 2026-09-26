04050658: 4856                     pea     (a6)
0405065A: 2c4f                     movea.l sp,a6
0405065C: 4280                     clr.l   d0
0405065E: 41f9040c2800             lea     (_wait_queue).l,a0
04050664: 21480004                 move.l  a0,dword_40C2804-_wait_queue(a0)
04050668: 2088                     move.l  a0,(a0)
0405066A: 5048                     addq.w  #8,a0
0405066C: 5280                     addq.l  #1,d0
0405066E: 723a                     moveq   #$3A,d1 ; ':'
04050670: b280                     cmp.l   d0,d1
04050672: 6cf0                     bge.s   loc_4050664
04050674: 4e5e                     unlk    a6
04050676: 4e75                     rts
