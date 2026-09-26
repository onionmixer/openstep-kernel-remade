0406E574: 4856                     pea     (a6)
0406E576: 2c4f                     movea.l sp,a6
0406E578: 206e0008                 movea.l 8(a6),a0
0406E57C: 226e000c                 movea.l $C(a6),a1
0406E580: 22280004                 move.l  4(a0),d1
0406E584: 20290004                 move.l  4(a1),d0
0406E588: b081                     cmp.l   d1,d0
0406E58A: 6704                     beq.s   loc_406E590
0406E58C: 55c0                     scs     d0
0406E58E: 6006                     bra.s   loc_406E596
0406E590: 2050                     movea.l (a0),a0
0406E592: b1d1                     cmpa.l  (a1),a0
0406E594: 52c0                     shi     d0
0406E596: 49c0                     extb.l  d0
0406E598: 4480                     neg.l   d0
0406E59A: 4e5e                     unlk    a6
0406E59C: 4e75                     rts
