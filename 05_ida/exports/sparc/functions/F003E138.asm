F003E138: 9de3bf80                 save    %sp, -0x80, %sp
F003E13C: 113c04cf                 sethi   %hi(_active_u), %o0
F003E140: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F003E144: e207a05c                 ld      [%fp+arg_5C], %l1
F003E148: 9410001a                 mov     %i2, %o2
F003E14C: e407a060                 ld      [%fp+arg_60], %l2
F003E150: 96102005                 mov     5, %o3
F003E154: d802601c                 ld      [%o1+0x1C], %o4
F003E158: 90100018                 mov     %i0, %o0
F003E15C: 40001221                 call    _clntkudp_create
F003E160: 92100019                 mov     %i1, %o1
F003E164: 92102003                 mov     3, %o1
F003E168: d227bff0                 st      %o1, [%fp+var_10]
F003E16C: c027bff4                 clr     [%fp+var_C]
F003E170: d227bfe8                 st      %o1, [%fp+var_18]
F003E174: c027bfec                 clr     [%fp+var_14]
F003E178: a0100008                 mov     %o0, %l0
F003E17C: 9210001b                 mov     %i3, %o1
F003E180: 9410001c                 mov     %i4, %o2
F003E184: 9610001d                 mov     %i5, %o3
F003E188: 98100011                 mov     %l1, %o4
F003E18C: c4042004                 ld      [%l0+4], %g2
F003E190: 9a07bfe8                 add     %fp, var_18, %o5
F003E194: da23a05c                 st      %o5, [%sp+0x80+var_24]
F003E198: c4008000                 ld      [%g2], %g2
F003E19C: 9fc08000                 call    %g2
F003E1A0: 9a100012                 mov     %l2, %o5
F003E1A4: d4040000                 ld      [%l0], %o2
F003E1A8: d202a020                 ld      [%o2+0x20], %o1
F003E1AC: b0100008                 mov     %o0, %i0
F003E1B0: d2026010                 ld      [%o1+0x10], %o1
F003E1B4: 9fc24000                 call    %o1
F003E1B8: 9010000a                 mov     %o2, %o0
F003E1BC: d0042004                 ld      [%l0+4], %o0
F003E1C0: d2022010                 ld      [%o0+0x10], %o1
F003E1C4: 9fc24000                 call    %o1
F003E1C8: 90100010                 mov     %l0, %o0
F003E1CC: 81c7e008                 ret
F003E1D0: 81e80000                 restore
