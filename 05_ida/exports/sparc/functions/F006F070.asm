F006F070: 9de3bf98                 save    %sp, -0x68, %sp
F006F074: c606213c                 ld      [%i0+0x13C], %g3
F006F078: 84062138                 add     %i0, 0x138, %g2
F006F07C: 80a08003                 cmp     %g2, %g3
F006F080: 32800003                 bne,a   loc_F006F08C
F006F084: f220e018                 st      %i1, [%g3+0x18]
F006F088: f2262138                 st      %i1, [%i0+0x138]
F006F08C: c626601c                 st      %g3, [%i1+0x1C]
F006F090: 84062138                 add     %i0, 0x138, %g2
F006F094: c4266018                 st      %g2, [%i1+0x18]
F006F098: f226213c                 st      %i1, [%i0+0x13C]
F006F09C: f0266190                 st      %i0, [%i1+0x190]
F006F0A0: c4062140                 ld      [%i0+0x140], %g2
F006F0A4: 8400a001                 inc     %g2
F006F0A8: c4262140                 st      %g2, [%i0+0x140]
F006F0AC: 81c7e008                 ret
F006F0B0: 81e80000                 restore
