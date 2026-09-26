0404F2B0: 4856                     pea     (a6)
0404F2B2: 2c4f                     movea.l sp,a6
0404F2B4: 2f0a                     move.l  a2,-(sp)
0404F2B6: 226e0008                 movea.l 8(a6),a1
0404F2BA: 4a89                     tst.l   a1
0404F2BC: 671e                     beq.s   loc_404F2DC
0404F2BE: 2069013c                 movea.l $13C(a1),a0
0404F2C2: 45e8ffff                 lea     -1(a0),a2
0404F2C6: 234a013c                 move.l  a2,$13C(a1)
0404F2CA: 5348                     subq.w  #1,a0
0404F2CC: 4a88                     tst.l   a0
0404F2CE: 6e0c                     bgt.s   loc_404F2DC
0404F2D0: 4879040a8c3c             pea     (aPsetDeallocate).l; "pset_deallocate: default_pset destroyed"
0404F2D6: 61fffffbc98e             bsr.l   _panic
0404F2DC: 246efffc                 movea.l -4(a6),a2
0404F2E0: 4e5e                     unlk    a6
0404F2E2: 4e75                     rts
