0406E758: 4856                     pea     (a6)
0406E75A: 2c4f                     movea.l sp,a6
0406E75C: 202e0008                 move.l  8(a6),d0
0406E760: 43f9040b139e             lea     (_fd_density_sectsize).l,a1
0406E766: 4ab9040b13a2             tst.l   (off_40B13A2).l
0406E76C: 6716                     beq.s   loc_406E784
0406E76E: 41f9040b13a2             lea     (off_40B13A2).l,a0
0406E774: b091                     cmp.l   (a1),d0
0406E776: 6604                     bne.s   loc_406E77C
0406E778: 2010                     move.l  (a0),d0
0406E77A: 6014                     bra.s   loc_406E790
0406E77C: 5048                     addq.w  #8,a0
0406E77E: 5049                     addq.w  #8,a1
0406E780: 4a90                     tst.l   (a0)
0406E782: 66f0                     bne.s   loc_406E774
0406E784: 4879040aa52a             pea     (aFdSectsizeInfo).l; "fd_sectsize_info: bad density"
0406E78A: 61fffff9d4da             bsr.l   _panic
0406E790: 4e5e                     unlk    a6
0406E792: 4e75                     rts
