F00B23C8: 9de3bf90                 save    %sp, -0x70, %sp
F00B23CC: 92100018                 mov     %i0, %o1
F00B23D0: d0066014                 ld      [%i1+0x14], %o0
F00B23D4: 80a22000                 cmp     %o0, 0
F00B23D8: 0480007c                 ble     locret_F00B25C8
F00B23DC: b0102000                 mov     0, %i0
F00B23E0: a60a60ff                 and     %o1, 0xFF, %l3
F00B23E4: 2b3c04d1                 sethi   -0xFECBC00, %l5
F00B23E8: 293c0447                 sethi   -0xFEEE400, %l4
F00B23EC: e0064000                 ld      [%i1], %l0
F00B23F0: d0042004                 ld      [%l0+4], %o0
F00B23F4: 80a22000                 cmp     %o0, 0
F00B23F8: 1280000e                 bne     loc_F00B2430
F00B23FC: 80a4e001                 cmp     %l3, 1
F00B2400: 92042008                 add     %l0, 8, %o1
F00B2404: d0066004                 ld      [%i1+4], %o0
F00B2408: d2264000                 st      %o1, [%i1]
F00B240C: 90023fff                 inc     -1, %o0
F00B2410: 80a22000                 cmp     %o0, 0
F00B2414: 16800061                 bge     loc_F00B2598
F00B2418: d0266004                 st      %o0, [%i1+4]
F00B241C: 113c0477                 sethi   %hi(aMmrw), %o0! "mmrw"
F00B2420: 7ffd8b54                 call    _panic
F00B2424: 90122118                 bset    %lo(aMmrw), %o0! "mmrw"
F00B2428: 1080005d                 ba      loc_F00B259C
F00B242C: d0066014                 ld      [%i1+0x14], %o0
F00B2430: 02800041                 be      loc_F00B2534
F00B2434: 80a4e001                 cmp     %l3, 1
F00B2438: 14800007                 bg      loc_F00B2454
F00B243C: 80a4e002                 cmp     %l3, 2
F00B2440: 80a4e000                 cmp     %l3, 0
F00B2444: 02800008                 be      loc_F00B2464
F00B2448: 113c04f0                 sethi   -0xFEC4000, %o0
F00B244C: 10800045                 ba      loc_F00B2560
F00B2450: 80a62000                 cmp     %i0, 0
F00B2454: 02800040                 be      loc_F00B2554
F00B2458: 80a6a000                 cmp     %i2, 0
F00B245C: 10800041                 ba      loc_F00B2560
F00B2460: 80a62000                 cmp     %i0, 0
F00B2464: d2022108                 ld      [%o0+0x108], %o1
F00B2468: d4066008                 ld      [%i1+8], %o2
F00B246C: 113c04d0                 sethi   %hi(_page_mask), %o0
F00B2470: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F00B2474: 80a28009                 cmp     %o2, %o1
F00B2478: 1a800053                 bcc     loc_F00B25C4
F00B247C: a22a8008                 andn    %o2, %o0, %l1
F00B2480: 7fff921f                 call    _splvm
F00B2484: 01000000                 nop
F00B2488: 92102000                 mov     0, %o1
F00B248C: 94102000                 mov     0, %o2
F00B2490: d805213c                 ld      [%l4+0x13C], %o4
F00B2494: 9607bff4                 add     %fp, var_C, %o3
F00B2498: da056340                 ld      [%l5+0x340], %o5
F00B249C: a4100008                 mov     %o0, %l2
F00B24A0: c4036014                 ld      [%o5+0x14], %g2
F00B24A4: 9010000d                 mov     %o5, %o0
F00B24A8: c427bff4                 st      %g2, [%fp+var_C]
F00B24AC: 7fff4849                 call    _vm_map_find
F00B24B0: 9a102001                 mov     1, %o5
F00B24B4: 80a22000                 cmp     %o0, 0
F00B24B8: 12800041                 bne     loc_F00B25BC
F00B24BC: d207bff4                 ld      [%fp+var_C], %o1
F00B24C0: 94100011                 mov     %l1, %o2
F00B24C4: d0056340                 ld      [%l5+0x340], %o0
F00B24C8: 96102003                 mov     3, %o3
F00B24CC: d0022024                 ld      [%o0+0x24], %o0
F00B24D0: 7fffaff7                 call    _pmap_enter
F00B24D4: 98102001                 mov     1, %o4
F00B24D8: d2042004                 ld      [%l0+4], %o1
F00B24DC: e0066008                 ld      [%i1+8], %l0
F00B24E0: d005213c                 ld      [%l4+0x13C], %o0
F00B24E4: a0240011                 sub     %l0, %l1, %l0
F00B24E8: 7ffd8c05                 call    _min
F00B24EC: 90220010                 sub     %o0, %l0, %o0
F00B24F0: a2100008                 mov     %o0, %l1
F00B24F4: 92100011                 mov     %l1, %o1
F00B24F8: 9410001a                 mov     %i2, %o2
F00B24FC: d007bff4                 ld      [%fp+var_C], %o0
F00B2500: 96100019                 mov     %i1, %o3
F00B2504: 7ffd7f85                 call    _uiomove
F00B2508: 90020010                 add     %o0, %l0, %o0
F00B250C: d207bff4                 ld      [%fp+var_C], %o1
F00B2510: d405213c                 ld      [%l4+0x13C], %o2
F00B2514: b0100008                 mov     %o0, %i0
F00B2518: d0056340                 ld      [%l5+0x340], %o0
F00B251C: 7fff4b89                 call    _vm_map_remove
F00B2520: 9402400a                 add     %o1, %o2, %o2
F00B2524: 7fff9200                 call    _splx
F00B2528: 90100012                 mov     %l2, %o0
F00B252C: 1080001c                 ba      loc_F00B259C
F00B2530: d0066014                 ld      [%i1+0x14], %o0
F00B2534: a2100008                 mov     %o0, %l1
F00B2538: d0066008                 ld      [%i1+8], %o0
F00B253C: 92100011                 mov     %l1, %o1
F00B2540: 9410001a                 mov     %i2, %o2
F00B2544: 7ffd7f75                 call    _uiomove
F00B2548: 96100019                 mov     %i1, %o3
F00B254C: 10800013                 ba      loc_F00B2598
F00B2550: b0100008                 mov     %o0, %i0
F00B2554: 02800018                 be      loc_F00B25B4
F00B2558: a2100008                 mov     %o0, %l1
F00B255C: 80a62000                 cmp     %i0, 0
F00B2560: 1280001a                 bne     locret_F00B25C8
F00B2564: 01000000                 nop
F00B2568: d0040000                 ld      [%l0], %o0
F00B256C: d2042004                 ld      [%l0+4], %o1
F00B2570: 90020011                 add     %o0, %l1, %o0
F00B2574: d0240000                 st      %o0, [%l0]
F00B2578: 92224011                 sub     %o1, %l1, %o1
F00B257C: d2242004                 st      %o1, [%l0+4]
F00B2580: d0066008                 ld      [%i1+8], %o0
F00B2584: d2066014                 ld      [%i1+0x14], %o1
F00B2588: 90020011                 add     %o0, %l1, %o0
F00B258C: d0266008                 st      %o0, [%i1+8]
F00B2590: 92224011                 sub     %o1, %l1, %o1
F00B2594: d2266014                 st      %o1, [%i1+0x14]
F00B2598: d0066014                 ld      [%i1+0x14], %o0
F00B259C: 80a22000                 cmp     %o0, 0
F00B25A0: 0480000a                 ble     locret_F00B25C8
F00B25A4: 80a62000                 cmp     %i0, 0
F00B25A8: 22bfff92                 be,a    loc_F00B23F0
F00B25AC: e0064000                 ld      [%i1], %l0
F00B25B0: 30800006                 ba,a    locret_F00B25C8
F00B25B4: 10800005                 ba      locret_F00B25C8
F00B25B8: b0102000                 mov     0, %i0
F00B25BC: 7fff91da                 call    _splx
F00B25C0: 90100012                 mov     %l2, %o0
F00B25C4: b010200e                 mov     0xE, %i0
F00B25C8: 81c7e008                 ret
F00B25CC: 81e80000                 restore
