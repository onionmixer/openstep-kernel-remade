04006BE0: 4856                     pea     (a6)
04006BE2: 2c4f                     movea.l sp,a6
04006BE4: 226e0008                 movea.l 8(a6),a1
04006BE8: 2079040b57d0             movea.l (_active_u).l,a0
04006BEE: 2010                     move.l  (a0),d0
04006BF0: b089                     cmp.l   a1,d0
04006BF2: 6712                     beq.s   loc_4006C06
04006BF4: 4a690032                 tst.w   $32(a1)
04006BF8: 6604                     bne.s   loc_4006BFE
04006BFA: 4280                     clr.l   d0
04006BFC: 600a                     bra.s   loc_4006C08
04006BFE: 22690042                 movea.l $42(a1),a1
04006C02: b089                     cmp.l   a1,d0
04006C04: 66ee                     bne.s   loc_4006BF4
04006C06: 7001                     moveq   #1,d0
04006C08: 4e5e                     unlk    a6
04006C0A: 4e75                     rts
