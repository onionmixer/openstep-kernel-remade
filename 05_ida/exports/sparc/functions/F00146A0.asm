F00146A0: 9de3bf98                 save    %sp, -0x68, %sp
F00146A4: f227a048                 st      %i1, [%fp+arg_48]
F00146A8: f427a04c                 st      %i2, [%fp+arg_4C]
F00146AC: f627a050                 st      %i3, [%fp+arg_50]
F00146B0: 113c04cf                 sethi   %hi(_active_u), %o0
F00146B4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00146B8: f827a054                 st      %i4, [%fp+arg_54]
F00146BC: f2022164                 ld      [%o0+0x164], %i1
F00146C0: 80a66000                 cmp     %i1, 0
F00146C4: 0280000b                 be      locret_F00146F0
F00146C8: fa27a058                 st      %i5, [%fp+arg_58]
F00146CC: 90100019                 mov     %i1, %o0
F00146D0: 400014d0                 call    _ttycheckoutq
F00146D4: 92102001                 mov     1, %o1
F00146D8: 90100018                 mov     %i0, %o0
F00146DC: 9207a048                 add     %fp, arg_48, %o1
F00146E0: 94102002                 mov     2, %o2
F00146E4: 4000007a                 call    _prf
F00146E8: 96100019                 mov     %i1, %o3
F00146EC: b0102000                 mov     0, %i0
F00146F0: 81c7e008                 ret
F00146F4: 81e80000                 restore
