0404F2E4: 4856                     pea     (a6)
0404F2E6: 2c4f                     movea.l sp,a6
0404F2E8: 206e0008                 movea.l 8(a6),a0
0404F2EC: 52a8013c                 addq.l  #1,$13C(a0)
0404F2F0: 4e5e                     unlk    a6
0404F2F2: 4e75                     rts
