F00A2060: 9de3bf88                 save    %sp, -0x78, %sp
F00A2064: 133c04f792126270         set     _pmap_info, %o1
F00A206C: d00260e0                 ld      [%o1+0xE0], %o0
F00A2070: b2100018                 mov     %i0, %i1
F00A2074: 90022001                 inc     %o0
F00A2078: d02260e0                 st      %o0, [%o1+0xE0]
F00A207C: 133c04f7                 sethi   -0xFEC2400, %o1
F00A2080: d00263b8                 ld      [%o1+0x3B8], %o0
F00A2084: 80a22000                 cmp     %o0, 0
F00A2088: 02800032                 be      loc_F00A2150
F00A208C: 901263b8                 or      %o1, 0x3B8, %o0
F00A2090: 7ffffcde                 call    _del_first_pool
F00A2094: 90023ff8                 inc     -8, %o0
F00A2098: a4920000                 orcc    %o0, %g0, %l2
F00A209C: 02800007                 be      loc_F00A20B8
F00A20A0: 113c0463                 sethi   -0xFEE7400, %o0
F00A20A4: d014a01e                 lduh    [%l2+0x1E], %o0
F00A20A8: 80a22000                 cmp     %o0, 0
F00A20AC: 32800006                 bne,a   loc_F00A20C4
F00A20B0: e604a018                 ld      [%l2+0x18], %l3
F00A20B4: 113c0463                 sethi   -0xFEE7400, %o0! char *
F00A20B8: 7ffdcc2e                 call    _panic
F00A20BC: 901222c8                 bset    0x2C8, %o0
F00A20C0: e604a018                 ld      [%l2+0x18], %l3
F00A20C4: d014a01e                 lduh    [%l2+0x1E], %o0
F00A20C8: e814a01c                 lduh    [%l2+0x1C], %l4
F00A20CC: 90023fff                 inc     -1, %o0
F00A20D0: a8053fff                 inc     -1, %l4
F00A20D4: 80a53fff                 cmp     %l4, -1
F00A20D8: 028000d9                 be      locret_F00A243C
F00A20DC: d034a01e                 sth     %o0, [%l2+0x1E]
F00A20E0: 173c04f7                 sethi   -0xFEC2400, %o3
F00A20E4: 153c04f7                 sethi   -0xFEC2400, %o2
F00A20E8: 113c04f7a0122270         set     _pmap_info, %l0
F00A20F0: 9204e00f                 add     %l3, 0xF, %o1
F00A20F4: d0027ff9                 ld      [%o1-7], %o0
F00A20F8: 80a22000                 cmp     %o0, 0
F00A20FC: 32800010                 bne,a   loc_F00A213C
F00A2100: 92026054                 inc     0x54, %o1 ! 'T'
F00A2104: f2227ff9                 st      %i1, [%o1-7]
F00A2108: c02a4000                 clrb    [%o1]
F00A210C: d014a01e                 lduh    [%l2+0x1E], %o0
F00A2110: 80a22000                 cmp     %o0, 0
F00A2114: 12800003                 bne     loc_F00A2120
F00A2118: 9012a3b0                 or      %o2, 0x3B0, %o0
F00A211C: 9012e390                 or      %o3, 0x390, %o0
F00A2120: 7ffffca7                 call    _add_pool
F00A2124: 92100012                 mov     %l2, %o1
F00A2128: e6264000                 st      %l3, [%i1]
F00A212C: d0042024                 ld      [%l0+0x24], %o0
F00A2130: 90022001                 inc     %o0
F00A2134: 108000c2                 ba      locret_F00A243C
F00A2138: d0242024                 st      %o0, [%l0+0x24]
F00A213C: a8053fff                 inc     -1, %l4
F00A2140: 80a53fff                 cmp     %l4, -1
F00A2144: 12bfffec                 bne     loc_F00A20F4
F00A2148: a604e054                 inc     0x54, %l3 ! 'T'
F00A214C: 308000bc                 ba,a    locret_F00A243C
F00A2150: 133c04f7                 sethi   %hi(dword_F013DFA8), %o1
F00A2154: d00263a8                 ld      [%o1+%lo(dword_F013DFA8)], %o0
F00A2158: 80a22000                 cmp     %o0, 0
F00A215C: 02800061                 be      loc_F00A22E0
F00A2160: 901263a8                 or      %o1, %lo(dword_F013DFA8), %o0
F00A2164: 7ffffca9                 call    _del_first_pool
F00A2168: 90023ff8                 inc     -8, %o0
F00A216C: a4920000                 orcc    %o0, %g0, %l2
F00A2170: 32800006                 bne,a   loc_F00A2188
F00A2174: c024a008                 clr     [%l2+8]
F00A2178: 113c0463                 sethi   %hi(aPmapAllocRegEn_1), %o0! "pmap_alloc_reg_entry: reg_free.count wr"...
F00A217C: 7ffdcbfd                 call    _panic
F00A2180: 901222f8                 bset    %lo(aPmapAllocRegEn_1), %o0! "pmap_alloc_reg_entry: reg_free.count wr"...
F00A2184: c024a008                 clr     [%l2+8]
F00A2188: 133c0447                 sethi   %hi(_page_size), %o1
F00A218C: d402613c                 ld      [%o1+%lo(_page_size)], %o2
F00A2190: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00A2194: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00A2198: 7fff859b                 call    _kmem_alloc_wired
F00A219C: 9204a008                 add     %l2, 8, %o1
F00A21A0: 80a22000                 cmp     %o0, 0
F00A21A4: 02800004                 be      loc_F00A21B4
F00A21A8: 113c0463                 sethi   %hi(aPmapAllocRegEn_2), %o0! "pmap_alloc_reg_entry: no memory"
F00A21AC: 7ffdcbf1                 call    _panic
F00A21B0: 90122328                 bset    %lo(aPmapAllocRegEn_2), %o0! "pmap_alloc_reg_entry: no memory"
F00A21B4: 233c04f0                 sethi   %hi(_kernel_pmap), %l1
F00A21B8: d0046100                 ld      [%l1+%lo(_kernel_pmap)], %o0
F00A21BC: 7ffff332                 call    _pmap_resident_extract
F00A21C0: d204a008                 ld      [%l2+8], %o1
F00A21C4: 94100008                 mov     %o0, %o2
F00A21C8: 113c045d                 sethi   %hi(_mxcc), %o0
F00A21CC: d00222d4                 ld      [%o0+%lo(_mxcc)], %o0
F00A21D0: 80a22000                 cmp     %o0, 0
F00A21D4: 1280000a                 bne     loc_F00A21FC
F00A21D8: d424a004                 st      %o2, [%l2+4]
F00A21DC: 96102001                 mov     1, %o3
F00A21E0: 98102007                 mov     7, %o4
F00A21E4: d204a008                 ld      [%l2+8], %o1
F00A21E8: 9a102000                 mov     0, %o5
F00A21EC: d0046100                 ld      [%l1+%lo(_kernel_pmap)], %o0
F00A21F0: d623a05c                 st      %o3, [%sp+0x78+var_1C]
F00A21F4: 7fffef51                 call    _pmap_enter_dev
F00A21F8: 96102000                 mov     0, %o3
F00A21FC: 7fff904f                 call    _vm_mem_ppi
F00A2200: d004a004                 ld      [%l2+4], %o0
F00A2204: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F00A2208: 932a2002                 sll     %o0, 2, %o1
F00A220C: d602a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o3
F00A2210: 92024008                 add     %o1, %o0, %o1
F00A2214: d0046100                 ld      [%l1+0x100], %o0
F00A2218: 952a6002                 sll     %o1, 2, %o2
F00A221C: a002c00a                 add     %o3, %o2, %l0
F00A2220: d2042004                 ld      [%l0+4], %o1
F00A2224: 80a24008                 cmp     %o1, %o0
F00A2228: 1280000d                 bne     loc_F00A225C
F00A222C: 113c0463                 sethi   -0xFEE7400, %o0
F00A2230: d0042008                 ld      [%l0+8], %o0
F00A2234: d204a008                 ld      [%l2+8], %o1
F00A2238: 91322008                 srl     %o0, 8, %o0
F00A223C: 912a200c                 sll     %o0, 12, %o0
F00A2240: 80a20009                 cmp     %o0, %o1
F00A2244: 12800006                 bne     loc_F00A225C
F00A2248: 113c0463                 sethi   -0xFEE7400, %o0
F00A224C: d002c00a                 ld      [%o3+%o2], %o0
F00A2250: 80a22000                 cmp     %o0, 0
F00A2254: 02800004                 be      loc_F00A2264
F00A2258: 113c0463                 sethi   -0xFEE7400, %o0! char *
F00A225C: 7ffdcbc5                 call    _panic
F00A2260: 90122348                 bset    0x348, %o0
F00A2264: e0248000                 st      %l0, [%l2]
F00A2268: e424200c                 st      %l2, [%l0+0xC]
F00A226C: d014a01e                 lduh    [%l2+0x1E], %o0
F00A2270: 153c04f7                 sethi   %hi(word_F013DE72), %o2
F00A2274: e604a018                 ld      [%l2+0x18], %l3
F00A2278: 90023fff                 inc     -1, %o0
F00A227C: d034a01e                 sth     %o0, [%l2+0x1E]
F00A2280: d012a272                 lduh    [%o2+%lo(word_F013DE72)], %o0
F00A2284: a2102000                 mov     0, %l1
F00A2288: 80a44008                 cmp     %l1, %o0
F00A228C: 16800009                 bge     loc_F00A22B0
F00A2290: d204a008                 ld      [%l2+8], %o1
F00A2294: d224c000                 st      %o1, [%l3]
F00A2298: 92026400                 inc     0x400, %o1
F00A229C: a2046001                 inc     %l1
F00A22A0: d012a272                 lduh    [%o2+0x272], %o0
F00A22A4: 80a44008                 cmp     %l1, %o0
F00A22A8: 06bffffb                 bl      loc_F00A2294
F00A22AC: a604e054                 inc     0x54, %l3 ! 'T'
F00A22B0: 173c04f79612e270         set     _pmap_info, %o3
F00A22B8: 113c04f7                 sethi   %hi(_reg_semi_active), %o0
F00A22BC: d812e002                 lduh    [%o3+2], %o4
F00A22C0: 901223b0                 bset    %lo(_reg_semi_active), %o0
F00A22C4: d402e028                 ld      [%o3+0x28], %o2
F00A22C8: 92100012                 mov     %l2, %o1
F00A22CC: 9402800c                 add     %o2, %o4, %o2
F00A22D0: 7ffffc3b                 call    _add_pool
F00A22D4: d422e028                 st      %o2, [%o3+0x28]
F00A22D8: 10bfff6a                 ba      loc_F00A2080
F00A22DC: 133c04f7                 sethi   -0xFEC2400, %o1
F00A22E0: c027bff4                 clr     [%fp+var_C]
F00A22E4: 133c0447                 sethi   %hi(_page_size), %o1
F00A22E8: d402613c                 ld      [%o1+%lo(_page_size)], %o2
F00A22EC: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00A22F0: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00A22F4: 7fff8544                 call    _kmem_alloc_wired
F00A22F8: 9207bff4                 add     %fp, var_C, %o1! size_t
F00A22FC: 80a22000                 cmp     %o0, 0
F00A2300: 02800004                 be      loc_F00A2310
F00A2304: 113c0463                 sethi   %hi(aPmapAllocRegEn_3), %o0! "pmap_alloc_reg_entry: no memory"
F00A2308: 7ffdcb9a                 call    _panic
F00A230C: 90122378                 bset    %lo(aPmapAllocRegEn_3), %o0! "pmap_alloc_reg_entry: no memory"
F00A2310: ac102000                 mov     0, %l6
F00A2314: 113c04f7                 sethi   %hi(word_F013DE76), %o0
F00A2318: d0122276                 lduh    [%o0+%lo(word_F013DE76)], %o0
F00A231C: a8102000                 mov     0, %l4
F00A2320: 80a58008                 cmp     %l6, %o0
F00A2324: 1680002d                 bge     loc_F00A23D8
F00A2328: e607bff4                 ld      [%fp+var_C], %l3
F00A232C: 353c04f7                 sethi   -0xFEC2400, %i2
F00A2330: 2f3c04f7                 sethi   -0xFEC2400, %l7
F00A2334: b0102001                 mov     1, %i0
F00A2338: 7fff5b65                 call    _zalloc
F00A233C: d006a380                 ld      [%i2+0x380], %o0! void *
F00A2340: a4100008                 mov     %o0, %l2
F00A2344: 7fffcac5                 call    _bzero
F00A2348: 92102020                 mov     0x20, %o1 ! ' '! size_t
F00A234C: e624a018                 st      %l3, [%l2+0x18]
F00A2350: d015e272                 lduh    [%l7+0x272], %o0
F00A2354: d034a01c                 sth     %o0, [%l2+0x1C]
F00A2358: d015e272                 lduh    [%l7+0x272], %o0
F00A235C: d034a01e                 sth     %o0, [%l2+0x1E]
F00A2360: d015e272                 lduh    [%l7+0x272], %o0
F00A2364: a2102000                 mov     0, %l1
F00A2368: 80a44008                 cmp     %l1, %o0
F00A236C: 36800011                 bge,a   loc_F00A23B0
F00A2370: ec24a014                 st      %l6, [%l2+0x14]
F00A2374: 2b3c04f7                 sethi   -0xFEC2400, %l5
F00A2378: a004e00e                 add     %l3, 0xE, %l0
F00A237C: 90100013                 mov     %l3, %o0! void *
F00A2380: 7fffcab6                 call    _bzero
F00A2384: 92102054                 mov     0x54, %o1 ! 'T'
F00A2388: e4243ff6                 st      %l2, [%l0-0xA]
F00A238C: f02c3fff                 stb     %i0, [%l0-1]
F00A2390: e22c0000                 stb     %l1, [%l0]
F00A2394: a0042054                 inc     0x54, %l0 ! 'T'
F00A2398: d0156272                 lduh    [%l5+0x272], %o0
F00A239C: a2046001                 inc     %l1
F00A23A0: 80a44008                 cmp     %l1, %o0
F00A23A4: 06bffff6                 bl      loc_F00A237C
F00A23A8: a604e054                 inc     0x54, %l3 ! 'T'
F00A23AC: ec24a014                 st      %l6, [%l2+0x14]
F00A23B0: 113c04f7901223a0         set     _reg_free, %o0
F00A23B8: 7ffffc01                 call    _add_pool
F00A23BC: 92100012                 mov     %l2, %o1
F00A23C0: 113c04f7                 sethi   %hi(word_F013DE76), %o0
F00A23C4: d0122276                 lduh    [%o0+%lo(word_F013DE76)], %o0
F00A23C8: a8052001                 inc     %l4
F00A23CC: 80a50008                 cmp     %l4, %o0
F00A23D0: 06bfffda                 bl      loc_F00A2338
F00A23D4: ac100012                 mov     %l2, %l6
F00A23D8: 153c04f79412a270         set     _pmap_info, %o2
F00A23E0: d612a006                 lduh    [%o2+6], %o3
F00A23E4: d202a02c                 ld      [%o2+0x2C], %o1
F00A23E8: 113c04f7                 sethi   %hi(_garbage_zone), %o0
F00A23EC: d0022220                 ld      [%o0+%lo(_garbage_zone)], %o0
F00A23F0: 9202400b                 add     %o1, %o3, %o1
F00A23F4: 7fff5b36                 call    _zalloc
F00A23F8: d222a02c                 st      %o1, [%o2+0x2C]
F00A23FC: 94100008                 mov     %o0, %o2
F00A2400: ec22a008                 st      %l6, [%o2+8]
F00A2404: 113c04f7                 sethi   %hi(dword_F013DE1C), %o0
F00A2408: d202221c                 ld      [%o0+%lo(dword_F013DE1C)], %o1
F00A240C: 9612221c                 or      %o0, %lo(dword_F013DE1C), %o3
F00A2410: 9002fffc                 add     %o3, -4, %o0
F00A2414: 80a24008                 cmp     %o1, %o0
F00A2418: 32800003                 bne,a   loc_F00A2424
F00A241C: d4224000                 st      %o2, [%o1]
F00A2420: d422fffc                 st      %o2, [%o3-4]
F00A2424: d222a004                 st      %o1, [%o2+4]
F00A2428: 113c04f790122218         set     _garbage, %o0
F00A2430: d0228000                 st      %o0, [%o2]
F00A2434: 10bfff12                 ba      loc_F00A207C
F00A2438: d4222004                 st      %o2, [%o0+4]
F00A243C: 81c7e008                 ret
F00A2440: 81e80000                 restore
