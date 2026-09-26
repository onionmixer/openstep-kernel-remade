0407F330: 4856                     pea     (a6)
0407F332: 2c4f                     movea.l sp,a6
0407F334: 206e0008                 movea.l 8(a6),a0
0407F338: 20280004                 move.l  4(a0),d0
0407F33C: b0b9040b2084             cmp.l   (dword_40B2084).l,d0
0407F342: 6408                     bcc.s   loc_407F34C
0407F344: 0268ff7f000a             andi.w  #$FF7F,$A(a0)
0407F34A: 6008                     bra.s   loc_407F354
0407F34C: 2f08                     move.l  a0,-(sp)
0407F34E: 61fffffff568             bsr.l   sub_407E8B8
0407F354: 4e5e                     unlk    a6
0407F356: 4e75                     rts
