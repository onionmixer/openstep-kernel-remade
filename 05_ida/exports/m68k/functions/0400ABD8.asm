0400ABD8: 4856                     pea     (a6)
0400ABDA: 2c4f                     movea.l sp,a6
0400ABDC: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400ABE2: 20680024                 movea.l $24(a0),a0
0400ABE6: 20280004                 move.l  4(a0),d0
0400ABEA: 2239040b5db4             move.l  (_hostnamelen).l,d1
0400ABF0: 5281                     addq.l  #1,d1
0400ABF2: b280                     cmp.l   d0,d1
0400ABF4: 6402                     bcc.s   loc_400ABF8
0400ABF6: 2001                     move.l  d1,d0
0400ABF8: 2f00                     move.l  d0,-(sp)
0400ABFA: 2f10                     move.l  (a0),-(sp)
0400ABFC: 4879040b5cb4             pea     (_hostname).l
0400AC02: 61ffffff6a5a             bsr.l   _copyoutmsg
0400AC08: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AC0E: 11400064                 move.b  d0,$64(a0)
0400AC12: 4e5e                     unlk    a6
0400AC14: 4e75                     rts
