0404B1CE: 4856                     pea     (a6)
0404B1D0: 2c4f                     movea.l sp,a6
0404B1D2: 226e000c                 movea.l $C(a6),a1
0404B1D6: 4aae0008                 tst.l   8(a6)
0404B1DA: 6604                     bne.s   loc_404B1E0
0404B1DC: 7016                     moveq   #$16,d0
0404B1DE: 6018                     bra.s   loc_404B1F8
0404B1E0: 2079040af804             movea.l (_mtime).l,a0
0404B1E6: 2290                     move.l  (a0),(a1)
0404B1E8: 236800040004             move.l  4(a0),4(a1)
0404B1EE: 2211                     move.l  (a1),d1
0404B1F0: b2a80008                 cmp.l   8(a0),d1
0404B1F4: 66f0                     bne.s   loc_404B1E6
0404B1F6: 4280                     clr.l   d0
0404B1F8: 4e5e                     unlk    a6
0404B1FA: 4e75                     rts
