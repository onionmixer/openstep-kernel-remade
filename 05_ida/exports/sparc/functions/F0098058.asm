F0098058: 9de3bf90                 save    %sp, -0x70, %sp
F009805C: f027a044                 st      %i0, [%fp+arg_44]
F0098060: f227a048                 st      %i1, [%fp+arg_48]
F0098064: f427a04c                 st      %i2, [%fp+arg_4C]
F0098068: 7ffffb3b                 call    _setjmp
F009806C: 9007bff0                 add     %fp, var_10, %o0
F0098070: 80a22000                 cmp     %o0, 0
F0098074: 1280000d                 bne     locret_F00980A8
F0098078: b010200e                 mov     0xE, %i0
F009807C: d007a044                 ld      [%fp+arg_44], %o0! void *
F0098080: 213c04d0                 sethi   %hi(_active_threads), %l0
F0098084: d8042260                 ld      [%l0+%lo(_active_threads)], %o4
F0098088: d207a048                 ld      [%fp+arg_48], %o1! void *
F009808C: 9607bff0                 add     %fp, var_10, %o3
F0098090: d407a04c                 ld      [%fp+arg_4C], %o2! size_t
F0098094: 7ffff29f                 call    _bcopy
F0098098: d6232074                 st      %o3, [%o4+0x74]
F009809C: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F00980A0: b0102000                 mov     0, %i0
F00980A4: c0222074                 clr     [%o0+0x74]
F00980A8: 81c7e008                 ret
F00980AC: 81e80000                 restore
