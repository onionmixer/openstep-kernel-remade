0405FDAE: 4856                     pea     (a6)
0405FDB0: 2c4f                     movea.l sp,a6
0405FDB2: 206e0008                 movea.l 8(a6),a0
0405FDB6: 4a88                     tst.l   a0
0405FDB8: 671a                     beq.s   loc_405FDD4
0405FDBA: 102e000f                 move.b  $F(a6),d0
0405FDBE: 02000001                 andi.b  #1,d0
0405FDC2: efe800c10042             bfins   d0,$42(a0){3:1}
0405FDC8: 2f08                     move.l  a0,-(sp)
0405FDCA: 61fffffffd4c             bsr.l   _vm_object_deallocate
0405FDD0: 4280                     clr.l   d0
0405FDD2: 6002                     bra.s   loc_405FDD6
0405FDD4: 7004                     moveq   #4,d0
0405FDD6: 4e5e                     unlk    a6
0405FDD8: 4e75                     rts
