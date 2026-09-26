F00980CC: 9de3bf90                 save    %sp, -0x70, %sp
F00980D0: f027a044                 st      %i0, [%fp+arg_44]
F00980D4: f227a048                 st      %i1, [%fp+arg_48]
F00980D8: f427a04c                 st      %i2, [%fp+arg_4C]
F00980DC: 7ffffb1e                 call    _setjmp
F00980E0: 9007bff0                 add     %fp, var_10, %o0
F00980E4: 80a22000                 cmp     %o0, 0
F00980E8: 1280000d                 bne     locret_F009811C
F00980EC: b010200e                 mov     0xE, %i0
F00980F0: d007a044                 ld      [%fp+arg_44], %o0! void *
F00980F4: 213c04d0                 sethi   %hi(_active_threads), %l0
F00980F8: d8042260                 ld      [%l0+%lo(_active_threads)], %o4
F00980FC: d207a048                 ld      [%fp+arg_48], %o1! void *
F0098100: 9607bff0                 add     %fp, var_10, %o3
F0098104: d407a04c                 ld      [%fp+arg_4C], %o2! size_t
F0098108: 7ffff282                 call    _bcopy
F009810C: d6232074                 st      %o3, [%o4+0x74]
F0098110: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F0098114: b0102000                 mov     0, %i0
F0098118: c0222074                 clr     [%o0+0x74]
F009811C: 81c7e008                 ret
F0098120: 81e80000                 restore
