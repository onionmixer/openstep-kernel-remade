040639F6: 4856                     pea     (a6)
040639F8: 2c4f                     movea.l sp,a6
040639FA: 2f2e001c                 move.l  $1C(a6),-(sp)
040639FE: 2f2e0018                 move.l  $18(a6),-(sp)
04063A02: 2f2e0010                 move.l  $10(a6),-(sp)
04063A06: 2f2e0014                 move.l  $14(a6),-(sp)
04063A0A: 42a7                     clr.l   -(sp)
04063A0C: 306e000e                 movea.w $E(a6),a0
04063A10: 2f08                     move.l  a0,-(sp)
04063A12: 306e000a                 movea.w $A(a6),a0
04063A16: 2f08                     move.l  a0,-(sp)
04063A18: 42a7                     clr.l   -(sp)
04063A1A: 61ff00000008             bsr.l   sub_4063A24
04063A20: 4e5e                     unlk    a6
04063A22: 4e75                     rts
