04038728: 4856                     pea     (a6)
0403872A: 2c4f                     movea.l sp,a6
0403872C: 2f0b                     move.l  a3,-(sp)
0403872E: 2f0a                     move.l  a2,-(sp)
04038730: 226e0008                 movea.l 8(a6),a1
04038734: 4aa90008                 tst.l   8(a1)
04038738: 6e46                     bgt.s   loc_4038780
0403873A: 703f                     moveq   #$3F,d0 ; '?'
0403873C: c091                     and.l   (a1),d0
0403873E: 41f9040c20b0             lea     (_lf_svnode_hash).l,a0
04038744: 47f00c00                 lea     (a0,d0.l*4),a3
04038748: 4a93                     tst.l   (a3)
0403874A: 6728                     beq.s   loc_4038774
0403874C: 2453                     movea.l (a3),a2
0403874E: b3ca                     cmpa.l  a2,a1
04038750: 661a                     bne.s   loc_403876C
04038752: 2f12                     move.l  (a2),-(sp)
04038754: 61fffffe2970             bsr.l   _vn_rele
0403875A: 26aa000c                 move.l  $C(a2),(a3)
0403875E: 48780010                 pea     ($10).w
04038762: 2f0a                     move.l  a2,-(sp)
04038764: 61ff00011b5e             bsr.l   _kfree
0403876A: 6014                     bra.s   loc_4038780
0403876C: 47ea000c                 lea     $C(a2),a3
04038770: 4a93                     tst.l   (a3)
04038772: 66d8                     bne.s   loc_403874C
04038774: 4879040a811b             pea     (aLfFreeSvnodeCa).l; "lf_free_svnode: cannot find shadow vnod"...
0403877A: 61fffffd34ea             bsr.l   _panic
04038780: 246efff8                 movea.l -8(a6),a2
04038784: 266efffc                 movea.l -4(a6),a3
04038788: 4e5e                     unlk    a6
0403878A: 4e75                     rts
