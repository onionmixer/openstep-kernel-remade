F009E454: 9de3bf90                 save    %sp, -0x70, %sp
F009E458: e407a05c                 ld      [%fp+arg_5C], %l2
F009E45C: b806401c                 add     %i1, %i4, %i4
F009E460: 80a6401c                 cmp     %i1, %i4
F009E464: 1a800010                 bcc     locret_F009E4A4
F009E468: e207a060                 ld      [%fp+arg_60], %l1
F009E46C: 213c0447                 sethi   -0xFEEE400, %l0
F009E470: e223a05c                 st      %l1, [%sp+0x70+var_14]
F009E474: 90100018                 mov     %i0, %o0
F009E478: 92100019                 mov     %i1, %o1
F009E47C: 9410001a                 mov     %i2, %o2
F009E480: 9610001b                 mov     %i3, %o3
F009E484: 9810001d                 mov     %i5, %o4
F009E488: 7ffffeac                 call    _pmap_enter_dev
F009E48C: 9a100012                 mov     %l2, %o5
F009E490: d004213c                 ld      [%l0+0x13C], %o0
F009E494: b2064008                 add     %i1, %o0, %i1
F009E498: 80a6401c                 cmp     %i1, %i4
F009E49C: 0abffff5                 bcs     loc_F009E470
F009E4A0: b4068008                 add     %i2, %o0, %i2
F009E4A4: 81c7e008                 ret
F009E4A8: 81e80000                 restore
