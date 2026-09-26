0400AC84: 4856                     pea     (a6)
0400AC86: 2c4f                     movea.l sp,a6
0400AC88: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AC8E: 20680024                 movea.l $24(a0),a0
0400AC92: 20280004                 move.l  4(a0),d0
0400AC96: 2239040b5c9c             move.l  (_domainnamelen).l,d1
0400AC9C: 5281                     addq.l  #1,d1
0400AC9E: b280                     cmp.l   d0,d1
0400ACA0: 6402                     bcc.s   loc_400ACA4
0400ACA2: 2001                     move.l  d1,d0
0400ACA4: 2f00                     move.l  d0,-(sp)
0400ACA6: 2f10                     move.l  (a0),-(sp)
0400ACA8: 4879040b5b9c             pea     (_domainname).l
0400ACAE: 61ffffff69ae             bsr.l   _copyoutmsg
0400ACB4: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400ACBA: 11400064                 move.b  d0,$64(a0)
0400ACBE: 4e5e                     unlk    a6
0400ACC0: 4e75                     rts
