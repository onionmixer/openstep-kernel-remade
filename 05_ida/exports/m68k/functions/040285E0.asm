040285E0: 4856                     pea     (a6)
040285E2: 2c4f                     movea.l sp,a6
040285E4: 206e0008                 movea.l 8(a6),a0
040285E8: 226e000c                 movea.l $C(a6),a1
040285EC: 3010                     move.w  (a0),d0
040285EE: b051                     cmp.w   (a1),d0
040285F0: 6606                     bne.s   loc_40285F8
040285F2: 0c400002                 cmpi.w  #2,d0
040285F6: 6704                     beq.s   loc_40285FC
040285F8: 4280                     clr.l   d0
040285FA: 600e                     bra.s   loc_402860A
040285FC: 20680004                 movea.l 4(a0),a0
04028600: b1e90004                 cmpa.l  4(a1),a0
04028604: 57c0                     seq     d0
04028606: 49c0                     extb.l  d0
04028608: 4480                     neg.l   d0
0402860A: 4e5e                     unlk    a6
0402860C: 4e75                     rts
