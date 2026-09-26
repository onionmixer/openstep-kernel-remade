0404F79E: 4856                     pea     (a6)
0404F7A0: 2c4f                     movea.l sp,a6
0404F7A2: 2f0a                     move.l  a2,-(sp)
0404F7A4: 206e0008                 movea.l 8(a6),a0
0404F7A8: 226e000c                 movea.l $C(a6),a1
0404F7AC: 2288                     move.l  a0,(a1)
0404F7AE: 236800040004             move.l  4(a0),4(a1)
0404F7B4: 24690004                 movea.l 4(a1),a2
0404F7B8: 2489                     move.l  a1,(a2)
0404F7BA: 21490004                 move.l  a1,4(a0)
0404F7BE: 246efffc                 movea.l -4(a6),a2
0404F7C2: 4e5e                     unlk    a6
0404F7C4: 4e75                     rts
