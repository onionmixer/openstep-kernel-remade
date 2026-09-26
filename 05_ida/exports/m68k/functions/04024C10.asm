04024C10: 4856                     pea     (a6)
04024C12: 2c4f                     movea.l sp,a6
04024C14: 206e0008                 movea.l 8(a6),a0
04024C18: 7003                     moveq   #3,d0
04024C1A: 42700a0a                 clr.w   $A(a0,d0.l*2)
04024C1E: 51c8fffa                 dbf     d0,loc_4024C1A
04024C22: 4240                     clr.w   d0
04024C24: 5380                     subq.l  #1,d0
04024C26: 64f2                     bcc.s   loc_4024C1A
04024C28: 4e5e                     unlk    a6
04024C2A: 4e75                     rts
