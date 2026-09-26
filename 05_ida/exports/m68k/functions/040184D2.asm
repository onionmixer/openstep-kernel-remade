040184D2: 4856                     pea     (a6)
040184D4: 2c4f                     movea.l sp,a6
040184D6: 226e0008                 movea.l 8(a6),a1
040184DA: 91c8                     suba.l  a0,a0
040184DC: 082900020003             btst    #2,3(a1)
040184E2: 670c                     beq.s   loc_40184F0
040184E4: 3069001c                 movea.w $1C(a1),a0
040184E8: 4a88                     tst.l   a0
040184EA: 6604                     bne.s   loc_40184F0
040184EC: 7005                     moveq   #5,d0
040184EE: 6002                     bra.s   loc_40184F2
040184F0: 2008                     move.l  a0,d0
040184F2: 4e5e                     unlk    a6
040184F4: 4e75                     rts
