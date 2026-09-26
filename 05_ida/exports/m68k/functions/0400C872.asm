0400C872: 4856                     pea     (a6)
0400C874: 2c4f                     movea.l sp,a6
0400C876: 2f0a                     move.l  a2,-(sp)
0400C878: 246e0008                 movea.l 8(a6),a2
0400C87C: 4a8a                     tst.l   a2
0400C87E: 660e                     bne.s   loc_400C88E
0400C880: 4879040a6314             pea     (aSelthreadclear).l; "selthreadclear not passed an address\n"
0400C886: 61fffffff3de             bsr.l   _panic
0400C88C: 584f                     addq.w  #4,sp
0400C88E: 2012                     move.l  (a2),d0
0400C890: 6708                     beq.s   loc_400C89A
0400C892: 2f00                     move.l  d0,-(sp)
0400C894: 61ff00046418             bsr.l   _thread_deallocate_interrupt
0400C89A: 4292                     clr.l   (a2)
0400C89C: 246efffc                 movea.l -4(a6),a2
0400C8A0: 4e5e                     unlk    a6
0400C8A2: 4e75                     rts
