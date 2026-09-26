04053B02: 4856                     pea     (a6)
04053B04: 2c4f                     movea.l sp,a6
04053B06: 4280                     clr.l   d0
04053B08: 206e0008                 movea.l 8(a6),a0
04053B0C: 0c90deadbeef             cmpi.l  #$DEADBEEF,(a0)
04053B12: 660c                     bne.s   loc_4053B20
04053B14: 5848                     addq.w  #4,a0
04053B16: 5280                     addq.l  #1,d0
04053B18: 0c80000003fc             cmpi.l  #$3FC,d0
04053B1E: 63ec                     bls.s   loc_4053B0C
04053B20: e580                     asl.l   #2,d0
04053B22: 223c00000ff4             move.l  #$FF4,d1
04053B28: 9280                     sub.l   d0,d1
04053B2A: 2001                     move.l  d1,d0
04053B2C: 4e5e                     unlk    a6
04053B2E: 4e75                     rts
