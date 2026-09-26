F00A27D4: 9de3bf98                 save    %sp, -0x68, %sp
F00A27D8: 113c04f790122270         set     _pmap_info, %o0
F00A27E0: d20220f0                 ld      [%o0+0xF0], %o1
F00A27E4: 92026001                 inc     %o1
F00A27E8: d22220f0                 st      %o1, [%o0+0xF0]
F00A27EC: d00e200f                 ldub    [%i0+0xF], %o0
F00A27F0: 80a22000                 cmp     %o0, 0
F00A27F4: 02800004                 be      loc_F00A2804
F00A27F8: 113c0464                 sethi   %hi(aPmapDeallocKse_1), %o0! "pmap_dealloc_kseg_entry(valid)"
F00A27FC: 7ffdca5d                 call    _panic
F00A2800: 90122088                 bset    %lo(aPmapDeallocKse_1), %o0! "pmap_dealloc_kseg_entry(valid)"
F00A2804: d0062010                 ld      [%i0+0x10], %o0
F00A2808: 80a22000                 cmp     %o0, 0
F00A280C: 12800006                 bne     loc_F00A2824
F00A2810: 113c0464                 sethi   -0xFEE7000, %o0
F00A2814: d0062014                 ld      [%i0+0x14], %o0
F00A2818: 80a22000                 cmp     %o0, 0
F00A281C: 02800004                 be      loc_F00A282C
F00A2820: 113c0464                 sethi   -0xFEE7000, %o0! char *
F00A2824: 7ffdca53                 call    _panic
F00A2828: 901220a8                 bset    0xA8, %o0
F00A282C: 7fffecf6                 call    _check_ptbl
F00A2830: 90100018                 mov     %i0, %o0
F00A2834: 80a22000                 cmp     %o0, 0
F00A2838: 02800004                 be      loc_F00A2848
F00A283C: 113c0464                 sethi   %hi(aPmapDeallocKse_2), %o0! "pmap_dealloc_kseg_entry: page_table non"...
F00A2840: 7ffdca4c                 call    _panic
F00A2844: 901220c8                 bset    %lo(aPmapDeallocKse_2), %o0! "pmap_dealloc_kseg_entry: page_table non"...
F00A2848: d00e200d                 ldub    [%i0+0xD], %o0
F00A284C: 80a22003                 cmp     %o0, 3
F00A2850: 12800017                 bne     loc_F00A28AC
F00A2854: 80a22002                 cmp     %o0, 2
F00A2858: d0062008                 ld      [%i0+8], %o0
F00A285C: 92102fff                 mov     0xFFF, %o1
F00A2860: d2222010                 st      %o1, [%o0+0x10]
F00A2864: d0062008                 ld      [%i0+8], %o0
F00A2868: c0222008                 clr     [%o0+8]
F00A286C: e0062020                 ld      [%i0+0x20], %l0
F00A2870: 80a42000                 cmp     %l0, 0
F00A2874: 02800021                 be      loc_F00A28F8
F00A2878: 90100010                 mov     %l0, %o0
F00A287C: d4062024                 ld      [%i0+0x24], %o2
F00A2880: 133fff00                 sethi   -0x40000, %o1
F00A2884: 7ffffcdc                 call    _set_invalidptp
F00A2888: 920a8009                 and     %o2, %o1, %o1
F00A288C: d00c200f                 ldub    [%l0+0xF], %o0
F00A2890: 80a22000                 cmp     %o0, 0
F00A2894: 3280001a                 bne,a   loc_F00A28FC
F00A2898: c0262008                 clr     [%i0+8]
F00A289C: 4000013d                 call    _pmap_dealloc_seg_entry
F00A28A0: 90100010                 mov     %l0, %o0
F00A28A4: 10800016                 ba      loc_F00A28FC
F00A28A8: c0262008                 clr     [%i0+8]
F00A28AC: 32800014                 bne,a   loc_F00A28FC
F00A28B0: c0262008                 clr     [%i0+8]
F00A28B4: d2062024                 ld      [%i0+0x24], %o1
F00A28B8: 113bffff901223ff         set     -0x10000001, %o0
F00A28C0: 80a24008                 cmp     %o1, %o0
F00A28C4: 18800023                 bgu     locret_F00A2950
F00A28C8: 92102fff                 mov     0xFFF, %o1
F00A28CC: d0062008                 ld      [%i0+8], %o0
F00A28D0: d222200c                 st      %o1, [%o0+0xC]
F00A28D4: d0062008                 ld      [%i0+8], %o0
F00A28D8: c0222004                 clr     [%o0+4]
F00A28DC: d0062020                 ld      [%i0+0x20], %o0
F00A28E0: 80a22000                 cmp     %o0, 0
F00A28E4: 02800005                 be      loc_F00A28F8
F00A28E8: 133fc000                 sethi   -0x1000000, %o1
F00A28EC: d4062024                 ld      [%i0+0x24], %o2
F00A28F0: 7ffffcc1                 call    _set_invalidptp
F00A28F4: 920a8009                 and     %o2, %o1, %o1
F00A28F8: c0262008                 clr     [%i0+8]
F00A28FC: 133c04f792126270         set     _pmap_info, %o1
F00A2904: d0026014                 ld      [%o1+0x14], %o0
F00A2908: 90023fff                 inc     -1, %o0
F00A290C: d0226014                 st      %o0, [%o1+0x14]
F00A2910: f0062004                 ld      [%i0+4], %i0
F00A2914: d016201e                 lduh    [%i0+0x1E], %o0
F00A2918: 80a22000                 cmp     %o0, 0
F00A291C: 1280000c                 bne     loc_F00A294C
F00A2920: 90022001                 inc     %o0
F00A2924: d036201e                 sth     %o0, [%i0+0x1E]
F00A2928: 113c04f790122230         set     _kseg_active, %o0
F00A2930: 7ffffac8                 call    _del_any_pool
F00A2934: 92100018                 mov     %i0, %o1
F00A2938: 113c04f790122240         set     _kseg_semi_active, %o0
F00A2940: 7ffffa9f                 call    _add_pool
F00A2944: 92100018                 mov     %i0, %o1
F00A2948: 30800002                 ba,a    locret_F00A2950
F00A294C: d036201e                 sth     %o0, [%i0+0x1E]
F00A2950: 81c7e008                 ret
F00A2954: 81e80000                 restore
