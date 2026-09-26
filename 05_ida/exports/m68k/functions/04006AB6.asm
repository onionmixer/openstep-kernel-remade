04006AB6: 4856                     pea     (a6)
04006AB8: 2c4f                     movea.l sp,a6
04006ABA: 226e0008                 movea.l 8(a6),a1
04006ABE: 2079040b57d0             movea.l (_active_u).l,a0
04006AC4: 2068014a                 movea.l $14A(a0),a0
04006AC8: 023100fd8800             andi.b  #$FD,(a1,a0.l)
04006ACE: 4e5e                     unlk    a6
04006AD0: 4e75                     rts
