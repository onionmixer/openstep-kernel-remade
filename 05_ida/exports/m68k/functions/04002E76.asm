04002E76: 4856                     pea     (a6)
04002E78: 2c4f                     movea.l sp,a6
04002E7A: 41f9040b58f0             lea     (_bufhash).l,a0
04002E80: 4280                     clr.l   d0
04002E82: 21480008                 move.l  a0,8(a0)
04002E86: 21480004                 move.l  a0,4(a0)
04002E8A: 5280                     addq.l  #1,d0
04002E8C: 5048                     addq.w  #8,a0
04002E8E: 5848                     addq.w  #4,a0
04002E90: 720f                     moveq   #$F,d1
04002E92: b280                     cmp.l   d0,d1
04002E94: 6cec                     bge.s   loc_4002E82
04002E96: 4e5e                     unlk    a6
04002E98: 4e75                     rts
