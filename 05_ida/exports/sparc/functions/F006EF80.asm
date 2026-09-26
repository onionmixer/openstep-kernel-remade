F006EF80: 9de3bf98                 save    %sp, -0x68, %sp
F006EF84: c406602c                 ld      [%i1+0x2C], %g2
F006EF88: 80a60002                 cmp     %i0, %g2
F006EF8C: 12800012                 bne     locret_F006EFD4
F006EF90: 8406212c                 add     %i0, 0x12C, %g2
F006EF94: f4066010                 ld      [%i1+0x10], %i2
F006EF98: 80a0801a                 cmp     %g2, %i2
F006EF9C: 12800004                 bne     loc_F006EFAC
F006EFA0: c6066014                 ld      [%i1+0x14], %g3
F006EFA4: 10800004                 ba      loc_F006EFB4
F006EFA8: c6262130                 st      %g3, [%i0+0x130]
F006EFAC: c626a014                 st      %g3, [%i2+0x14]
F006EFB0: 8406212c                 add     %i0, 0x12C, %g2
F006EFB4: 80a08003                 cmp     %g2, %g3
F006EFB8: 32800003                 bne,a   loc_F006EFC4
F006EFBC: f420e010                 st      %i2, [%g3+0x10]
F006EFC0: f426212c                 st      %i2, [%i0+0x12C]
F006EFC4: c026602c                 clr     [%i1+0x2C]
F006EFC8: c4062134                 ld      [%i0+0x134], %g2
F006EFCC: 8400bfff                 inc     -1, %g2
F006EFD0: c4262134                 st      %g2, [%i0+0x134]
F006EFD4: 81c7e008                 ret
F006EFD8: 81e80000                 restore
