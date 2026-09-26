0400A938: 4856                     pea     (a6)
0400A93A: 2c4f                     movea.l sp,a6
0400A93C: 206e0008                 movea.l 8(a6),a0
0400A940: 4aa80004                 tst.l   4(a0)
0400A944: 6c0a                     bge.s   loc_400A950
0400A946: 5390                     subq.l  #1,(a0)
0400A948: 06a8000f42400004         addi.l  #$F4240,4(a0)
0400A950: 0ca8000f423f0004         cmpi.l  #$F423F,4(a0)
0400A958: 6f0a                     ble.s   loc_400A964
0400A95A: 5290                     addq.l  #1,(a0)
0400A95C: 06a8fff0bdc00004         addi.l  #-$F4240,4(a0)
0400A964: 4e5e                     unlk    a6
0400A966: 4e75                     rts
