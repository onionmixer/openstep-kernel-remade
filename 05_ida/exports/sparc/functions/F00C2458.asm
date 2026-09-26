F00C2458: 9de3bf90                 save    %sp, -0x70, %sp
F00C245C: 94102000                 mov     0, %o2
F00C2460: 113c04fd92122350         set     _msdata, %o1
F00C2468: d0026018                 ld      [%o1+0x18], %o0
F00C246C: 80a20019                 cmp     %o0, %i1
F00C2470: 0280006a                 be      loc_F00C2618
F00C2474: 9402a001                 inc     %o2
F00C2478: 80a2a000                 cmp     %o2, 0
F00C247C: 04bffffb                 ble     loc_F00C2468
F00C2480: 92026034                 inc     0x34, %o1 ! '4'
F00C2484: 94102000                 mov     0, %o2
F00C2488: 113c04fdb4122350         set     _msdata, %i2
F00C2490: a610001a                 mov     %i2, %l3
F00C2494: aa102000                 mov     0, %l5
F00C2498: 92100013                 mov     %l3, %o1
F00C249C: d0026018                 ld      [%o1+0x18], %o0
F00C24A0: 80a22000                 cmp     %o0, 0
F00C24A4: 02800009                 be      loc_F00C24C8
F00C24A8: a8100015                 mov     %l5, %l4
F00C24AC: a6026034                 add     %o1, 0x34, %l3 ! '4'
F00C24B0: 9402a001                 inc     %o2
F00C24B4: 80a2a000                 cmp     %o2, 0
F00C24B8: 04bffff8                 ble     loc_F00C2498
F00C24BC: aa052034                 add     %l4, 0x34, %l5 ! '4'
F00C24C0: 1080005e                 ba      locret_F00C2638
F00C24C4: b0102010                 mov     0x10, %i0
F00C24C8: a52e2010                 sll     %i0, 16, %l2
F00C24CC: a13ca010                 sra     %l2, 16, %l0
F00C24D0: 90100010                 mov     %l0, %o0
F00C24D4: 7fffdc9a                 call    _zsopen
F00C24D8: 92102001                 mov     1, %o1
F00C24DC: b0920000                 orcc    %o0, %g0, %i0
F00C24E0: 12800056                 bne     locret_F00C2638
F00C24E4: 90100010                 mov     %l0, %o0
F00C24E8: 1310019d92126008         set     0x40067408, %o1
F00C24F0: ac07bff0                 add     %fp, var_10, %l6
F00C24F4: 94100016                 mov     %l6, %o2
F00C24F8: 9934a018                 srl     %l2, 24, %o4
F00C24FC: 972b2001                 sll     %o4, 1, %o3
F00C2500: 9602c00c                 add     %o3, %o4, %o3
F00C2504: 972ae002                 sll     %o3, 2, %o3
F00C2508: 9622c00c                 sub     %o3, %o4, %o3
F00C250C: 972ae002                 sll     %o3, 2, %o3
F00C2510: 193c0472981321f0         set     _cdevsw, %o4
F00C2518: a402c00c                 add     %o3, %o4, %l2
F00C251C: d804a010                 ld      [%l2+0x10], %o4
F00C2520: 9fc30000                 call    %o4
F00C2524: 96102000                 mov     0, %o3
F00C2528: b0920000                 orcc    %o0, %g0, %i0
F00C252C: 1280003e                 bne     loc_F00C2624
F00C2530: 90100017                 mov     %l7, %o0
F00C2534: 901020e0                 mov     0xE0, %o0
F00C2538: d037bff4                 sth     %o0, [%fp+var_C]
F00C253C: 9010200c                 mov     0xC, %o0
F00C2540: d02fbff1                 stb     %o0, [%fp+var_F]
F00C2544: d02fbff0                 stb     %o0, [%fp+var_10]
F00C2548: 90100010                 mov     %l0, %o0
F00C254C: 1320019d92126009         set     -0x7FF98BF7, %o1
F00C2554: 94100016                 mov     %l6, %o2
F00C2558: d804a010                 ld      [%l2+0x10], %o4
F00C255C: 9fc30000                 call    %o4
F00C2560: 96102000                 mov     0, %o3
F00C2564: b0920000                 orcc    %o0, %g0, %i0
F00C2568: 1280002f                 bne     loc_F00C2624
F00C256C: 90100017                 mov     %l7, %o0
F00C2570: ae100013                 mov     %l3, %l7
F00C2574: c035e020                 clrh    [%l7+0x20]
F00C2578: f225e018                 st      %i1, [%l7+0x18]
F00C257C: a2100017                 mov     %l7, %l1
F00C2580: 9010200c                 mov     0xC, %o0
F00C2584: d0246024                 st      %o0, [%l1+0x24]
F00C2588: 90102001                 mov     1, %o0
F00C258C: d0246028                 st      %o0, [%l1+0x28]
F00C2590: c0246030                 clr     [%l1+0x30]
F00C2594: d005001a                 ld      [%l4+%i2], %o0
F00C2598: 80a22000                 cmp     %o0, 0
F00C259C: 12800027                 bne     locret_F00C2638
F00C25A0: b0102000                 mov     0, %i0
F00C25A4: 113c0484                 sethi   %hi(_MS_BUF_BYTES), %o0
F00C25A8: d002212c                 ld      [%o0+%lo(_MS_BUF_BYTES)], %o0
F00C25AC: d0346004                 sth     %o0, [%l1+4]
F00C25B0: 912a2010                 sll     %o0, 16, %o0
F00C25B4: 7ffe96af                 call    _kalloc
F00C25B8: 913a2010                 sra     %o0, 16, %o0! void *
F00C25BC: b0920000                 orcc    %o0, %g0, %i0
F00C25C0: 32800004                 bne,a   loc_F00C25D0
F00C25C4: d2546004                 ldsh    [%l1+4], %o1! size_t
F00C25C8: 10800016                 ba      loc_F00C2620
F00C25CC: b0102016                 mov     0x16, %i0
F00C25D0: 7fff4a22                 call    _bzero
F00C25D4: 90100018                 mov     %i0, %o0
F00C25D8: d0546004                 ldsh    [%l1+4], %o0
F00C25DC: 9210200c                 mov     0xC, %o1
F00C25E0: 7ffd1008                 call    _udiv
F00C25E4: 90023ff0                 inc     -0x10, %o0
F00C25E8: 90022001                 inc     %o0
F00C25EC: d0360000                 sth     %o0, [%i0]
F00C25F0: 113c043e                 sethi   %hi(_hz), %o0
F00C25F4: d00223e0                 ld      [%o0+%lo(_hz)], %o0! int
F00C25F8: 133c0484                 sethi   %hi(_msjitterrate), %o1
F00C25FC: d2026128                 ld      [%o1+%lo(_msjitterrate)], %o1! int
F00C2600: 7ffd1002                 call    _div
F00C2604: f025401a                 st      %i0, [%l5+%i2]
F00C2608: 133c04fd                 sethi   %hi(_msjittertimeout), %o1! size_t
F00C260C: d0226388                 st      %o0, [%o1+%lo(_msjittertimeout)]
F00C2610: 40000022                 call    sub_F00C2698
F00C2614: 90100011                 mov     %l1, %o0
F00C2618: 10800008                 ba      locret_F00C2638
F00C261C: b0102000                 mov     0, %i0
F00C2620: 90100017                 mov     %l7, %o0! void *
F00C2624: 7fff4a0d                 call    _bzero
F00C2628: 92102034                 mov     0x34, %o1 ! '4'! size_t
F00C262C: 90100011                 mov     %l1, %o0! void *
F00C2630: 7fff4a0a                 call    _bzero
F00C2634: 92102018                 mov     0x18, %o1
F00C2638: 81c7e008                 ret
F00C263C: 81e80000                 restore
