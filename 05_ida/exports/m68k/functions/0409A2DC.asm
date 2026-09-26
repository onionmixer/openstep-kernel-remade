0409A2DC: 4856                     pea     (a6)
0409A2DE: 2c4f                     movea.l sp,a6
0409A2E0: 206e0008                 movea.l 8(a6),a0
0409A2E4: 02683fff0040             andi.w  #$3FFF,$40(a0)
0409A2EA: 42a7                     clr.l   -(sp)
0409A2EC: 42a7                     clr.l   -(sp)
0409A2EE: 42a7                     clr.l   -(sp)
0409A2F0: 48780006                 pea     (6).w
0409A2F4: 61fffffad2b4             bsr.l   _exception_with_continuation
0409A2FA: 4e5e                     unlk    a6
0409A2FC: 4e75                     rts
