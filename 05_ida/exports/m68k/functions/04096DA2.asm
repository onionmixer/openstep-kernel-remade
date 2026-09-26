04096DA2: 4856                     pea     (a6)
04096DA4: 2c4f                     movea.l sp,a6
04096DA6: 226e0010                 movea.l $10(a6),a1
04096DAA: 206e0018                 movea.l $18(a6),a0
04096DAE: 7201                     moveq   #1,d1
04096DB0: b2ae000c                 cmp.l   $C(a6),d1
04096DB4: 6610                     bne.s   loc_4096DC6
04096DB6: 7211                     moveq   #$11,d1
04096DB8: b2ae0014                 cmp.l   $14(a6),d1
04096DBC: 6504                     bcs.s   loc_4096DC2
04096DBE: 7004                     moveq   #4,d0
04096DC0: 6006                     bra.s   loc_4096DC8
04096DC2: 20a90044                 move.l  $44(a1),(a0)
04096DC6: 4280                     clr.l   d0
04096DC8: 4e5e                     unlk    a6
04096DCA: 4e75                     rts
