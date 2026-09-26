F00ED164: 9de3bf88                 save    %sp, -0x78, %sp! z
F00ED168: d0060000                 ld      [%i0], %o0
F00ED16C: d027bfe8                 st      %o0, [%fp+var_18]
F00ED170: d0062004                 ld      [%i0+4], %o0
F00ED174: d027bfec                 st      %o0, [%fp+var_14]
F00ED178: d0062008                 ld      [%i0+8], %o0
F00ED17C: d027bff0                 st      %o0, [%fp+var_10]
F00ED180: d006200c                 ld      [%i0+0xC], %o0
F00ED184: d027bff4                 st      %o0, [%fp+var_C]
F00ED188: 40000e71                 call    _NXDefaultMallocZone
F00ED18C: a007bfe8                 add     %fp, var_18, %l0
F00ED190: 96100008                 mov     %o0, %o3
F00ED194: 90100010                 mov     %l0, %o0! prototype
F00ED198: 92100019                 mov     %i1, %o1
F00ED19C: 40000004                 call    _NXCreateHashTableFromZone
F00ED1A0: 9410001a                 mov     %i2, %o2
F00ED1A4: 81c7e008                 ret
F00ED1A8: 91e80008                 restore %g0, %o0, %o0
