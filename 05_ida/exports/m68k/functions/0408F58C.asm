0408F58C: 4856                     pea     (a6)
0408F58E: 2c4f                     movea.l sp,a6
0408F590: 2f0a                     move.l  a2,-(sp)
0408F592: 2479040c32f8             movea.l (_slot_id_bmap).l,a2
0408F598: d5fc02006000             adda.l  #$2006000,a2
0408F59E: 0c790139040c32d0         cmpi.w  #$139,(_dma_chip).l
0408F5A6: 6722                     beq.s   loc_408F5CA
0408F5A8: 157c00040004             move.b  #4,4(a2)
0408F5AE: 2f3c0007a120             move.l  #$7A120,-(sp)
0408F5B4: 61ff00002dc4             bsr.l   _delay
0408F5BA: 422a0001                 clr.b   1(a2)
0408F5BE: 42a7                     clr.l   -(sp)
0408F5C0: 486a0003                 pea     3(a2)
0408F5C4: 61ffffffe60c             bsr.l   sub_408DBD2
0408F5CA: 246efffc                 movea.l -4(a6),a2
0408F5CE: 4e5e                     unlk    a6
0408F5D0: 4e75                     rts
