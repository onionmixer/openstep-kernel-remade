040865CC: 4856                     pea     (a6)
040865CE: 2c4f                     movea.l sp,a6
040865D0: 202e0008                 move.l  8(a6),d0
040865D4: 7202                     moveq   #2,d1
040865D6: b280                     cmp.l   d0,d1
040865D8: 6710                     beq.s   loc_40865EA
040865DA: 6c16                     bge.s   loc_40865F2
040865DC: 7204                     moveq   #4,d1
040865DE: b280                     cmp.l   d0,d1
040865E0: 6610                     bne.s   loc_40865F2
040865E2: 203c00000258             move.l  #$258,d0
040865E8: 600e                     bra.s   loc_40865F8
040865EA: 203c00000259             move.l  #$259,d0
040865F0: 6006                     bra.s   loc_40865F8
040865F2: 203c0000025a             move.l  #$25A,d0
040865F8: 4e5e                     unlk    a6
040865FA: 4e75                     rts
