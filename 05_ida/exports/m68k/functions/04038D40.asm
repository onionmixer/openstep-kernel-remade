04038D40: 4856                     pea     (a6)
04038D42: 2c4f                     movea.l sp,a6
04038D44: 202e000c                 move.l  $C(a6),d0
04038D48: 43ee0008                 lea     8(a6),a1
04038D4C: 4a91                     tst.l   (a1)
04038D4E: 6716                     beq.s   loc_4038D66
04038D50: 2051                     movea.l (a1),a0
04038D52: b088                     cmp.l   a0,d0
04038D54: 6608                     bne.s   loc_4038D5E
04038D56: 22a80018                 move.l  $18(a0),(a1)
04038D5A: 7001                     moveq   #1,d0
04038D5C: 600a                     bra.s   loc_4038D68
04038D5E: 43e80018                 lea     $18(a0),a1
04038D62: 4a91                     tst.l   (a1)
04038D64: 66ea                     bne.s   loc_4038D50
04038D66: 4280                     clr.l   d0
04038D68: 4e5e                     unlk    a6
04038D6A: 4e75                     rts
