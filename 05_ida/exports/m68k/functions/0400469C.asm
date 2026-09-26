0400469C: 4856                     pea     (a6)
0400469E: 2c4f                     movea.l sp,a6
040046A0: 2f0a                     move.l  a2,-(sp)
040046A2: 246e0008                 movea.l 8(a6),a2
040046A6: 2252                     movea.l (a2),a1
040046A8: 206a0004                 movea.l 4(a2),a0
040046AC: b3fc040b59c4             cmpa.l  #$40B59C4,a1
040046B2: 6608                     bne.s   loc_40046BC
040046B4: 23c8040b59c8             move.l  a0,(dword_40B59C8).l
040046BA: 6004                     bra.s   loc_40046C0
040046BC: 23480004                 move.l  a0,4(a1)
040046C0: 2089                     move.l  a1,(a0)
040046C2: 2f0a                     move.l  a2,-(sp)
040046C4: 2f39040b6068             move.l  (_file_zone).l,-(sp)
040046CA: 61ff00051530             bsr.l   _zfree
040046D0: 246efffc                 movea.l -4(a6),a2
040046D4: 4e5e                     unlk    a6
040046D6: 4e75                     rts
