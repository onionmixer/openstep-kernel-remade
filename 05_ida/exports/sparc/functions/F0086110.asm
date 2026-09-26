F0086110: 9de3bf90                 save    %sp, -0x70, %sp
F0086114: e607a05c                 ld      [%fp+arg_5C], %l3
F0086118: e207a060                 ld      [%fp+arg_60], %l1
F008611C: 80a62000                 cmp     %i0, 0
F0086120: 12800004                 bne     loc_F0086130
F0086124: e407a064                 ld      [%fp+arg_64], %l2
F0086128: 10800052                 ba      locret_F0086270
F008612C: b0102004                 mov     4, %i0
F0086130: e0064000                 ld      [%i1], %l0
F0086134: 7fff8bf0                 call    _lock_read
F0086138: 90100018                 mov     %i0, %o0
F008613C: 90100018                 mov     %i0, %o0
F0086140: 92100010                 mov     %l0, %o1
F0086144: 7ffff8d9                 call    _vm_map_lookup_entry
F0086148: 9407bff4                 add     %fp, var_C, %o2
F008614C: 80a22000                 cmp     %o0, 0
F0086150: 1280000c                 bne     loc_F0086180
F0086154: d207bff4                 ld      [%fp+var_C], %o1
F0086158: d007bff4                 ld      [%fp+var_C], %o0
F008615C: d2022004                 ld      [%o0+4], %o1
F0086160: 9006200c                 add     %i0, 0xC, %o0
F0086164: 80a24008                 cmp     %o1, %o0
F0086168: 32800007                 bne,a   loc_F0086184
F008616C: d002601c                 ld      [%o1+0x1C], %o0
F0086170: 7fff8bb1                 call    _lock_done
F0086174: 90100018                 mov     %i0, %o0
F0086178: 1080003e                 ba      locret_F0086270
F008617C: b0102003                 mov     3, %i0
F0086180: d002601c                 ld      [%o1+0x1C], %o0
F0086184: e0026008                 ld      [%o1+8], %l0
F0086188: d026c000                 st      %o0, [%i3]
F008618C: d0026020                 ld      [%o1+0x20], %o0
F0086190: d0270000                 st      %o0, [%i4]
F0086194: d0026024                 ld      [%o1+0x24], %o0
F0086198: d0274000                 st      %o0, [%i5]
F008619C: e0264000                 st      %l0, [%i1]
F00861A0: d002600c                 ld      [%o1+0xC], %o0
F00861A4: 90220010                 sub     %o0, %l0, %o0
F00861A8: d0268000                 st      %o0, [%i2]
F00861AC: d4026018                 ld      [%o1+0x18], %o2
F00861B0: 80a2a000                 cmp     %o2, 0
F00861B4: 16800022                 bge     loc_F008623C
F00861B8: f2026014                 ld      [%o1+0x14], %i1
F00861BC: e0026010                 ld      [%o1+0x10], %l0
F00861C0: 7fff8bcd                 call    _lock_read
F00861C4: 90100010                 mov     %l0, %o0
F00861C8: 90100010                 mov     %l0, %o0
F00861CC: 92100019                 mov     %i1, %o1
F00861D0: 7ffff8b6                 call    _vm_map_lookup_entry
F00861D4: 9407bff4                 add     %fp, var_C, %o2
F00861D8: d007bff4                 ld      [%fp+var_C], %o0
F00861DC: d002200c                 ld      [%o0+0xC], %o0
F00861E0: d2068000                 ld      [%i2], %o1
F00861E4: 90220019                 sub     %o0, %i1, %o0
F00861E8: 80a20009                 cmp     %o0, %o1
F00861EC: 2a800002                 bcs,a   loc_F00861F4
F00861F0: d0268000                 st      %o0, [%i2]
F00861F4: d007bff4                 ld      [%fp+var_C], %o0
F00861F8: 40000647                 call    _vm_object_name
F00861FC: d0022010                 ld      [%o0+0x10], %o0
F0086200: d0244000                 st      %o0, [%l1]
F0086204: d207bff4                 ld      [%fp+var_C], %o1
F0086208: d0026008                 ld      [%o1+8], %o0
F008620C: d2026014                 ld      [%o1+0x14], %o1
F0086210: 90264008                 sub     %i1, %o0, %o0
F0086214: 92024008                 add     %o1, %o0, %o1
F0086218: d2248000                 st      %o1, [%l2]
F008621C: d2042030                 ld      [%l0+0x30], %o1
F0086220: 90100010                 mov     %l0, %o0
F0086224: 921a6001                 btog    1, %o1
F0086228: 80a00009                 cmp     %g0, %o1
F008622C: 92402000                 addc    %g0, 0, %o1
F0086230: 7fff8b81                 call    _lock_done
F0086234: d224c000                 st      %o1, [%l3]
F0086238: 3080000b                 ba,a    loc_F0086264
F008623C: 11080000                 sethi   0x20000000, %o0
F0086240: 808a8008                 btst    %o0, %o2
F0086244: 02800004                 be      loc_F0086254
F0086248: c024c000                 clr     [%l3]
F008624C: 10800005                 ba      loc_F0086260
F0086250: c0244000                 clr     [%l1]
F0086254: 40000630                 call    _vm_object_name
F0086258: d0026010                 ld      [%o1+0x10], %o0
F008625C: d0244000                 st      %o0, [%l1]
F0086260: f2248000                 st      %i1, [%l2]
F0086264: 7fff8b74                 call    _lock_done
F0086268: 90100018                 mov     %i0, %o0
F008626C: b0102000                 mov     0, %i0
F0086270: 81c7e008                 ret
F0086274: 81e80000                 restore
