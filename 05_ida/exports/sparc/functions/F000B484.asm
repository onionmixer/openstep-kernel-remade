F000B484: 9de3bf98                 save    %sp, -0x68, %sp
F000B488: 073c04cf                 sethi   %hi(_active_u), %g3
F000B48C: f200e1d8                 ld      [%g3+%lo(_active_u)], %i1
F000B490: c4066158                 ld      [%i1+0x158], %g2
F000B494: 80a60002                 cmp     %i0, %g2
F000B498: 1a800008                 bcc     loc_F000B4B8
F000B49C: b410e1d8                 or      %g3, %lo(_active_u), %i2
F000B4A0: c606614c                 ld      [%i1+0x14C], %g3
F000B4A4: 852e2002                 sll     %i0, 2, %g2
F000B4A8: f000c002                 ld      [%g3+%g2], %i0
F000B4AC: 80a62000                 cmp     %i0, 0
F000B4B0: 12800004                 bne     loc_F000B4C0
F000B4B4: 053fffc0                 sethi   -0x10000, %g2
F000B4B8: 10800005                 ba      loc_F000B4CC
F000B4BC: b0102000                 mov     0, %i0
F000B4C0: 80a60002                 cmp     %i0, %g2
F000B4C4: 12800005                 bne     locret_F000B4D8
F000B4C8: 01000000                 nop
F000B4CC: c606a004                 ld      [%i2+4], %g3
F000B4D0: 84102009                 mov     9, %g2
F000B4D4: c428e038                 stb     %g2, [%g3+0x38]
F000B4D8: 81c7e008                 ret
F000B4DC: 81e80000                 restore
