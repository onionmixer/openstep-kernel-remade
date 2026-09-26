F005F10C: 9de3bf70                 save    %sp, -0x90, %sp
F005F110: f227bfe4                 st      %i1, [%fp+var_1C]
F005F114: f427bfdc                 st      %i2, [%fp+var_24]
F005F118: f627bfd4                 st      %i3, [%fp+var_2C]
F005F11C: a6102000                 mov     0, %l3
F005F120: 80a62000                 cmp     %i0, 0
F005F124: 12800004                 bne     loc_F005F134
F005F128: ae102000                 mov     0, %l7
F005F12C: 1080014d                 ba      locret_F005F660
F005F130: b0102010                 mov     0x10, %i0
F005F134: c207bfdc                 ld      [%fp+var_24], %g1
F005F138: f4070000                 ld      [%i4], %i2
F005F13C: e8074000                 ld      [%i5], %l4
F005F140: a0062008                 add     %i0, 8, %l0
F005F144: f2004000                 ld      [%g1], %i1
F005F148: 233c04ef                 sethi   -0xFEC4400, %l1
F005F14C: c207bfd4                 ld      [%fp+var_2C], %g1
F005F150: 373c04d0                 sethi   -0xFECC000, %i3
F005F154: ec004000                 ld      [%g1], %l6
F005F158: d0040000                 ld      [%l0], %o0
F005F15C: 80a22000                 cmp     %o0, 0
F005F160: 12bffffe                 bne     loc_F005F158
F005F164: 01000000                 nop
F005F168: 4000df50                 call    _simple_lock_try
F005F16C: 90100010                 mov     %l0, %o0
F005F170: 80a22000                 cmp     %o0, 0
F005F174: 02bffff9                 be      loc_F005F158
F005F178: 01000000                 nop
F005F17C: d006200c                 ld      [%i0+0xC], %o0
F005F180: 80a22000                 cmp     %o0, 0
F005F184: 32800014                 bne,a   loc_F005F1D4
F005F188: ea062018                 ld      [%i0+0x18], %l5
F005F18C: c207bfdc                 ld      [%fp+var_24], %g1
F005F190: c0262008                 clr     [%i0+8]
F005F194: d0004000                 ld      [%g1], %o0
F005F198: 80a64008                 cmp     %i1, %o0
F005F19C: 02800005                 be      loc_F005F1B0
F005F1A0: d00462f8                 ld      [%l1+0x2F8], %o0
F005F1A4: d207bff4                 ld      [%fp+var_C], %o1
F005F1A8: 400091b7                 call    _kmem_free
F005F1AC: 94100013                 mov     %l3, %o2
F005F1B0: d0070000                 ld      [%i4], %o0
F005F1B4: 80a68008                 cmp     %i2, %o0
F005F1B8: 02bfffdd                 be      loc_F005F12C
F005F1BC: d00462f8                 ld      [%l1+0x2F8], %o0
F005F1C0: d207bff0                 ld      [%fp+var_10], %o1
F005F1C4: 400091b0                 call    _kmem_free
F005F1C8: 94100017                 mov     %l7, %o2
F005F1CC: 10800125                 ba      locret_F005F660
F005F1D0: b0102010                 mov     0x10, %i0
F005F1D4: 80a54016                 cmp     %l5, %l6
F005F1D8: 18800005                 bgu     loc_F005F1EC
F005F1DC: e4062038                 ld      [%i0+0x38], %l2
F005F1E0: 80a48014                 cmp     %l2, %l4
F005F1E4: 0880004e                 bleu    loc_F005F31C
F005F1E8: c207bfe4                 ld      [%fp+var_1C], %g1
F005F1EC: c0262008                 clr     [%i0+8]
F005F1F0: 80a54016                 cmp     %l5, %l6
F005F1F4: 08800021                 bleu    loc_F005F278
F005F1F8: c207bfdc                 ld      [%fp+var_24], %g1
F005F1FC: d0004000                 ld      [%g1], %o0
F005F200: 80a64008                 cmp     %i1, %o0
F005F204: 02800005                 be      loc_F005F218
F005F208: d00462f8                 ld      [%l1+0x2F8], %o0
F005F20C: d207bff4                 ld      [%fp+var_C], %o1
F005F210: 4000919d                 call    _kmem_free
F005F214: 94100013                 mov     %l3, %o2
F005F218: 9207bff4                 add     %fp, var_C, %o1
F005F21C: 952d6003                 sll     %l5, 3, %o2
F005F220: 94028015                 add     %o2, %l5, %o2
F005F224: d606e0d8                 ld      [%i3+0xD8], %o3
F005F228: 952aa002                 sll     %o2, 2, %o2
F005F22C: d00462f8                 ld      [%l1+0x2F8], %o0
F005F230: 9402800b                 add     %o2, %o3, %o2
F005F234: a62a800b                 andn    %o2, %o3, %l3
F005F238: 40009118                 call    _kmem_alloc
F005F23C: 94100013                 mov     %l3, %o2
F005F240: 80a22000                 cmp     %o0, 0
F005F244: 02800009                 be      loc_F005F268
F005F248: f207bff4                 ld      [%fp+var_C], %i1
F005F24C: d0070000                 ld      [%i4], %o0
F005F250: 80a68008                 cmp     %i2, %o0
F005F254: 0280002a                 be      loc_F005F2FC
F005F258: d00462f8                 ld      [%l1+0x2F8], %o0
F005F25C: d207bff0                 ld      [%fp+var_10], %o1
F005F260: 10800025                 ba      loc_F005F2F4
F005F264: 94100017                 mov     %l7, %o2
F005F268: 90100013                 mov     %l3, %o0
F005F26C: 7ffe9ce5                 call    _udiv
F005F270: 92102024                 mov     0x24, %o1 ! '$'
F005F274: ac100008                 mov     %o0, %l6
F005F278: 80a48014                 cmp     %l2, %l4
F005F27C: 08bfffb7                 bleu    loc_F005F158
F005F280: 01000000                 nop
F005F284: d0070000                 ld      [%i4], %o0
F005F288: 80a68008                 cmp     %i2, %o0
F005F28C: 02800005                 be      loc_F005F2A0
F005F290: d00462f8                 ld      [%l1+0x2F8], %o0
F005F294: d207bff0                 ld      [%fp+var_10], %o1
F005F298: 4000917b                 call    _kmem_free
F005F29C: 94100017                 mov     %l7, %o2
F005F2A0: 9207bff0                 add     %fp, var_10, %o1
F005F2A4: 952ca001                 sll     %l2, 1, %o2
F005F2A8: 94028012                 add     %o2, %l2, %o2
F005F2AC: 952aa002                 sll     %o2, 2, %o2
F005F2B0: 94228012                 sub     %o2, %l2, %o2
F005F2B4: d606e0d8                 ld      [%i3+0xD8], %o3
F005F2B8: 952aa002                 sll     %o2, 2, %o2
F005F2BC: d00462f8                 ld      [%l1+0x2F8], %o0
F005F2C0: 9402800b                 add     %o2, %o3, %o2
F005F2C4: ae2a800b                 andn    %o2, %o3, %l7
F005F2C8: 400090f4                 call    _kmem_alloc
F005F2CC: 94100017                 mov     %l7, %o2
F005F2D0: 80a22000                 cmp     %o0, 0
F005F2D4: 0280000c                 be      loc_F005F304
F005F2D8: c207bfdc                 ld      [%fp+var_24], %g1
F005F2DC: d0004000                 ld      [%g1], %o0
F005F2E0: 80a64008                 cmp     %i1, %o0
F005F2E4: 02800006                 be      loc_F005F2FC
F005F2E8: d00462f8                 ld      [%l1+0x2F8], %o0
F005F2EC: d207bff4                 ld      [%fp+var_C], %o1
F005F2F0: 94100013                 mov     %l3, %o2
F005F2F4: 40009164                 call    _kmem_free
F005F2F8: 01000000                 nop
F005F2FC: 108000d9                 ba      locret_F005F660
F005F300: b0102006                 mov     6, %i0
F005F304: f407bff0                 ld      [%fp+var_10], %i2
F005F308: 90100017                 mov     %l7, %o0
F005F30C: 7ffe9cbd                 call    _udiv
F005F310: 9210202c                 mov     0x2C, %o1 ! ','
F005F314: 10bfff91                 ba      loc_F005F158
F005F318: a8100008                 mov     %o0, %l4
F005F31C: 901020ff                 mov     0xFF, %o0
F005F320: d0204000                 st      %o0, [%g1]
F005F324: d0062018                 ld      [%i0+0x18], %o0
F005F328: d0206004                 st      %o0, [%g1+4]
F005F32C: d006201c                 ld      [%i0+0x1C], %o0
F005F330: d0020000                 ld      [%o0], %o0
F005F334: d0206008                 st      %o0, [%g1+8]
F005F338: d0062038                 ld      [%i0+0x38], %o0
F005F33C: d020600c                 st      %o0, [%g1+0xC]
F005F340: d006203c                 ld      [%i0+0x3C], %o0
F005F344: d0206010                 st      %o0, [%g1+0x10]
F005F348: d0062040                 ld      [%i0+0x40], %o0
F005F34C: d0206014                 st      %o0, [%g1+0x14]
F005F350: c4062018                 ld      [%i0+0x18], %g2
F005F354: 9a102000                 mov     0, %o5
F005F358: 80a34002                 cmp     %o5, %g2
F005F35C: 1a800026                 bcc     loc_F005F3F4
F005F360: d4062014                 ld      [%i0+0x14], %o2
F005F364: 213fc000                 sethi   -0x1000000, %l0
F005F368: 1f0007c0                 sethi   0x1F0000, %o7
F005F36C: 1100003f861223ff         set     0xFFFF, %g3
F005F374: 96100019                 mov     %i1, %o3
F005F378: 9810000a                 mov     %o2, %o4
F005F37C: d4030000                 ld      [%o4], %o2
F005F380: 932b6008                 sll     %o5, 8, %o1
F005F384: 900a8010                 and     %o2, %l0, %o0
F005F388: 91322018                 srl     %o0, 24, %o0
F005F38C: 92124008                 bset    %o0, %o1
F005F390: d222c000                 st      %o1, [%o3]
F005F394: 9132a017                 srl     %o2, 23, %o0
F005F398: 900a2001                 and     %o0, 1, %o0
F005F39C: d022e004                 st      %o0, [%o3+4]
F005F3A0: 9132a016                 srl     %o2, 22, %o0
F005F3A4: 900a2001                 and     %o0, 1, %o0
F005F3A8: d022e008                 st      %o0, [%o3+8]
F005F3AC: 9132a015                 srl     %o2, 21, %o0
F005F3B0: 900a2001                 and     %o0, 1, %o0
F005F3B4: d022e00c                 st      %o0, [%o3+0xC]
F005F3B8: 900a800f                 and     %o2, %o7, %o0
F005F3BC: d022e010                 st      %o0, [%o3+0x10]
F005F3C0: 940a8003                 and     %o2, %g3, %o2
F005F3C4: d422e014                 st      %o2, [%o3+0x14]
F005F3C8: d0032004                 ld      [%o4+4], %o0
F005F3CC: d022e018                 st      %o0, [%o3+0x18]
F005F3D0: d0032008                 ld      [%o4+8], %o0
F005F3D4: 9a036001                 inc     %o5
F005F3D8: d022e01c                 st      %o0, [%o3+0x1C]
F005F3DC: d003200c                 ld      [%o4+0xC], %o0
F005F3E0: 80a34002                 cmp     %o5, %g2
F005F3E4: d022e020                 st      %o0, [%o3+0x20]
F005F3E8: 9602e024                 inc     0x24, %o3 ! '$'
F005F3EC: 0abfffe4                 bcs     loc_F005F37C
F005F3F0: 98032010                 inc     0x10, %o4
F005F3F4: 7ffffd37                 call    _ipc_splay_traverse_start
F005F3F8: 90062020                 add     %i0, 0x20, %o0 ! ' '
F005F3FC: 96920000                 orcc    %o0, %g0, %o3
F005F400: 02800034                 be      loc_F005F4D0
F005F404: 1100003f                 sethi   0xFC00, %o0
F005F408: 2d0007c0                 sethi   0x1F0000, %l6
F005F40C: a81223ff                 or      %o0, 0x3FF, %l4
F005F410: a010001a                 mov     %i2, %l0
F005F414: a2102000                 mov     0, %l1
F005F418: d402c000                 ld      [%o3], %o2
F005F41C: d202e010                 ld      [%o3+0x10], %o1
F005F420: 90100011                 mov     %l1, %o0
F005F424: d2268008                 st      %o1, [%i2+%o0]
F005F428: 92100010                 mov     %l0, %o1
F005F42C: 9132a017                 srl     %o2, 23, %o0
F005F430: 900a2001                 and     %o0, 1, %o0
F005F434: d0226004                 st      %o0, [%o1+4]
F005F438: 9132a016                 srl     %o2, 22, %o0
F005F43C: 900a2001                 and     %o0, 1, %o0
F005F440: d0226008                 st      %o0, [%o1+8]
F005F444: 9132a015                 srl     %o2, 21, %o0
F005F448: 900a2001                 and     %o0, 1, %o0
F005F44C: d022600c                 st      %o0, [%o1+0xC]
F005F450: 900a8016                 and     %o2, %l6, %o0
F005F454: d0226010                 st      %o0, [%o1+0x10]
F005F458: 940a8014                 and     %o2, %l4, %o2
F005F45C: d4226014                 st      %o2, [%o1+0x14]
F005F460: d002e004                 ld      [%o3+4], %o0
F005F464: d0226018                 st      %o0, [%o1+0x18]
F005F468: d002e008                 ld      [%o3+8], %o0
F005F46C: d022601c                 st      %o0, [%o1+0x1C]
F005F470: d002e00c                 ld      [%o3+0xC], %o0
F005F474: a204602c                 inc     0x2C, %l1 ! ','
F005F478: d0226020                 st      %o0, [%o1+0x20]
F005F47C: d002e018                 ld      [%o3+0x18], %o0
F005F480: 80a22000                 cmp     %o0, 0
F005F484: 12800004                 bne     loc_F005F494
F005F488: a002602c                 add     %o1, 0x2C, %l0 ! ','
F005F48C: 10800004                 ba      loc_F005F49C
F005F490: c0226024                 clr     [%o1+0x24]
F005F494: d0022010                 ld      [%o0+0x10], %o0
F005F498: d0226024                 st      %o0, [%o1+0x24]
F005F49C: d002e01c                 ld      [%o3+0x1C], %o0
F005F4A0: 80a22000                 cmp     %o0, 0
F005F4A4: 32800004                 bne,a   loc_F005F4B4
F005F4A8: d0022010                 ld      [%o0+0x10], %o0
F005F4AC: 10800003                 ba      loc_F005F4B8
F005F4B0: c0226028                 clr     [%o1+0x28]
F005F4B4: d0226028                 st      %o0, [%o1+0x28]
F005F4B8: 90062020                 add     %i0, 0x20, %o0 ! ' '
F005F4BC: 7ffffd20                 call    _ipc_splay_traverse_next
F005F4C0: 92102000                 mov     0, %o1
F005F4C4: 96920000                 orcc    %o0, %g0, %o3
F005F4C8: 32bfffd5                 bne,a   loc_F005F41C
F005F4CC: d402c000                 ld      [%o3], %o2
F005F4D0: 7ffffd99                 call    _ipc_splay_traverse_finish
F005F4D4: 90062020                 add     %i0, 0x20, %o0 ! ' '
F005F4D8: c207bfdc                 ld      [%fp+var_24], %g1
F005F4DC: c0262008                 clr     [%i0+8]
F005F4E0: d0004000                 ld      [%g1], %o0
F005F4E4: 80a64008                 cmp     %i1, %o0
F005F4E8: 0280002c                 be      loc_F005F598
F005F4EC: 80a56000                 cmp     %l5, 0
F005F4F0: 1280000a                 bne     loc_F005F518
F005F4F4: 912d6003                 sll     %l5, 3, %o0
F005F4F8: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F4FC: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F500: d207bff4                 ld      [%fp+var_C], %o1
F005F504: 400090e0                 call    _kmem_free
F005F508: 94100013                 mov     %l3, %o2
F005F50C: c207bfd4                 ld      [%fp+var_2C], %g1
F005F510: 10800024                 ba      loc_F005F5A0
F005F514: c0204000                 clr     [%g1]
F005F518: 90020015                 add     %o0, %l5, %o0
F005F51C: 133c04d0                 sethi   %hi(_page_mask), %o1
F005F520: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F005F524: b32a2002                 sll     %o0, 2, %i1
F005F528: 90064009                 add     %i1, %o1, %o0
F005F52C: b02a0009                 andn    %o0, %o1, %i0
F005F530: 80a60013                 cmp     %i0, %l3
F005F534: 02800007                 be      loc_F005F550
F005F538: 9424c018                 sub     %l3, %i0, %o2
F005F53C: d207bff4                 ld      [%fp+var_C], %o1
F005F540: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F544: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F548: 400090cf                 call    _kmem_free
F005F54C: 92024018                 add     %o1, %i0, %o1
F005F550: 80a64018                 cmp     %i1, %i0
F005F554: 02800005                 be      loc_F005F568
F005F558: d007bff4                 ld      [%fp+var_C], %o0! void *
F005F55C: 92260019                 sub     %i0, %i1, %o1! size_t
F005F560: 4000d63e                 call    _bzero
F005F564: 90020019                 add     %o0, %i1, %o0
F005F568: 96100018                 mov     %i0, %o3
F005F56C: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F570: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F574: 98102001                 mov     1, %o4
F005F578: d207bff4                 ld      [%fp+var_C], %o1
F005F57C: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F005F580: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F005F584: 40009b3d                 call    _vm_move
F005F588: 9a07bfec                 add     %fp, var_14, %o5
F005F58C: d007bfec                 ld      [%fp+var_14], %o0
F005F590: c207bfdc                 ld      [%fp+var_24], %g1
F005F594: d0204000                 st      %o0, [%g1]
F005F598: c207bfd4                 ld      [%fp+var_2C], %g1
F005F59C: ea204000                 st      %l5, [%g1]
F005F5A0: d0070000                 ld      [%i4], %o0
F005F5A4: 80a68008                 cmp     %i2, %o0
F005F5A8: 0280002c                 be      loc_F005F658
F005F5AC: 80a4a000                 cmp     %l2, 0
F005F5B0: 12800009                 bne     loc_F005F5D4
F005F5B4: 912ca001                 sll     %l2, 1, %o0
F005F5B8: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F5BC: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F5C0: d207bff0                 ld      [%fp+var_10], %o1
F005F5C4: 400090b0                 call    _kmem_free
F005F5C8: 94100017                 mov     %l7, %o2
F005F5CC: 10800024                 ba      loc_F005F65C
F005F5D0: c0274000                 clr     [%i5]
F005F5D4: 90020012                 add     %o0, %l2, %o0
F005F5D8: 912a2002                 sll     %o0, 2, %o0
F005F5DC: 90220012                 sub     %o0, %l2, %o0
F005F5E0: 133c04d0                 sethi   %hi(_page_mask), %o1
F005F5E4: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F005F5E8: b32a2002                 sll     %o0, 2, %i1
F005F5EC: 90064009                 add     %i1, %o1, %o0
F005F5F0: b02a0009                 andn    %o0, %o1, %i0
F005F5F4: 80a60017                 cmp     %i0, %l7
F005F5F8: 02800007                 be      loc_F005F614
F005F5FC: 9425c018                 sub     %l7, %i0, %o2
F005F600: d207bff0                 ld      [%fp+var_10], %o1
F005F604: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F608: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F60C: 4000909e                 call    _kmem_free
F005F610: 92024018                 add     %o1, %i0, %o1
F005F614: 80a64018                 cmp     %i1, %i0
F005F618: 02800005                 be      loc_F005F62C
F005F61C: d007bff0                 ld      [%fp+var_10], %o0! void *
F005F620: 92260019                 sub     %i0, %i1, %o1! size_t
F005F624: 4000d60d                 call    _bzero
F005F628: 90020019                 add     %o0, %i1, %o0
F005F62C: 96100018                 mov     %i0, %o3
F005F630: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F634: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F638: 98102001                 mov     1, %o4
F005F63C: d207bff0                 ld      [%fp+var_10], %o1
F005F640: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F005F644: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F005F648: 40009b0c                 call    _vm_move
F005F64C: 9a07bfe8                 add     %fp, var_18, %o5
F005F650: d007bfe8                 ld      [%fp+var_18], %o0
F005F654: d0270000                 st      %o0, [%i4]
F005F658: e4274000                 st      %l2, [%i5]
F005F65C: b0102000                 mov     0, %i0
F005F660: 81c7e008                 ret
F005F664: 81e80000                 restore
