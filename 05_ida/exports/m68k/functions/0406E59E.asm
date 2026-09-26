0406E59E: 4856                     pea     (a6)
0406E5A0: 2c4f                     movea.l sp,a6
0406E5A2: 206e0008                 movea.l 8(a6),a0
0406E5A6: 2210                     move.l  (a0),d1
0406E5A8: 2001                     move.l  d1,d0
0406E5AA: d0ae000c                 add.l   $C(a6),d0
0406E5AE: 2080                     move.l  d0,(a0)
0406E5B0: b280                     cmp.l   d0,d1
0406E5B2: 6304                     bls.s   loc_406E5B8
0406E5B4: 52a80004                 addq.l  #1,4(a0)
0406E5B8: 4e5e                     unlk    a6
0406E5BA: 4e75                     rts
