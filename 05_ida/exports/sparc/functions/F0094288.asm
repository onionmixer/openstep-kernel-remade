F0094288: 9de3bf90                 save    %sp, -0x70, %sp
F009428C: f227a048                 st      %i1, [%fp+arg_48]
F0094290: f427a04c                 st      %i2, [%fp+arg_4C]
F0094294: f627a050                 st      %i3, [%fp+arg_50]
F0094298: f827a054                 st      %i4, [%fp+arg_54]
F009429C: fa27a058                 st      %i5, [%fp+arg_58]
F00942A0: 213c04c4a2142268         set     unk_F0131268, %l1
F00942A8: e227bff4                 st      %l1, [%fp+var_C]
F00942AC: 90100018                 mov     %i0, %o0
F00942B0: 9207a048                 add     %fp, arg_48, %o1
F00942B4: 94102008                 mov     8, %o2
F00942B8: 7ffe0185                 call    _prf
F00942BC: 9607bff4                 add     %fp, var_C, %o3
F00942C0: d207bff4                 ld      [%fp+var_C], %o1
F00942C4: 90026001                 add     %o1, 1, %o0
F00942C8: d027bff4                 st      %o0, [%fp+var_C]
F00942CC: c02a4000                 clrb    [%o1]
F00942D0: d04c2268                 ldsb    [%l0+0x268], %o0
F00942D4: 80a22000                 cmp     %o0, 0
F00942D8: 0280000c                 be      locret_F0094308
F00942DC: e227bff4                 st      %l1, [%fp+var_C]
F00942E0: d207bff4                 ld      [%fp+var_C], %o1
F00942E4: 90026001                 add     %o1, 1, %o0
F00942E8: d027bff4                 st      %o0, [%fp+var_C]
F00942EC: 40007641                 call    _cnputc
F00942F0: d04a4000                 ldsb    [%o1], %o0
F00942F4: d007bff4                 ld      [%fp+var_C], %o0
F00942F8: d04a0000                 ldsb    [%o0], %o0
F00942FC: 80a22000                 cmp     %o0, 0
F0094300: 12bffff9                 bne     loc_F00942E4
F0094304: d207bff4                 ld      [%fp+var_C], %o1
F0094308: 81c7e008                 ret
F009430C: 81e80000                 restore
