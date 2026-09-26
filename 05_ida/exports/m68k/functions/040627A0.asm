040627A0: 4856                     pea     (a6)
040627A2: 2c4f                     movea.l sp,a6
040627A4: 206e0008                 movea.l 8(a6),a0
040627A8: 5268000e                 addq.w  #1,$E(a0)
040627AC: 20280014                 move.l  $14(a0),d0
040627B0: 4e5e                     unlk    a6
040627B2: 4e75                     rts
