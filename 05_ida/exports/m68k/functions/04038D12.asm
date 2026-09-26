04038D12: 4856                     pea     (a6)
04038D14: 2c4f                     movea.l sp,a6
04038D16: 226e0008                 movea.l 8(a6),a1
04038D1A: 202e000c                 move.l  $C(a6),d0
04038D1E: 671c                     beq.s   loc_4038D3C
04038D20: 20690018                 movea.l $18(a1),a0
04038D24: 4a88                     tst.l   a0
04038D26: 660a                     bne.s   loc_4038D32
04038D28: 23400018                 move.l  d0,$18(a1)
04038D2C: 600e                     bra.s   loc_4038D3C
04038D2E: 20680018                 movea.l $18(a0),a0
04038D32: 4aa80018                 tst.l   $18(a0)
04038D36: 66f6                     bne.s   loc_4038D2E
04038D38: 21400018                 move.l  d0,$18(a0)
04038D3C: 4e5e                     unlk    a6
04038D3E: 4e75                     rts
