04014180: 4856                     pea     (a6)
04014182: 2c4f                     movea.l sp,a6
04014184: 206e0008                 movea.l 8(a6),a0
04014188: 202e000c                 move.l  $C(a6),d0
0401418C: 0c800000cccc             cmpi.l  #$CCCC,d0
04014192: 6304                     bls.s   loc_4014198
04014194: 4280                     clr.l   d0
04014196: 6018                     bra.s   loc_40141B0
04014198: 31400002                 move.w  d0,2(a0)
0401419C: d080                     add.l   d0,d0
0401419E: 0c800000ffff             cmpi.l  #$FFFF,d0
040141A4: 6f04                     ble.s   loc_40141AA
040141A6: 7000                     moveq   #0,d0
040141A8: 4640                     not.w   d0
040141AA: 31400006                 move.w  d0,6(a0)
040141AE: 7001                     moveq   #1,d0
040141B0: 4e5e                     unlk    a6
040141B2: 4e75                     rts
