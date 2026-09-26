F00F25A4: 9de3bf88                 save    %sp, -0x78, %sp! z
F00F25A8: 113c04bc92122138         set     unk_F012F138, %o1
F00F25B0: d0022138                 ld      [%o0+0x138], %o0
F00F25B4: d027bfe8                 st      %o0, [%fp+var_18]
F00F25B8: d0026004                 ld      [%o1+4], %o0
F00F25BC: d027bfec                 st      %o0, [%fp+var_14]
F00F25C0: d0026008                 ld      [%o1+8], %o0
F00F25C4: d027bff0                 st      %o0, [%fp+var_10]
F00F25C8: d002600c                 ld      [%o1+0xC], %o0
F00F25CC: d027bff4                 st      %o0, [%fp+var_C]
F00F25D0: 7ffff8ba                 call    __objc_create_zone
F00F25D4: a007bfe8                 add     %fp, var_18, %l0
F00F25D8: 96100008                 mov     %o0, %o3
F00F25DC: 90100010                 mov     %l0, %o0! prototype
F00F25E0: 92102008                 mov     8, %o1
F00F25E4: 7fffeaf2                 call    _NXCreateHashTableFromZone
F00F25E8: 94102000                 mov     0, %o2
F00F25EC: 81c7e008                 ret
F00F25F0: 91e80008                 restore %g0, %o0, %o0
