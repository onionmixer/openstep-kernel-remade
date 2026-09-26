0404AA94: 4856                     pea     (a6)
0404AA96: 2c4f                     movea.l sp,a6
0404AA98: 2f0a                     move.l  a2,-(sp)
0404AA9A: 246e0008                 movea.l 8(a6),a2
0404AA9E: 2f0a                     move.l  a2,-(sp)
0404AAA0: 61ff0004bd50             bsr.l   _stack_detach
0404AAA6: 584f                     addq.w  #4,sp
0404AAA8: b0aa002c                 cmp.l   $2C(a2),d0
0404AAAC: 6708                     beq.s   loc_404AAB6
0404AAAE: 2f00                     move.l  d0,-(sp)
0404AAB0: 61fffffffab6             bsr.l   _freeStack
0404AAB6: 246efffc                 movea.l -4(a6),a2
0404AABA: 4e5e                     unlk    a6
0404AABC: 4e75                     rts
