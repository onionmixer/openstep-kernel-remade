F008BF14: 9de3bf98                 save    %sp, -0x68, %sp
F008BF18: f8060000                 ld      [%i0], %i4
F008BF1C: b1372018                 srl     %i4, 24, %i0
F008BF20: 80a62000                 cmp     %i0, 0
F008BF24: 02800027                 be      locret_F008BFC0
F008BF28: 053c0447                 sethi   %hi(dword_F0111EA8), %g2
F008BF2C: f400a2a8                 ld      [%g2+%lo(dword_F0111EA8)], %i2
F008BF30: 86102000                 mov     0, %g3
F008BF34: 80a0c01a                 cmp     %g3, %i2
F008BF38: 3680001b                 bge,a   loc_F008BFA4
F008BF3C: 313c0447                 sethi   -0xFEEE400, %i0
F008BF40: ba100018                 mov     %i0, %i5
F008BF44: 05003fffb610a3ff         set     0xFFFFFF, %i3
F008BF4C: b20f001b                 and     %i4, %i3, %i1
F008BF50: 033fc000                 sethi   -0x1000000, %g1
F008BF54: 053c04c3b010a3b0         set     unk_F0130FB0, %i0
F008BF5C: c40e0000                 ldub    [%i0], %g2
F008BF60: 80a0801d                 cmp     %g2, %i5
F008BF64: 1280000c                 bne     loc_F008BF94
F008BF68: 8600e001                 inc     %g3
F008BF6C: c4060000                 ld      [%i0], %g2
F008BF70: 8608801b                 and     %g2, %i3, %g3
F008BF74: 80a0c019                 cmp     %g3, %i1
F008BF78: 26800002                 bl,a    loc_F008BF80
F008BF7C: 86100019                 mov     %i1, %g3
F008BF80: 84088001                 and     %g2, %g1, %g2
F008BF84: 8608c01b                 and     %g3, %i3, %g3
F008BF88: 84108003                 bset    %g3, %g2
F008BF8C: 1080000d                 ba      locret_F008BFC0
F008BF90: c4260000                 st      %g2, [%i0]
F008BF94: 80a0c01a                 cmp     %g3, %i2
F008BF98: 06bffff1                 bl      loc_F008BF5C
F008BF9C: b0062004                 inc     4, %i0
F008BFA0: 313c0447                 sethi   -0xFEEE400, %i0
F008BFA4: c60622a8                 ld      [%i0+0x2A8], %g3
F008BFA8: 8400e001                 add     %g3, 1, %g2
F008BFAC: c42622a8                 st      %g2, [%i0+0x2A8]
F008BFB0: 053c04c38410a3b0         set     unk_F0130FB0, %g2
F008BFB8: 8728e002                 sll     %g3, 2, %g3
F008BFBC: f820c002                 st      %i4, [%g3+%g2]
F008BFC0: 81c7e008                 ret
F008BFC4: 81e80000                 restore
