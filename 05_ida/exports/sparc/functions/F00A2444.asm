F00A2444: 9de3bf98                 save    %sp, -0x68, %sp
F00A2448: 113c04f7a2122270         set     _pmap_info, %l1
F00A2450: d00460e4                 ld      [%l1+0xE4], %o0
F00A2454: 133c04f0                 sethi   %hi(_kernel_pmap), %o1
F00A2458: d2026100                 ld      [%o1+%lo(_kernel_pmap)], %o1
F00A245C: 90022001                 inc     %o0
F00A2460: d02460e4                 st      %o0, [%l1+0xE4]
F00A2464: 80a60009                 cmp     %i0, %o1
F00A2468: 02800055                 be      locret_F00A25BC
F00A246C: e0060000                 ld      [%i0], %l0
F00A2470: d00c200f                 ldub    [%l0+0xF], %o0
F00A2474: 80a22010                 cmp     %o0, 0x10
F00A2478: 08800005                 bleu    loc_F00A248C
F00A247C: 113c0463                 sethi   %hi(aPmapDeallocReg_1), %o0! "pmap_dealloc_reg_entry(valid_cnt %d)\n"
F00A2480: d20c200f                 ldub    [%l0+0xF], %o1
F00A2484: 7ffdcb3b                 call    _panic
F00A2488: 90122398                 bset    %lo(aPmapDeallocReg_1), %o0! "pmap_dealloc_reg_entry(valid_cnt %d)\n"
F00A248C: c0242008                 clr     [%l0+8]
F00A2490: d0046024                 ld      [%l1+0x24], %o0
F00A2494: 90023fff                 inc     -1, %o0
F00A2498: d0246024                 st      %o0, [%l1+0x24]
F00A249C: f0042004                 ld      [%l0+4], %i0
F00A24A0: d016201e                 lduh    [%i0+0x1E], %o0
F00A24A4: 80a22000                 cmp     %o0, 0
F00A24A8: 1280000d                 bne     loc_F00A24DC
F00A24AC: 90022001                 inc     %o0
F00A24B0: d036201e                 sth     %o0, [%i0+0x1E]
F00A24B4: 113c04f790122390         set     _reg_active, %o0
F00A24BC: 7ffffbe5                 call    _del_any_pool
F00A24C0: 92100018                 mov     %i0, %o1
F00A24C4: 113c04f7901223b0         set     _reg_semi_active, %o0
F00A24CC: 7ffffbbc                 call    _add_pool
F00A24D0: 92100018                 mov     %i0, %o1
F00A24D4: 10800004                 ba      loc_F00A24E4
F00A24D8: d216201e                 lduh    [%i0+0x1E], %o1
F00A24DC: d036201e                 sth     %o0, [%i0+0x1E]
F00A24E0: d216201e                 lduh    [%i0+0x1E], %o1
F00A24E4: d016201c                 lduh    [%i0+0x1C], %o0
F00A24E8: 80a24008                 cmp     %o1, %o0
F00A24EC: 12800034                 bne     locret_F00A25BC
F00A24F0: 133c04f7                 sethi   %hi(dword_F013DFB8), %o1
F00A24F4: d00263b8                 ld      [%o1+%lo(dword_F013DFB8)], %o0
F00A24F8: 80a2200a                 cmp     %o0, 0xA
F00A24FC: 04800030                 ble     locret_F00A25BC
F00A2500: 901263b8                 or      %o1, %lo(dword_F013DFB8), %o0
F00A2504: 90023ff8                 inc     -8, %o0
F00A2508: 7ffffbd2                 call    _del_any_pool
F00A250C: 92100018                 mov     %i0, %o1
F00A2510: 7fff8f8a                 call    _vm_mem_ppi
F00A2514: d0062004                 ld      [%i0+4], %o0
F00A2518: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F00A251C: 932a2002                 sll     %o0, 2, %o1
F00A2520: 92024008                 add     %o1, %o0, %o1
F00A2524: d602a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o3
F00A2528: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00A252C: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00A2530: 952a6002                 sll     %o1, 2, %o2
F00A2534: a002c00a                 add     %o3, %o2, %l0
F00A2538: d2042004                 ld      [%l0+4], %o1
F00A253C: 80a24008                 cmp     %o1, %o0
F00A2540: 1280000d                 bne     loc_F00A2574
F00A2544: 113c0463                 sethi   -0xFEE7400, %o0
F00A2548: d0042008                 ld      [%l0+8], %o0
F00A254C: d2062008                 ld      [%i0+8], %o1
F00A2550: 91322008                 srl     %o0, 8, %o0
F00A2554: 912a200c                 sll     %o0, 12, %o0
F00A2558: 80a20009                 cmp     %o0, %o1
F00A255C: 12800006                 bne     loc_F00A2574
F00A2560: 113c0463                 sethi   -0xFEE7400, %o0
F00A2564: d002c00a                 ld      [%o3+%o2], %o0
F00A2568: 80a22000                 cmp     %o0, 0
F00A256C: 02800004                 be      loc_F00A257C
F00A2570: 113c0463                 sethi   -0xFEE7400, %o0! char *
F00A2574: 7ffdcaff                 call    _panic
F00A2578: 901223c0                 bset    0x3C0, %o0
F00A257C: c024200c                 clr     [%l0+0xC]
F00A2580: d0062008                 ld      [%i0+8], %o0
F00A2584: 7fff84c0                 call    _kmem_free
F00A2588: c0260000                 clr     [%i0]
F00A258C: 173c04f79612e270         set     _pmap_info, %o3
F00A2594: 113c04f7                 sethi   %hi(_reg_free), %o0
F00A2598: d812e002                 lduh    [%o3+2], %o4
F00A259C: 901223a0                 bset    %lo(_reg_free), %o0
F00A25A0: d402e028                 ld      [%o3+0x28], %o2
F00A25A4: 92100018                 mov     %i0, %o1
F00A25A8: 9422800c                 sub     %o2, %o4, %o2
F00A25AC: d422e028                 st      %o2, [%o3+0x28]
F00A25B0: c0226008                 clr     [%o1+8]
F00A25B4: 7ffffb82                 call    _add_pool
F00A25B8: c0226004                 clr     [%o1+4]
F00A25BC: 81c7e008                 ret
F00A25C0: 81e80000                 restore
