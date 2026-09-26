F00A25C4: 9de3bf98                 save    %sp, -0x68, %sp
F00A25C8: 133c04f792126270         set     _pmap_info, %o1
F00A25D0: d00260e8                 ld      [%o1+0xE8], %o0
F00A25D4: 90022001                 inc     %o0
F00A25D8: d02260e8                 st      %o0, [%o1+0xE8]
F00A25DC: 113c04f8                 sethi   %hi(_kernel_seg_tables_phys), %o0
F00A25E0: d2022100                 ld      [%o0+%lo(_kernel_seg_tables_phys)], %o1
F00A25E4: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A25E8: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F00A25EC: 80a60009                 cmp     %i0, %o1
F00A25F0: 0a80000f                 bcs     loc_F00A262C
F00A25F4: a22e0008                 andn    %i0, %o0, %l1
F00A25F8: 113c04f8                 sethi   %hi(_kernel_seg_end), %o0
F00A25FC: d00220d0                 ld      [%o0+%lo(_kernel_seg_end)], %o0
F00A2600: 80a60008                 cmp     %i0, %o0
F00A2604: 1880000a                 bgu     loc_F00A262C
F00A2608: 90244009                 sub     %l1, %o1, %o0
F00A260C: 133c0447                 sethi   %hi(_page_size), %o1
F00A2610: 7ffd8ffc                 call    _udiv
F00A2614: d202613c                 ld      [%o1+%lo(_page_size)], %o1
F00A2618: 133c04f8                 sethi   %hi(_kernel_seg_pools), %o1
F00A261C: d20260e8                 ld      [%o1+%lo(_kernel_seg_pools)], %o1
F00A2620: 912a2005                 sll     %o0, 5, %o0
F00A2624: 1080001e                 ba      loc_F00A269C
F00A2628: a0024008                 add     %o1, %o0, %l0
F00A262C: 7fff8f43                 call    _vm_mem_ppi
F00A2630: 90100011                 mov     %l1, %o0
F00A2634: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F00A2638: 932a2002                 sll     %o0, 2, %o1
F00A263C: 92024008                 add     %o1, %o0, %o1
F00A2640: 972a6002                 sll     %o1, 2, %o3
F00A2644: d802a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o4
F00A2648: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00A264C: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00A2650: 9403000b                 add     %o4, %o3, %o2
F00A2654: d202a004                 ld      [%o2+4], %o1
F00A2658: 80a24008                 cmp     %o1, %o0
F00A265C: 1280000d                 bne     loc_F00A2690
F00A2660: e002a00c                 ld      [%o2+0xC], %l0
F00A2664: d002a008                 ld      [%o2+8], %o0
F00A2668: d2042008                 ld      [%l0+8], %o1
F00A266C: 91322008                 srl     %o0, 8, %o0
F00A2670: 912a200c                 sll     %o0, 12, %o0
F00A2674: 80a20009                 cmp     %o0, %o1
F00A2678: 12800007                 bne     loc_F00A2694
F00A267C: 113c0463                 sethi   -0xFEE7400, %o0
F00A2680: d003000b                 ld      [%o4+%o3], %o0
F00A2684: 80a22000                 cmp     %o0, 0
F00A2688: 22800006                 be,a    loc_F00A26A0
F00A268C: 90260011                 sub     %i0, %l1, %o0
F00A2690: 113c0463                 sethi   -0xFEE7400, %o0! char *
F00A2694: 7ffdcab7                 call    _panic
F00A2698: 901223f0                 bset    0x3F0, %o0
F00A269C: 90260011                 sub     %i0, %l1, %o0
F00A26A0: 913a2008                 sra     %o0, 8, %o0
F00A26A4: b12a2002                 sll     %o0, 2, %i0
F00A26A8: b0060008                 add     %i0, %o0, %i0
F00A26AC: d0042018                 ld      [%l0+0x18], %o0
F00A26B0: b12e2003                 sll     %i0, 3, %i0
F00A26B4: 81c7e008                 ret
F00A26B8: 91ea0018                 restore %o0, %i0, %o0
