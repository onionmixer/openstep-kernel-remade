04096F96: 4856                     pea     (a6)
04096F98: 2c4f                     movea.l sp,a6
04096F9A: 2f0a                     move.l  a2,-(sp)
04096F9C: 2f02                     move.l  d2,-(sp)
04096F9E: 246e0008                 movea.l 8(a6),a2
04096FA2: 242e000c                 move.l  $C(a6),d2
04096FA6: 4878001c                 pea     ($1C).w
04096FAA: 2f0a                     move.l  a2,-(sp)
04096FAC: 61ffffffbe64             bsr.l   _bzero
04096FB2: 25420008                 move.l  d2,8(a2)
04096FB6: 2239040b06d0             move.l  (_page_size).l,d1
04096FBC: 4c421001                 divu.l  d2,d1
04096FC0: 25410018                 move.l  d1,$18(a2)
04096FC4: 242efff8                 move.l  -8(a6),d2
04096FC8: 246efffc                 movea.l -4(a6),a2
04096FCC: 4e5e                     unlk    a6
04096FCE: 4e75                     rts
