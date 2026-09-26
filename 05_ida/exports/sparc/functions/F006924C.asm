F006924C: 9de3bf98                 save    %sp, -0x68, %sp
F0069250: a0100018                 mov     %i0, %l0
F0069254: b0042008                 add     %l0, 8, %i0
F0069258: d0060000                 ld      [%i0], %o0
F006925C: 80a22000                 cmp     %o0, 0
F0069260: 12bffffe                 bne     loc_F0069258
F0069264: 01000000                 nop
F0069268: 4000b710                 call    _simple_lock_try
F006926C: 90100018                 mov     %i0, %o0
F0069270: 80a22000                 cmp     %o0, 0
F0069274: 02bffff9                 be      loc_F0069258
F0069278: 01000000                 nop
F006927C: d0142004                 lduh    [%l0+4], %o0
F0069280: d2040000                 ld      [%l0], %o1
F0069284: 90023fff                 inc     -1, %o0
F0069288: d0342004                 sth     %o0, [%l0+4]
F006928C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0069290: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0069294: 80a24008                 cmp     %o1, %o0
F0069298: 3280000c                 bne,a   loc_F00692C8
F006929C: d4042004                 ld      [%l0+4], %o2
F00692A0: c0242008                 clr     [%l0+8]
F00692A4: d0042004                 ld      [%l0+4], %o0
F00692A8: b0102000                 mov     0, %i0
F00692AC: 920a3000                 and     %o0, -0x1000, %o1
F00692B0: 900a2fff                 and     %o0, 0xFFF, %o0
F00692B4: 90022001                 inc     %o0
F00692B8: 900a2fff                 and     %o0, 0xFFF, %o0
F00692BC: 92124008                 bset    %o0, %o1
F00692C0: 10800053                 ba      locret_F006940C
F00692C4: d2242004                 st      %o1, [%l0+4]
F00692C8: 11000020                 sethi   0x8000, %o0
F00692CC: 808a8008                 btst    %o0, %o2
F00692D0: 02800010                 be      loc_F0069310
F00692D4: 13000008                 sethi   0x2000, %o1
F00692D8: 113fffc8                 sethi   -0xE000, %o0
F00692DC: 900a8008                 and     %o2, %o0, %o0
F00692E0: 80a20009                 cmp     %o0, %o1
F00692E4: 12800008                 bne     loc_F0069304
F00692E8: 11000008                 sethi   0x2000, %o0
F00692EC: 902a8008                 andn    %o2, %o0, %o0
F00692F0: d0242004                 st      %o0, [%l0+4]
F00692F4: 90100010                 mov     %l0, %o0
F00692F8: 92102000                 mov     0, %o1
F00692FC: 40001f40                 call    _thread_wakeup_prim
F0069300: 94102000                 mov     0, %o2
F0069304: c0242008                 clr     [%l0+8]
F0069308: 10800041                 ba      locret_F006940C
F006930C: b0102001                 mov     1, %i0
F0069310: 90128008                 bset    %o2, %o0
F0069314: d0242004                 st      %o0, [%l0+4]
F0069318: d0142004                 lduh    [%l0+4], %o0
F006931C: 80a22000                 cmp     %o0, 0
F0069320: 02800039                 be      loc_F0069404
F0069324: 113c043e                 sethi   -0xFEF0800, %o0
F0069328: a2042008                 add     %l0, 8, %l1
F006932C: d0022380                 ld      [%o0+0x380], %o0
F0069330: 80a22000                 cmp     %o0, 0
F0069334: 24800019                 ble,a   loc_F0069398
F0069338: d2042004                 ld      [%l0+4], %o1
F006933C: c0242008                 clr     [%l0+8]
F0069340: 90023fff                 inc     -1, %o0
F0069344: 80a22000                 cmp     %o0, 0
F0069348: 0480000a                 ble     loc_F0069370
F006934C: b0042008                 add     %l0, 8, %i0
F0069350: d2142004                 lduh    [%l0+4], %o1
F0069354: 80a26000                 cmp     %o1, 0
F0069358: 02800005                 be      loc_F006936C
F006935C: 90023fff                 inc     -1, %o0
F0069360: 80a22000                 cmp     %o0, 0
F0069364: 14bffffd                 bg      loc_F0069358
F0069368: 80a26000                 cmp     %o1, 0
F006936C: b0042008                 add     %l0, 8, %i0
F0069370: d0060000                 ld      [%i0], %o0
F0069374: 80a22000                 cmp     %o0, 0
F0069378: 12bffffe                 bne     loc_F0069370
F006937C: 01000000                 nop
F0069380: 4000b6ca                 call    _simple_lock_try
F0069384: 90100018                 mov     %i0, %o0
F0069388: 80a22000                 cmp     %o0, 0
F006938C: 02bffff9                 be      loc_F0069370
F0069390: 01000000                 nop
F0069394: d2042004                 ld      [%l0+4], %o1
F0069398: 11000004                 sethi   0x1000, %o0
F006939C: 808a4008                 btst    %o0, %o1
F00693A0: 02800016                 be      loc_F00693F8
F00693A4: d0142004                 lduh    [%l0+4], %o0
F00693A8: 80a22000                 cmp     %o0, 0
F00693AC: 02800014                 be      loc_F00693FC
F00693B0: 11000008                 sethi   0x2000, %o0
F00693B4: 90124008                 bset    %o1, %o0
F00693B8: d0242004                 st      %o0, [%l0+4]
F00693BC: 90100010                 mov     %l0, %o0
F00693C0: 92100011                 mov     %l1, %o1
F00693C4: 40001f7e                 call    _thread_sleep
F00693C8: 94102000                 mov     0, %o2
F00693CC: b0100011                 mov     %l1, %i0
F00693D0: d0060000                 ld      [%i0], %o0
F00693D4: 80a22000                 cmp     %o0, 0
F00693D8: 12bffffe                 bne     loc_F00693D0
F00693DC: 01000000                 nop
F00693E0: 4000b6b2                 call    _simple_lock_try
F00693E4: 90100018                 mov     %i0, %o0
F00693E8: 80a22000                 cmp     %o0, 0
F00693EC: 02bffff9                 be      loc_F00693D0
F00693F0: 01000000                 nop
F00693F4: d0142004                 lduh    [%l0+4], %o0
F00693F8: 80a22000                 cmp     %o0, 0
F00693FC: 12bfffcc                 bne     loc_F006932C
F0069400: 113c043e                 sethi   -0xFEF0800, %o0
F0069404: c0242008                 clr     [%l0+8]
F0069408: b0102000                 mov     0, %i0
F006940C: 81c7e008                 ret
F0069410: 81e80000                 restore
