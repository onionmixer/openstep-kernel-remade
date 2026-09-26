F0014768: 9de3bf90                 save    %sp, -0x70, %sp
F001476C: f427a04c                 st      %i2, [%fp+arg_4C]
F0014770: f627a050                 st      %i3, [%fp+arg_50]
F0014774: f827a054                 st      %i4, [%fp+arg_54]
F0014778: fa27a058                 st      %i5, [%fp+arg_58]
F001477C: f027bff4                 st      %i0, [%fp+var_C]
F0014780: 90100019                 mov     %i1, %o0
F0014784: 9207a04c                 add     %fp, arg_4C, %o1
F0014788: 94102008                 mov     8, %o2
F001478C: 40000050                 call    _prf
F0014790: 9607bff4                 add     %fp, var_C, %o3
F0014794: d207bff4                 ld      [%fp+var_C], %o1
F0014798: 90026001                 add     %o1, 1, %o0
F001479C: d027bff4                 st      %o0, [%fp+var_C]
F00147A0: c02a4000                 clrb    [%o1]
F00147A4: d007bff4                 ld      [%fp+var_C], %o0
F00147A8: b0220018                 sub     %o0, %i0, %i0
F00147AC: 81c7e008                 ret
F00147B0: 81e80000                 restore
