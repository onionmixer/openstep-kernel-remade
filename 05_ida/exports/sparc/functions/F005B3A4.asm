F005B3A4: 9de3bf90                 save    %sp, -0x70, %sp
F005B3A8: 273c04ef                 sethi   %hi(_ipc_object_zones), %l3
F005B3AC: d004e300                 ld      [%l3+%lo(_ipc_object_zones)], %o0
F005B3B0: 40007747                 call    _zalloc
F005B3B4: a4100018                 mov     %i0, %l2
F005B3B8: a0920000                 orcc    %o0, %g0, %l0
F005B3BC: 12800004                 bne     loc_F005B3CC
F005B3C0: 113c04f0                 sethi   -0xFEC4000, %o0
F005B3C4: 10800051                 ba      locret_F005B508
F005B3C8: b0102006                 mov     6, %i0
F005B3CC: e8022028                 ld      [%o0+0x28], %l4
F005B3D0: d0050000                 ld      [%l4], %o0
F005B3D4: 40000e3d                 call    _ipc_table_alloc
F005B3D8: 912a2003                 sll     %o0, 3, %o0
F005B3DC: a2920000                 orcc    %o0, %g0, %l1
F005B3E0: 12800007                 bne     loc_F005B3FC
F005B3E4: 90100012                 mov     %l2, %o0
F005B3E8: d004e300                 ld      [%l3+0x300], %o0
F005B3EC: 40007779                 call    _zfree
F005B3F0: 92100010                 mov     %l0, %o1
F005B3F4: 10800045                 ba      locret_F005B508
F005B3F8: b0102006                 mov     6, %i0
F005B3FC: 9207bff4                 add     %fp, var_C, %o1
F005B400: 7fffe1ca                 call    _ipc_entry_alloc
F005B404: 9407bff0                 add     %fp, var_10, %o2
F005B408: b0920000                 orcc    %o0, %g0, %i0
F005B40C: 02800009                 be      loc_F005B430
F005B410: d004e300                 ld      [%l3+0x300], %o0
F005B414: 4000776f                 call    _zfree
F005B418: 92100010                 mov     %l0, %o1
F005B41C: d0050000                 ld      [%l4], %o0
F005B420: 92100011                 mov     %l1, %o1
F005B424: 40000e4b                 call    _ipc_table_free
F005B428: 912a2003                 sll     %o0, 3, %o0
F005B42C: 30800037                 ba,a    locret_F005B508
F005B430: 90102001                 mov     1, %o0
F005B434: d407bff0                 ld      [%fp+var_10], %o2
F005B438: 13001080                 sethi   0x420000, %o1
F005B43C: d022a008                 st      %o0, [%o2+8]
F005B440: d0028000                 ld      [%o2], %o0
F005B444: e022a004                 st      %l0, [%o2+4]
F005B448: 90120009                 bset    %o1, %o0
F005B44C: d0228000                 st      %o0, [%o2]
F005B450: c0240000                 clr     [%l0]
F005B454: d0040000                 ld      [%l0], %o0
F005B458: 80a22000                 cmp     %o0, 0
F005B45C: 12bffffe                 bne     loc_F005B454
F005B460: 01000000                 nop
F005B464: 4000ee91                 call    _simple_lock_try
F005B468: 90100010                 mov     %l0, %o0
F005B46C: 80a22000                 cmp     %o0, 0
F005B470: 02bffff9                 be      loc_F005B454
F005B474: 01000000                 nop
F005B478: c024a008                 clr     [%l2+8]
F005B47C: 90102001                 mov     1, %o0
F005B480: d0242004                 st      %o0, [%l0+4]
F005B484: 11200000                 sethi   0x80000000, %o0
F005B488: d0242008                 st      %o0, [%l0+8]
F005B48C: 90100010                 mov     %l0, %o0
F005B490: d407bff4                 ld      [%fp+var_C], %o2
F005B494: 7ffffd61                 call    _ipc_port_init
F005B498: 92100012                 mov     %l2, %o1
F005B49C: d8050000                 ld      [%l4], %o4
F005B4A0: 94102002                 mov     2, %o2
F005B4A4: 80a2800c                 cmp     %o2, %o4
F005B4A8: 1a80000b                 bcc     loc_F005B4D4
F005B4AC: 96102000                 mov     0, %o3
F005B4B0: 932aa003                 sll     %o2, 3, %o1
F005B4B4: 90044009                 add     %l1, %o1, %o0
F005B4B8: c0222004                 clr     [%o0+4]
F005B4BC: d6244009                 st      %o3, [%l1+%o1]
F005B4C0: 9610000a                 mov     %o2, %o3
F005B4C4: 9402e001                 add     %o3, 1, %o2
F005B4C8: 80a2800c                 cmp     %o2, %o4
F005B4CC: 0abffffa                 bcs     loc_F005B4B4
F005B4D0: 932aa003                 sll     %o2, 3, %o1
F005B4D4: d6244000                 st      %o3, [%l1]
F005B4D8: e8246004                 st      %l4, [%l1+4]
F005B4DC: e224202c                 st      %l1, [%l0+0x2C]
F005B4E0: 9014a001                 or      %l2, 1, %o0
F005B4E4: d0246008                 st      %o0, [%l1+8]
F005B4E8: d207bff4                 ld      [%fp+var_C], %o1
F005B4EC: 90100012                 mov     %l2, %o0
F005B4F0: 40000a46                 call    _ipc_space_reference
F005B4F4: d224600c                 st      %o1, [%l1+0xC]
F005B4F8: d007bff4                 ld      [%fp+var_C], %o0
F005B4FC: b0102000                 mov     0, %i0
F005B500: d0264000                 st      %o0, [%i1]
F005B504: e0268000                 st      %l0, [%i2]
F005B508: 81c7e008                 ret
F005B50C: 81e80000                 restore
