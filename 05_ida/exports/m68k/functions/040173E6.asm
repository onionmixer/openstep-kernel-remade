040173E6: 4856                     pea     (a6)
040173E8: 2c4f                     movea.l sp,a6
040173EA: 226e0008                 movea.l 8(a6),a1
040173EE: 2079040b67cc             movea.l (_rootvfs).l,a0
040173F4: 4a88                     tst.l   a0
040173F6: 6718                     beq.s   loc_4017410
040173F8: 2011                     move.l  (a1),d0
040173FA: b0a80014                 cmp.l   $14(a0),d0
040173FE: 660a                     bne.s   loc_401740A
04017400: 22280018                 move.l  $18(a0),d1
04017404: b2a90004                 cmp.l   4(a1),d1
04017408: 6706                     beq.s   loc_4017410
0401740A: 2050                     movea.l (a0),a0
0401740C: 4a88                     tst.l   a0
0401740E: 66ea                     bne.s   loc_40173FA
04017410: 2008                     move.l  a0,d0
04017412: 4e5e                     unlk    a6
04017414: 4e75                     rts
