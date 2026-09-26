040249DA: 4856                     pea     (a6)
040249DC: 2c4f                     movea.l sp,a6
040249DE: 2f0b                     move.l  a3,-(sp)
040249E0: 2f0a                     move.l  a2,-(sp)
040249E2: 266e0008                 movea.l 8(a6),a3
040249E6: 206b0018                 movea.l $18(a3),a0
040249EA: 4280                     clr.l   d0
040249EC: 30280050                 move.w  $50(a0),d0
040249F0: 0c6800040006             cmpi.w  #4,6(a0)
040249F6: 671c                     beq.s   loc_4024A14
040249F8: 7241                     moveq   #$41,d1 ; 'A'
040249FA: b280                     cmp.l   d0,d1
040249FC: 670c                     beq.s   loc_4024A0A
040249FE: 7233                     moveq   #$33,d1 ; '3'
04024A00: b280                     cmp.l   d0,d1
04024A02: 6706                     beq.s   loc_4024A0A
04024A04: 7240                     moveq   #$40,d1 ; '@'
04024A06: b280                     cmp.l   d0,d1
04024A08: 660a                     bne.s   loc_4024A14
04024A0A: 206b0018                 movea.l $18(a3),a0
04024A0E: 42680050                 clr.w   $50(a0)
04024A12: 6034                     bra.s   loc_4024A48
04024A14: 206b001c                 movea.l $1C(a3),a0
04024A18: 3140006a                 move.w  d0,$6A(a0)
04024A1C: 724e                     moveq   #$4E,d1 ; 'N'
04024A1E: d2ab0018                 add.l   $18(a3),d1
04024A22: 2f01                     move.l  d1,-(sp)
04024A24: 61fffffe57dc             bsr.l   _wakeup
04024A2A: 206b0018                 movea.l $18(a3),a0
04024A2E: 48680022                 pea     $22(a0)
04024A32: 2f08                     move.l  a0,-(sp)
04024A34: 45f9040140d4             lea     (_sowakeup).l,a2
04024A3A: 4e92                     jsr     (a2)
04024A3C: 206b0018                 movea.l $18(a3),a0
04024A40: 48680038                 pea     $38(a0)
04024A44: 2f08                     move.l  a0,-(sp)
04024A46: 4e92                     jsr     (a2)
04024A48: 246efff8                 movea.l -8(a6),a2
04024A4C: 266efffc                 movea.l -4(a6),a3
04024A50: 4e5e                     unlk    a6
04024A52: 4e75                     rts
