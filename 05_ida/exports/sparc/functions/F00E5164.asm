F00E5164: 9de3bc18                 save    %sp, -0x3E8, %sp
F00E5168: aa102000                 mov     0, %l5
F00E516C: 90100019                 mov     %i1, %o0
F00E5170: 133c03f2921262d8         set     aReg, %o1! "reg"
F00E5178: 9407be18                 add     %fp, var_1E8, %o2
F00E517C: 193c04bb                 sethi   %hi(_sparcfbs), %o4
F00E5180: 972e2004                 sll     %i0, 4, %o3
F00E5184: 9602c018                 add     %o3, %i0, %o3
F00E5188: 972ae002                 sll     %o3, 2, %o3
F00E518C: d8032364                 ld      [%o4+%lo(_sparcfbs)], %o4
F00E5190: 9602e008                 inc     8, %o3
F00E5194: 7fff279c                 call    _prom_getprop
F00E5198: a403000b                 add     %o4, %o3, %l2
F00E519C: 7fff2cd1                 call    _prom_parentnode
F00E51A0: 90100019                 mov     %i1, %o0
F00E51A4: a0920000                 orcc    %o0, %g0, %l0
F00E51A8: 02800013                 be      loc_F00E51F4
F00E51AC: 133c03f2                 sethi   %hi(aRanges), %o1! "ranges"
F00E51B0: a21262f0                 or      %o1, %lo(aRanges), %l1! "ranges"
F00E51B4: 7fff278a                 call    _prom_getproplen
F00E51B8: 92100011                 mov     %l1, %o1
F00E51BC: 80a22000                 cmp     %o0, 0
F00E51C0: 02800010                 be      loc_F00E5200
F00E51C4: 90100010                 mov     %l0, %o0
F00E51C8: 92100011                 mov     %l1, %o1
F00E51CC: a007bc88                 add     %fp, var_378, %l0
F00E51D0: 7fff278d                 call    _prom_getprop
F00E51D4: 94100010                 mov     %l0, %o2
F00E51D8: d207be18                 ld      [%fp+var_1E8], %o1
F00E51DC: 912a6002                 sll     %o1, 2, %o0
F00E51E0: 90020009                 add     %o0, %o1, %o0
F00E51E4: 912a2002                 sll     %o0, 2, %o0
F00E51E8: a0040008                 add     %l0, %o0, %l0
F00E51EC: 10800005                 ba      loc_F00E5200
F00E51F0: ea04200c                 ld      [%l0+0xC], %l5
F00E51F4: 113c03f2                 sethi   %hi(aCanTGetParentN), %o0! "Can't get parent node\n"
F00E51F8: 7ffcbfde                 call    _panic
F00E51FC: 901222f8                 bset    %lo(aCanTGetParentN), %o0! "Can't get parent node\n"
F00E5200: 11000400                 sethi   0x100000, %o0
F00E5204: 293c0447                 sethi   %hi(_page_size), %l4
F00E5208: d205213c                 ld      [%l4+%lo(_page_size)], %o1
F00E520C: 7fff1740                 call    _map_alloc
F00E5210: b0102000                 mov     0, %i0
F00E5214: b4100008                 mov     %o0, %i2
F00E5218: a210001a                 mov     %i2, %l1
F00E521C: d407be1c                 ld      [%fp+var_1E4], %o2
F00E5220: 11000400                 sethi   0x100000, %o0
F00E5224: d205213c                 ld      [%l4+%lo(_page_size)], %o1
F00E5228: 7ffc84f6                 call    _udiv
F00E522C: a0028015                 add     %o2, %l5, %l0
F00E5230: a6100008                 mov     %o0, %l3
F00E5234: 80a60013                 cmp     %i0, %l3
F00E5238: 16800013                 bge     loc_F00E5284
F00E523C: 113c0447                 sethi   -0xFEEE400, %o0
F00E5240: 2f3c04f0                 sethi   -0xFEC4000, %l7
F00E5244: ac102001                 mov     1, %l6
F00E5248: ec23a05c                 st      %l6, [%sp+0x3E8+var_38C]
F00E524C: 92100011                 mov     %l1, %o1
F00E5250: 94100010                 mov     %l0, %o2
F00E5254: 96102000                 mov     0, %o3
F00E5258: 98102003                 mov     3, %o4
F00E525C: 9a102000                 mov     0, %o5
F00E5260: d005e100                 ld      [%l7+0x100], %o0
F00E5264: 7ffee335                 call    _pmap_enter_dev
F00E5268: b0062001                 inc     %i0
F00E526C: d005213c                 ld      [%l4+0x13C], %o0
F00E5270: 80a60013                 cmp     %i0, %l3
F00E5274: a2044008                 add     %l1, %o0, %l1
F00E5278: 06bffff4                 bl      loc_F00E5248
F00E527C: a0040008                 add     %l0, %o0, %l0
F00E5280: 113c0447                 sethi   -0xFEEE400, %o0
F00E5284: d202213c                 ld      [%o0+0x13C], %o1
F00E5288: 7fff1721                 call    _map_alloc
F00E528C: 11000008                 sethi   0x2000, %o0
F00E5290: a2100008                 mov     %o0, %l1
F00E5294: 92100011                 mov     %l1, %o1
F00E5298: 96102000                 mov     0, %o3
F00E529C: 98102003                 mov     3, %o4
F00E52A0: 9a102000                 mov     0, %o5
F00E52A4: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00E52A8: d407be7c                 ld      [%fp+var_184], %o2
F00E52AC: 84102001                 mov     1, %g2
F00E52B0: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00E52B4: c423a05c                 st      %g2, [%sp+0x3E8+var_38C]
F00E52B8: 7ffee320                 call    _pmap_enter_dev
F00E52BC: 94028015                 add     %o2, %l5, %o2
F00E52C0: 90102003                 mov     3, %o0
F00E52C4: d0248000                 st      %o0, [%l2]
F00E52C8: c024a004                 clr     [%l2+4]
F00E52CC: 90100019                 mov     %i1, %o0
F00E52D0: 133c03f2a01262e0         set     aWidth, %l0! "width"
F00E52D8: 7fff2741                 call    _prom_getproplen
F00E52DC: 92100010                 mov     %l0, %o1
F00E52E0: 80a22000                 cmp     %o0, 0
F00E52E4: 2280000e                 be,a    loc_F00E531C
F00E52E8: 90102001                 mov     1, %o0
F00E52EC: 0480000b                 ble     loc_F00E5318
F00E52F0: 80a22004                 cmp     %o0, 4
F00E52F4: 02800004                 be      loc_F00E5304
F00E52F8: 90100019                 mov     %i1, %o0
F00E52FC: 10800008                 ba      loc_F00E531C
F00E5300: 90102480                 mov     0x480, %o0
F00E5304: 92100010                 mov     %l0, %o1
F00E5308: 7fff273f                 call    _prom_getprop
F00E530C: 9407bc84                 add     %fp, var_37C, %o2
F00E5310: 10800003                 ba      loc_F00E531C
F00E5314: d007bc84                 ld      [%fp+var_37C], %o0
F00E5318: 90102480                 mov     0x480, %o0
F00E531C: d024a020                 st      %o0, [%l2+0x20]
F00E5320: 90100019                 mov     %i1, %o0
F00E5324: 133c03f2a01262e8         set     aHeight, %l0! "height"
F00E532C: 7fff272c                 call    _prom_getproplen
F00E5330: 92100010                 mov     %l0, %o1
F00E5334: 80a22000                 cmp     %o0, 0
F00E5338: 2280000e                 be,a    loc_F00E5370
F00E533C: 90102001                 mov     1, %o0
F00E5340: 0480000b                 ble     loc_F00E536C
F00E5344: 80a22004                 cmp     %o0, 4
F00E5348: 02800004                 be      loc_F00E5358
F00E534C: 90100019                 mov     %i1, %o0
F00E5350: 10800008                 ba      loc_F00E5370
F00E5354: 90102384                 mov     0x384, %o0
F00E5358: 92100010                 mov     %l0, %o1
F00E535C: 7fff272a                 call    _prom_getprop
F00E5360: 9407bc84                 add     %fp, var_37C, %o2
F00E5364: 10800003                 ba      loc_F00E5370
F00E5368: d007bc84                 ld      [%fp+var_37C], %o0
F00E536C: 90102384                 mov     0x384, %o0
F00E5370: d024a024                 st      %o0, [%l2+0x24]
F00E5374: f424a014                 st      %i2, [%l2+0x14]
F00E5378: c024a018                 clr     [%l2+0x18]
F00E537C: c024a008                 clr     [%l2+8]
F00E5380: e224a00c                 st      %l1, [%l2+0xC]
F00E5384: d004a020                 ld      [%l2+0x20], %o0
F00E5388: d204a024                 ld      [%l2+0x24], %o1
F00E538C: 7ffc845d                 call    _umul
F00E5390: 01000000                 nop
F00E5394: d024a01c                 st      %o0, [%l2+0x1C]
F00E5398: 90102008                 mov     8, %o0
F00E539C: d024a030                 st      %o0, [%l2+0x30]
F00E53A0: 90102001                 mov     1, %o0
F00E53A4: d024a034                 st      %o0, [%l2+0x34]
F00E53A8: d004a020                 ld      [%l2+0x20], %o0
F00E53AC: d204a034                 ld      [%l2+0x34], %o1
F00E53B0: 7ffc8454                 call    _umul
F00E53B4: 01000000                 nop
F00E53B8: d024a038                 st      %o0, [%l2+0x38]
F00E53BC: 81c7e008                 ret
F00E53C0: 91e82000                 restore %g0, 0, %o0
