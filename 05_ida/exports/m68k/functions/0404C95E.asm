0404C95E: 4856                     pea     (a6)
0404C960: 2c4f                     movea.l sp,a6
0404C962: 206e0008                 movea.l 8(a6),a0
0404C966: 0ca8000007a70028         cmpi.l  #$7A7,$28(a0)
0404C96E: 660c                     bne.s   loc_404C97C
0404C970: 2f08                     move.l  a0,-(sp)
0404C972: 61fffffffde4             bsr.l   sub_404C758
0404C978: 7001                     moveq   #1,d0
0404C97A: 6002                     bra.s   loc_404C97E
0404C97C: 4280                     clr.l   d0
0404C97E: 4e5e                     unlk    a6
0404C980: 4e75                     rts
