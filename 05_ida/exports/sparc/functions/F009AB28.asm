F009AB28: 9de3bf98                 save    %sp, -0x68, %sp
F009AB2C: a0102000                 mov     0, %l0
F009AB30: 7fffedbb                 call    _swift_getversion
F009AB34: a2102000                 mov     0, %l1
F009AB38: 95322018                 srl     %o0, 24, %o2
F009AB3C: 113c045d                 sethi   %hi(dword_F0117568), %o0
F009AB40: d4222168                 st      %o2, [%o0+%lo(dword_F0117568)]
F009AB44: 113c045d                 sethi   %hi(_swift), %o0
F009AB48: c022216c                 clr     [%o0+%lo(_swift)]
F009AB4C: 133c0464                 sethi   %hi(_small_4m), %o1
F009AB50: 90102001                 mov     1, %o0
F009AB54: d02262b0                 st      %o0, [%o1+%lo(_small_4m)]
F009AB58: 113c0464                 sethi   %hi(_no_vme), %o0
F009AB5C: c02222b4                 clr     [%o0+%lo(_no_vme)]
F009AB60: 113c0464                 sethi   %hi(_no_mix), %o0
F009AB64: c02222b8                 clr     [%o0+%lo(_no_mix)]
F009AB68: 113c0464                 sethi   %hi(_hat_cachesync_bug), %o0
F009AB6C: c02222c0                 clr     [%o0+%lo(_hat_cachesync_bug)]
F009AB70: 133c045c                 sethi   %hi(_v_mmu_writeptp), %o1
F009AB74: 113c026b901223a4         set     _swift_mmu_writeptp, %o0
F009AB7C: d02262fc                 st      %o0, [%o1+%lo(_v_mmu_writeptp)]
F009AB80: 133c045c                 sethi   %hi(_v_mmu_print_sfsr), %o1
F009AB84: 113c026b901221b8         set     _swift_mmu_print_sfsr, %o0
F009AB8C: d02262f4                 st      %o0, [%o1+%lo(_v_mmu_print_sfsr)]
F009AB90: 133c045c                 sethi   %hi(_v_mmu_writepte), %o1
F009AB94: 113c026b90122104         set     _swift_mmu_writepte, %o0
F009AB9C: d02262f8                 st      %o0, [%o1+%lo(_v_mmu_writepte)]
F009ABA0: 133c045c                 sethi   %hi(_v_mmu_chk_wdreset), %o1
F009ABA4: 113c0258901221c0         set     _swift_mmu_chk_wdreset, %o0
F009ABAC: d02262dc                 st      %o0, [%o1+%lo(_v_mmu_chk_wdreset)]
F009ABB0: 133c045c                 sethi   %hi(_v_mmu_getasyncflt), %o1
F009ABB4: 113c0258901221d0         set     _swift_mmu_getasyncflt, %o0
F009ABBC: d02262d8                 st      %o0, [%o1+%lo(_v_mmu_getasyncflt)]
F009ABC0: 133c045c                 sethi   %hi(_v_vac_init), %o1
F009ABC4: 113c026a901221f4         set     _swift_vac_init, %o0
F009ABCC: d0226304                 st      %o0, [%o1+%lo(_v_vac_init)]
F009ABD0: 133c045c                 sethi   %hi(_v_cache_on), %o1
F009ABD4: 113c0257901221a0         set     _swift_cache_on, %o0
F009ABDC: d0226328                 st      %o0, [%o1+%lo(_v_cache_on)]
F009ABE0: 133c045c                 sethi   %hi(_v_cache_sync), %o1
F009ABE4: 113c0257901221e8         set     _swift_vac_flushall, %o0
F009ABEC: d022632c                 st      %o0, [%o1+%lo(_v_cache_sync)]
F009ABF0: 133c045c                 sethi   %hi(_v_vac_flushall), %o1
F009ABF4: d0226308                 st      %o0, [%o1+%lo(_v_vac_flushall)]
F009ABF8: 133c045c                 sethi   %hi(_v_vac_usrflush), %o1
F009ABFC: 113c025790122228         set     _swift_vac_usrflush, %o0
F009AC04: d022630c                 st      %o0, [%o1+%lo(_v_vac_usrflush)]
F009AC08: 133c045c                 sethi   %hi(_v_vac_ctxflush), %o1
F009AC0C: 113c025790122284         set     _swift_vac_ctxflush, %o0
F009AC14: d0226310                 st      %o0, [%o1+%lo(_v_vac_ctxflush)]
F009AC18: 133c045c                 sethi   %hi(_v_vac_rgnflush), %o1
F009AC1C: 113c025790122338         set     _swift_vac_rgnflush, %o0
F009AC24: d0226314                 st      %o0, [%o1+%lo(_v_vac_rgnflush)]
F009AC28: 133c045c                 sethi   %hi(_v_vac_segflush), %o1
F009AC2C: 113c0257901223e8         set     _swift_vac_segflush, %o0
F009AC34: d0226318                 st      %o0, [%o1+%lo(_v_vac_segflush)]
F009AC38: 133c045c                 sethi   %hi(_v_vac_pageflush), %o1
F009AC3C: 113c025890122098         set     _swift_vac_pageflush, %o0
F009AC44: d022631c                 st      %o0, [%o1+%lo(_v_vac_pageflush)]
F009AC48: 133c045c                 sethi   %hi(_v_vac_pagectxflush), %o1
F009AC4C: 113c0258901220ec         set     _swift_vac_pagectxflush, %o0
F009AC54: d0226320                 st      %o0, [%o1+%lo(_v_vac_pagectxflush)]
F009AC58: 133c045c                 sethi   %hi(_v_vac_flush), %o1
F009AC5C: 113c025790122204         set     _swift_vac_flush, %o0
F009AC64: d0226324                 st      %o0, [%o1+%lo(_v_vac_flush)]
F009AC68: 133c0464                 sethi   %hi(_cache), %o1
F009AC6C: d0026330                 ld      [%o1+%lo(_cache)], %o0
F009AC70: 80a2a011                 cmp     %o2, 0x11
F009AC74: 90122001                 bset    1, %o0
F009AC78: 02800015                 be      loc_F009ACCC
F009AC7C: d0226330                 st      %o0, [%o1+%lo(_cache)]
F009AC80: 80a2a011                 cmp     %o2, 0x11
F009AC84: 18800006                 bgu     loc_F009AC9C
F009AC88: 80a2a000                 cmp     %o2, 0
F009AC8C: 02800009                 be      loc_F009ACB0
F009AC90: 133c045c                 sethi   -0xFEE9000, %o1
F009AC94: 10800011                 ba      loc_F009ACD8
F009AC98: 133c045d                 sethi   -0xFEE8C00, %o1
F009AC9C: 80a2a020                 cmp     %o2, 0x20 ! ' '
F009ACA0: 2280000c                 be,a    loc_F009ACD0
F009ACA4: a0102001                 mov     1, %l0
F009ACA8: 1080000c                 ba      loc_F009ACD8
F009ACAC: 133c045d                 sethi   -0xFEE8C00, %o1
F009ACB0: 113c0256901222e0         set     _srmmu_mmu_flushall, %o0
F009ACB8: d02262c8                 st      %o0, [%o1+0x2C8]
F009ACBC: 133c045c                 sethi   %hi(_v_mmu_flushrgn), %o1
F009ACC0: d02262c4                 st      %o0, [%o1+%lo(_v_mmu_flushrgn)]
F009ACC4: 133c045c                 sethi   %hi(_v_mmu_flushctx), %o1
F009ACC8: d02262c0                 st      %o0, [%o1+%lo(_v_mmu_flushctx)]
F009ACCC: a0102001                 mov     1, %l0
F009ACD0: a2102001                 mov     1, %l1
F009ACD4: 133c045d                 sethi   -0xFEE8C00, %o1
F009ACD8: d0026160                 ld      [%o1+0x160], %o0
F009ACDC: 80a23fff                 cmp     %o0, -1
F009ACE0: 22800002                 be,a    loc_F009ACE8
F009ACE4: e0226160                 st      %l0, [%o1+0x160]
F009ACE8: 133c045d                 sethi   %hi(_swift_kdnx), %o1
F009ACEC: d0026164                 ld      [%o1+%lo(_swift_kdnx)], %o0
F009ACF0: 80a23fff                 cmp     %o0, -1
F009ACF4: 22800002                 be,a    locret_F009ACFC
F009ACF8: e2226164                 st      %l1, [%o1+%lo(_swift_kdnx)]
F009ACFC: 81c7e008                 ret
F009AD00: 81e80000                 restore
