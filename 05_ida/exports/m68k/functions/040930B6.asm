040930B6: 4e560000                 link    a6,#0
040930BA: 206e0008                 movea.l arg_0(a6),a0
040930BE: 226e000c                 movea.l arg_4(a6),a1
040930C2: 222e0010                 move.l  arg_8(a6),d1
040930C6: 5381                     subq.l  #1,d1
040930C8: 6d0a                     blt.s   loc_40930D4
040930CA: 1018                     move.b  (a0)+,d0
040930CC: b019                     cmp.b   (a1)+,d0
040930CE: 660a                     bne.s   loc_40930DA
040930D0: 4a00                     tst.b   d0
040930D2: 66f2                     bne.s   loc_40930C6
040930D4: 7000                     moveq   #0,d0
040930D6: 4e5e                     unlk    a6
040930D8: 4e75                     rts
040930DA: 49c0                     extb.l  d0
040930DC: 1221                     move.b  -(a1),d1
040930DE: 49c1                     extb.l  d1
040930E0: 9081                     sub.l   d1,d0
040930E2: 4e5e                     unlk    a6
040930E4: 4e75                     rts
