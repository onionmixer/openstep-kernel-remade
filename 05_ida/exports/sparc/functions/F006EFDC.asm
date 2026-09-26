F006EFDC: 9de3bf98                 save    %sp, -0x68, %sp
F006EFE0: c6062130                 ld      [%i0+0x130], %g3
F006EFE4: 8406212c                 add     %i0, 0x12C, %g2
F006EFE8: 80a08003                 cmp     %g2, %g3
F006EFEC: 32800003                 bne,a   loc_F006EFF8
F006EFF0: f220e010                 st      %i1, [%g3+0x10]
F006EFF4: f226212c                 st      %i1, [%i0+0x12C]
F006EFF8: c6266014                 st      %g3, [%i1+0x14]
F006EFFC: 8406212c                 add     %i0, 0x12C, %g2
F006F000: c4266010                 st      %g2, [%i1+0x10]
F006F004: f2262130                 st      %i1, [%i0+0x130]
F006F008: f026602c                 st      %i0, [%i1+0x2C]
F006F00C: c4062134                 ld      [%i0+0x134], %g2
F006F010: 8400a001                 inc     %g2
F006F014: c4262134                 st      %g2, [%i0+0x134]
F006F018: 81c7e008                 ret
F006F01C: 81e80000                 restore
