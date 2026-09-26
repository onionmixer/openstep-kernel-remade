04053B30: 4856                     pea     (a6)
04053B32: 2c4f                     movea.l sp,a6
04053B34: 4ab9040aff14             tst.l   (_stack_check_usage).l
04053B3A: 6716                     beq.s   loc_4053B52
04053B3C: 4280                     clr.l   d0
04053B3E: 206e0008                 movea.l 8(a6),a0
04053B42: 20fcdeadbeef             move.l  #$DEADBEEF,(a0)+
04053B48: 5280                     addq.l  #1,d0
04053B4A: 0c80000003fc             cmpi.l  #$3FC,d0
04053B50: 63f0                     bls.s   loc_4053B42
04053B52: 4e5e                     unlk    a6
04053B54: 4e75                     rts
