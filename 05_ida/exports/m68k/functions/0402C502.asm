0402C502: 4856                     pea     (a6)
0402C504: 2c4f                     movea.l sp,a6
0402C506: 2f0a                     move.l  a2,-(sp)
0402C508: 246e0008                 movea.l 8(a6),a2
0402C50C: 2f2e000c                 move.l  $C(a6),-(sp)
0402C510: 2f0a                     move.l  a2,-(sp)
0402C512: 61ff0002161e             bsr.l   _mfs_fsync_invalidate
0402C518: 206a002e                 movea.l $2E(a2),a0
0402C51C: 504f                     addq.w  #8,sp
0402C51E: 08280004005f             btst    #4,$5F(a0)
0402C524: 6708                     beq.s   loc_402C52E
0402C526: 2f0a                     move.l  a2,-(sp)
0402C528: 61ff0000000c             bsr.l   sub_402C536
0402C52E: 246efffc                 movea.l -4(a6),a2
0402C532: 4e5e                     unlk    a6
0402C534: 4e75                     rts
