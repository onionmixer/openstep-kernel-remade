F00EE570: 9de3bf88                 save    %sp, -0x78, %sp
F00EE574: d0060000                 ld      [%i0], %o0
F00EE578: d027bfe8                 st      %o0, [%fp+var_18]
F00EE57C: d0062004                 ld      [%i0+4], %o0
F00EE580: d027bfec                 st      %o0, [%fp+var_14]
F00EE584: d0062008                 ld      [%i0+8], %o0
F00EE588: d027bff0                 st      %o0, [%fp+var_10]
F00EE58C: d006200c                 ld      [%i0+0xC], %o0
F00EE590: d027bff4                 st      %o0, [%fp+var_C]
F00EE594: 4000096e                 call    _NXDefaultMallocZone
F00EE598: a007bfe8                 add     %fp, var_18, %l0
F00EE59C: 94100008                 mov     %o0, %o2
F00EE5A0: 90100010                 mov     %l0, %o0
F00EE5A4: 7fffff94                 call    _NXCreateMapTableFromZone
F00EE5A8: 92100019                 mov     %i1, %o1
F00EE5AC: 81c7e008                 ret
F00EE5B0: 91e80008                 restore %g0, %o0, %o0
