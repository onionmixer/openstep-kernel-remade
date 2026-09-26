0404F7C6: 4856                     pea     (a6)
0404F7C8: 2c4f                     movea.l sp,a6
0404F7CA: 2f0a                     move.l  a2,-(sp)
0404F7CC: 246e0008                 movea.l 8(a6),a2
0404F7D0: 2252                     movea.l (a2),a1
0404F7D2: b5c9                     cmpa.l  a1,a2
0404F7D4: 670c                     beq.s   loc_404F7E2
0404F7D6: 2051                     movea.l (a1),a0
0404F7D8: 214a0004                 move.l  a2,4(a0)
0404F7DC: 2491                     move.l  (a1),(a2)
0404F7DE: 2009                     move.l  a1,d0
0404F7E0: 6002                     bra.s   loc_404F7E4
0404F7E2: 4280                     clr.l   d0
0404F7E4: 246efffc                 movea.l -4(a6),a2
0404F7E8: 4e5e                     unlk    a6
0404F7EA: 4e75                     rts
