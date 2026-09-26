F005E3C0: 9de3bf88                 save    %sp, -0x78, %sp
F005E3C4: d2062004                 ld      [%i0+4], %o1
F005E3C8: 80a26000                 cmp     %o1, 0
F005E3CC: 12800005                 bne     loc_F005E3E0
F005E3D0: d227bff4                 st      %o1, [%fp+var_C]
F005E3D4: c026a018                 clr     [%i2+0x18]
F005E3D8: 10800027                 ba      loc_F005E474
F005E3DC: c026a01c                 clr     [%i2+0x1C]
F005E3E0: d0060000                 ld      [%i0], %o0
F005E3E4: 80a20019                 cmp     %o0, %i1
F005E3E8: 02800012                 be      loc_F005E430
F005E3EC: 90100009                 mov     %o1, %o0
F005E3F0: a0062008                 add     %i0, 8, %l0
F005E3F4: 92100010                 mov     %l0, %o1
F005E3F8: d406200c                 ld      [%i0+0xC], %o2
F005E3FC: a2062010                 add     %i0, 0x10, %l1
F005E400: d8062014                 ld      [%i0+0x14], %o4
F005E404: 7fffffb1                 call    sub_F005E2C8
F005E408: 96100011                 mov     %l1, %o3
F005E40C: 90100019                 mov     %i1, %o0
F005E410: 9407bff4                 add     %fp, var_C, %o2
F005E414: 96100010                 mov     %l0, %o3
F005E418: 9806200c                 add     %i0, 0xC, %o4
F005E41C: d207bff4                 ld      [%fp+var_C], %o1
F005E420: 9a062014                 add     %i0, 0x14, %o5
F005E424: da23a05c                 st      %o5, [%sp+0x78+var_1C]
F005E428: 7fffff5f                 call    sub_F005E1A4
F005E42C: 9a100011                 mov     %l1, %o5
F005E430: d207bff4                 ld      [%fp+var_C], %o1
F005E434: d0026010                 ld      [%o1+0x10], %o0
F005E438: 80a64008                 cmp     %i1, %o0
F005E43C: 1a800007                 bcc     loc_F005E458
F005E440: d006200c                 ld      [%i0+0xC], %o0
F005E444: c0220000                 clr     [%o0]
F005E448: d2062014                 ld      [%i0+0x14], %o1
F005E44C: d007bff4                 ld      [%fp+var_C], %o0
F005E450: 10800005                 ba      loc_F005E464
F005E454: d0224000                 st      %o0, [%o1]
F005E458: d2220000                 st      %o1, [%o0]
F005E45C: d0062014                 ld      [%i0+0x14], %o0
F005E460: c0220000                 clr     [%o0]
F005E464: d0062008                 ld      [%i0+8], %o0
F005E468: d026a018                 st      %o0, [%i2+0x18]
F005E46C: d0062010                 ld      [%i0+0x10], %o0
F005E470: d026a01c                 st      %o0, [%i2+0x1C]
F005E474: f226a010                 st      %i1, [%i2+0x10]
F005E478: f4262004                 st      %i2, [%i0+4]
F005E47C: f2260000                 st      %i1, [%i0]
F005E480: 90062008                 add     %i0, 8, %o0
F005E484: d026200c                 st      %o0, [%i0+0xC]
F005E488: 90062010                 add     %i0, 0x10, %o0
F005E48C: d0262014                 st      %o0, [%i0+0x14]
F005E490: 81c7e008                 ret
F005E494: 81e80000                 restore
