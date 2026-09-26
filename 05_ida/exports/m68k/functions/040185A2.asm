040185A2: 4856                     pea     (a6)
040185A4: 2c4f                     movea.l sp,a6
040185A6: 2f0a                     move.l  a2,-(sp)
040185A8: 23fc040b6d60040b6d68     move.l  #$40B6D60,(dword_40B6D68).l
040185B2: 23fc040b6d60040b6d6c     move.l  #$40B6D60,(dword_40B6D6C).l
040185BC: 4280                     clr.l   d0
040185BE: b0b9040af728             cmp.l   (_ncsize).l,d0
040185C4: 6c46                     bge.s   loc_401860C
040185C6: 95ca                     suba.l  a2,a2
040185C8: 2079040b6d70             movea.l (_ncache).l,a0
040185CE: d1ca                     adda.l  a2,a0
040185D0: 2279040b6d68             movea.l (dword_40B6D68).l,a1
040185D6: 23c8040b6d68             move.l  a0,(dword_40B6D68).l
040185DC: 21490008                 move.l  a1,8(a0)
040185E0: 2348000c                 move.l  a0,$C(a1)
040185E4: 217c040b6d60000c         move.l  #$40B6D60,$C(a0)
040185EC: 21480004                 move.l  a0,4(a0)
040185F0: 2088                     move.l  a0,(a0)
040185F2: 42a80010                 clr.l   $10(a0)
040185F6: 42a80014                 clr.l   $14(a0)
040185FA: 42280042                 clr.b   $42(a0)
040185FE: d4fc0046                 adda.w  #$46,a2 ; 'F'
04018602: 5280                     addq.l  #1,d0
04018604: b0b9040af728             cmp.l   (_ncsize).l,d0
0401860A: 6dbc                     blt.s   loc_40185C8
0401860C: 4280                     clr.l   d0
0401860E: 41f9040b6b60             lea     (_nc_hash).l,a0
04018614: 21480004                 move.l  a0,dword_40B6B64-_nc_hash(a0)
04018618: 2088                     move.l  a0,(a0)
0401861A: 5048                     addq.w  #8,a0
0401861C: 5280                     addq.l  #1,d0
0401861E: 723f                     moveq   #$3F,d1 ; '?'
04018620: b280                     cmp.l   d0,d1
04018622: 6cf0                     bge.s   loc_4018614
04018624: 246efffc                 movea.l -4(a6),a2
04018628: 4e5e                     unlk    a6
0401862A: 4e75                     rts
