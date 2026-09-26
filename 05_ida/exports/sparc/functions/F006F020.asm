F006F020: 9de3bf98                 save    %sp, -0x68, %sp
F006F024: f4066018                 ld      [%i1+0x18], %i2
F006F028: 84062138                 add     %i0, 0x138, %g2
F006F02C: 80a0801a                 cmp     %g2, %i2
F006F030: 12800004                 bne     loc_F006F040
F006F034: c606601c                 ld      [%i1+0x1C], %g3
F006F038: 10800004                 ba      loc_F006F048
F006F03C: c626213c                 st      %g3, [%i0+0x13C]
F006F040: c626a01c                 st      %g3, [%i2+0x1C]
F006F044: 84062138                 add     %i0, 0x138, %g2
F006F048: 80a08003                 cmp     %g2, %g3
F006F04C: 32800003                 bne,a   loc_F006F058
F006F050: f420e018                 st      %i2, [%g3+0x18]
F006F054: f4262138                 st      %i2, [%i0+0x138]
F006F058: c0266190                 clr     [%i1+0x190]
F006F05C: c4062140                 ld      [%i0+0x140], %g2
F006F060: 8400bfff                 inc     -1, %g2
F006F064: c4262140                 st      %g2, [%i0+0x140]
F006F068: 81c7e008                 ret
F006F06C: 81e80000                 restore
