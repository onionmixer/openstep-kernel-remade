F00433D0: 9de3bf88                 save    %sp, -0x78, %sp
F00433D4: 9410001a                 mov     %i2, %o2
F00433D8: 9610001b                 mov     %i3, %o3
F00433DC: d207a05c                 ld      [%fp+arg_5C], %o1
F00433E0: 9810001c                 mov     %i4, %o4
F00433E4: d0024000                 ld      [%o1], %o0
F00433E8: 9a10001d                 mov     %i5, %o5
F00433EC: d027bff0                 st      %o0, [%fp+var_10]
F00433F0: d2026004                 ld      [%o1+4], %o1
F00433F4: 90100018                 mov     %i0, %o0
F00433F8: d227bff4                 st      %o1, [%fp+var_C]
F00433FC: 9207bff0                 add     %fp, var_10, %o1
F0043400: d223a05c                 st      %o1, [%sp+0x78+var_1C]
F0043404: c023a060                 clr     [%sp+0x78+var_18]
F0043408: 7ffffe01                 call    _clntkudp_callit_addr
F004340C: 92100019                 mov     %i1, %o1
F0043410: 81c7e008                 ret
F0043414: 91e80008                 restore %g0, %o0, %o0
