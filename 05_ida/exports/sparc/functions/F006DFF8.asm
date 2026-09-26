F006DFF8: 9de3bf90                 save    %sp, -0x70, %sp
F006DFFC: f227a048                 st      %i1, [%fp+arg_48]
F006E000: f427a04c                 st      %i2, [%fp+arg_4C]
F006E004: f627a050                 st      %i3, [%fp+arg_50]
F006E008: f827a054                 st      %i4, [%fp+arg_54]
F006E00C: fa27a058                 st      %i5, [%fp+arg_58]
F006E010: 213c04bda214229c         set     unk_F012F69C, %l1
F006E018: e227bff4                 st      %l1, [%fp+var_C]
F006E01C: 90100018                 mov     %i0, %o0
F006E020: 9207a048                 add     %fp, arg_48, %o1
F006E024: 94102008                 mov     8, %o2
F006E028: 7ffe9a29                 call    _prf
F006E02C: 9607bff4                 add     %fp, var_C, %o3
F006E030: d207bff4                 ld      [%fp+var_C], %o1
F006E034: 90026001                 add     %o1, 1, %o0
F006E038: d027bff4                 st      %o0, [%fp+var_C]
F006E03C: c02a4000                 clrb    [%o1]
F006E040: d04c229c                 ldsb    [%l0+0x29C], %o0
F006E044: 80a22000                 cmp     %o0, 0
F006E048: 0280000c                 be      locret_F006E078
F006E04C: e227bff4                 st      %l1, [%fp+var_C]
F006E050: d207bff4                 ld      [%fp+var_C], %o1
F006E054: 90026001                 add     %o1, 1, %o0
F006E058: d027bff4                 st      %o0, [%fp+var_C]
F006E05C: 40009a0e                 call    _miniMonPutchar
F006E060: d04a4000                 ldsb    [%o1], %o0
F006E064: d007bff4                 ld      [%fp+var_C], %o0
F006E068: d04a0000                 ldsb    [%o0], %o0
F006E06C: 80a22000                 cmp     %o0, 0
F006E070: 12bffff9                 bne     loc_F006E054
F006E074: d207bff4                 ld      [%fp+var_C], %o1
F006E078: 81c7e008                 ret
F006E07C: 81e80000                 restore
