0404D61A: 4856                     pea     (a6)
0404D61C: 2c4f                     movea.l sp,a6
0404D61E: 206e0008                 movea.l 8(a6),a0
0404D622: 2050                     movea.l (a0),a0
0404D624: 082800030034             btst    #3,$34(a0)
0404D62A: 6710                     beq.s   loc_404D63C
0404D62C: 4a680004                 tst.w   4(a0)
0404D630: 660a                     bne.s   loc_404D63C
0404D632: 42a7                     clr.l   -(sp)
0404D634: 2f08                     move.l  a0,-(sp)
0404D636: 61ff00000008             bsr.l   _mfs_memfree
0404D63C: 4e5e                     unlk    a6
0404D63E: 4e75                     rts
