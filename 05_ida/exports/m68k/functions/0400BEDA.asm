0400BEDA: 4856                     pea     (a6)
0400BEDC: 2c4f                     movea.l sp,a6
0400BEDE: 2079040b57d0             movea.l (_active_u).l,a0
0400BEE4: 2028005a                 move.l  $5A(a0),d0
0400BEE8: 7201                     moveq   #1,d1
0400BEEA: b280                     cmp.l   d0,d1
0400BEEC: 6706                     beq.s   loc_400BEF4
0400BEEE: 7203                     moveq   #3,d1
0400BEF0: b280                     cmp.l   d0,d1
0400BEF2: 660c                     bne.s   loc_400BF00
0400BEF4: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400BEFA: 117c00160064             move.b  #$16,$64(a0)
0400BF00: 42a7                     clr.l   -(sp)
0400BF02: 2f3c00010000             move.l  #$10000,-(sp)
0400BF08: 48780005                 pea     (5).w
0400BF0C: 61ff0003b7c6             bsr.l   _exception_from_kernel
0400BF12: 4e5e                     unlk    a6
0400BF14: 4e75                     rts
