0400F82E: 4856                     pea     (a6)
0400F830: 2c4f                     movea.l sp,a6
0400F832: 226e0008                 movea.l 8(a6),a1
0400F836: 2051                     movea.l (a1),a0
0400F838: 7222                     moveq   #$22,d1 ; '"'
0400F83A: c2a8003a                 and.l   $3A(a0),d1
0400F83E: 7001                     moveq   #1,d0
0400F840: 4a81                     tst.l   d1
0400F842: 6712                     beq.s   loc_400F856
0400F844: 4281                     clr.l   d1
0400F846: 12290015                 move.b  $15(a1),d1
0400F84A: b290                     cmp.l   (a0),d1
0400F84C: 6f08                     ble.s   loc_400F856
0400F84E: 4a290016                 tst.b   $16(a1)
0400F852: 6602                     bne.s   loc_400F856
0400F854: 4280                     clr.l   d0
0400F856: 4e5e                     unlk    a6
0400F858: 4e75                     rts
