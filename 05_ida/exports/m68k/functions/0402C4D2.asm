0402C4D2: 4856                     pea     (a6)
0402C4D4: 2c4f                     movea.l sp,a6
0402C4D6: 2f0a                     move.l  a2,-(sp)
0402C4D8: 246e0008                 movea.l 8(a6),a2
0402C4DC: 2f0a                     move.l  a2,-(sp)
0402C4DE: 61ff00021612             bsr.l   _mfs_fsync
0402C4E4: 206a002e                 movea.l $2E(a2),a0
0402C4E8: 584f                     addq.w  #4,sp
0402C4EA: 08280004005f             btst    #4,$5F(a0)
0402C4F0: 6708                     beq.s   loc_402C4FA
0402C4F2: 2f0a                     move.l  a2,-(sp)
0402C4F4: 61ff00000040             bsr.l   sub_402C536
0402C4FA: 246efffc                 movea.l -4(a6),a2
0402C4FE: 4e5e                     unlk    a6
0402C500: 4e75                     rts
