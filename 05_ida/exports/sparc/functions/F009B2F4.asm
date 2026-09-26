F009B2F4: 9de3bf98                 save    %sp, -0x68, %sp
F009B2F8: 113c045d                 sethi   %hi(_viking), %o0
F009B2FC: 92102001                 mov     1, %o1
F009B300: 808e2800                 btst    0x800, %i0
F009B304: 02800010                 be      loc_F009B344
F009B308: d22222d0                 st      %o1, [%o0+%lo(_viking)]
F009B30C: 133c0464                 sethi   %hi(_cache), %o1
F009B310: 90102002                 mov     2, %o0
F009B314: d0226330                 st      %o0, [%o1+%lo(_cache)]
F009B318: 133c044a                 sethi   %hi(_mod_info), %o1
F009B31C: 90102040                 mov     0x40, %o0 ! '@'
F009B320: d0226264                 st      %o0, [%o1+%lo(_mod_info)]
F009B324: 133c045c                 sethi   %hi(_v_mmu_log_module_err), %o1
F009B328: 113c026d90122098         set     _vik_mmu_log_module_err, %o0
F009B330: d02262f0                 st      %o0, [%o1+%lo(_v_mmu_log_module_err)]
F009B334: 133c045c                 sethi   -0xFEE9000, %o1
F009B338: 113c0259                 sethi   %hi(_vik_pac_pageflush), %o0
F009B33C: 10800015                 ba      loc_F009B390
F009B340: 9012220c                 bset    %lo(_vik_pac_pageflush), %o0
F009B344: 113c045d                 sethi   %hi(_mxcc), %o0
F009B348: d22222d4                 st      %o1, [%o0+%lo(_mxcc)]
F009B34C: 133c0464                 sethi   %hi(_cache), %o1
F009B350: 90102003                 mov     3, %o0
F009B354: d0226330                 st      %o0, [%o1+%lo(_cache)]
F009B358: 133c044a                 sethi   %hi(_mod_info), %o1
F009B35C: 90102041                 mov     0x41, %o0 ! 'A'
F009B360: d0226264                 st      %o0, [%o1+%lo(_mod_info)]
F009B364: 133c045c                 sethi   %hi(_v_mmu_log_module_err), %o1
F009B368: 113c026d901220e4         set     _mxcc_mmu_log_module_err, %o0
F009B370: d02262f0                 st      %o0, [%o1+%lo(_v_mmu_log_module_err)]
F009B374: 133c045c                 sethi   %hi(_v_vac_parity_chk_dis), %o1
F009B378: 113c0258901223bc         set     _mxcc_vac_parity_chk_dis, %o0
F009B380: d0226330                 st      %o0, [%o1+%lo(_v_vac_parity_chk_dis)]
F009B384: 133c045c                 sethi   -0xFEE9000, %o1
F009B388: 113c0259901222c4         set     _vik_mxcc_pageflush, %o0
F009B390: d0226334                 st      %o0, [%o1+0x334]
F009B394: 133c045c                 sethi   %hi(_v_vac_init), %o1
F009B398: 113c026b901223e4         set     _vik_vac_init, %o0
F009B3A0: d0226304                 st      %o0, [%o1+%lo(_v_vac_init)]
F009B3A4: 133c045c                 sethi   %hi(_v_cache_on), %o1
F009B3A8: 113c025890122388         set     _vik_cache_on, %o0
F009B3B0: d0226328                 st      %o0, [%o1+%lo(_v_cache_on)]
F009B3B4: 133c045c                 sethi   %hi(_v_mmu_getasyncflt), %o1
F009B3B8: 113c02589012222c         set     _vik_mmu_getasyncflt, %o0
F009B3C0: d02262d8                 st      %o0, [%o1+%lo(_v_mmu_getasyncflt)]
F009B3C4: 133c045c                 sethi   %hi(_v_mmu_chk_wdreset), %o1
F009B3C8: 113c025890122280         set     _vik_mmu_chk_wdreset, %o0
F009B3D0: d02262dc                 st      %o0, [%o1+%lo(_v_mmu_chk_wdreset)]
F009B3D4: 133c045c                 sethi   %hi(_v_mmu_print_sfsr), %o1
F009B3D8: 113c026d901221f4         set     _vik_mmu_print_sfsr, %o0
F009B3E0: d02262f4                 st      %o0, [%o1+%lo(_v_mmu_print_sfsr)]
F009B3E4: 133c045c                 sethi   %hi(_v_mmu_writepte), %o1
F009B3E8: 113c026e90122040         set     _vik_mmu_writepte, %o0
F009B3F0: d02262f8                 st      %o0, [%o1+%lo(_v_mmu_writepte)]
F009B3F4: 153c045c                 sethi   %hi(_v_module_wkaround), %o2
F009B3F8: 113c026e901220b4         set     _vik_module_wkaround, %o0
F009B400: 133c0464                 sethi   %hi(_cache), %o1
F009B404: d2026330                 ld      [%o1+%lo(_cache)], %o1
F009B408: 80a26003                 cmp     %o1, 3
F009B40C: 1280001d                 bne     loc_F009B480
F009B410: d022a300                 st      %o0, [%o2+%lo(_v_module_wkaround)]
F009B414: 133c045c                 sethi   %hi(_v_mmu_flushctx), %o1
F009B418: 113c025990122020         set     _vik_mmu_flushctx, %o0
F009B420: d02262c0                 st      %o0, [%o1+%lo(_v_mmu_flushctx)]
F009B424: 133c045c                 sethi   %hi(_v_mmu_flushrgn), %o1
F009B428: 113c025990122094         set     _vik_mmu_flushrgn, %o0
F009B430: d02262c4                 st      %o0, [%o1+%lo(_v_mmu_flushrgn)]
F009B434: 133c045c                 sethi   %hi(_v_mmu_flushseg), %o1
F009B438: 113c02599012209c         set     _vik_mmu_flushseg, %o0
F009B440: d02262c8                 st      %o0, [%o1+%lo(_v_mmu_flushseg)]
F009B444: 133c045c                 sethi   %hi(_v_mmu_flushpage), %o1
F009B448: 113c0259901220a4         set     _vik_mmu_flushpage, %o0
F009B450: d02262cc                 st      %o0, [%o1+%lo(_v_mmu_flushpage)]
F009B454: 153c045c                 sethi   %hi(_v_mmu_flushpagectx), %o2
F009B458: 113c0259901220b4         set     _vik_mmu_flushpagectx, %o0
F009B460: 133c0464                 sethi   %hi(_use_page_coloring), %o1
F009B464: d20262c8                 ld      [%o1+%lo(_use_page_coloring)], %o1
F009B468: 80a26000                 cmp     %o1, 0
F009B46C: 02800005                 be      loc_F009B480
F009B470: d022a2d0                 st      %o0, [%o2+%lo(_v_mmu_flushpagectx)]
F009B474: 133c0464                 sethi   %hi(_do_pg_coloring), %o1
F009B478: 90102001                 mov     1, %o0
F009B47C: d02262fc                 st      %o0, [%o1+%lo(_do_pg_coloring)]
F009B480: 4000013f                 call    _get_vik_rev_level
F009B484: 90100018                 mov     %i0, %o0
F009B488: 133c045d                 sethi   %hi(_vik_rev_level), %o1
F009B48C: d02262d8                 st      %o0, [%o1+%lo(_vik_rev_level)]
F009B490: 81c7e008                 ret
F009B494: 81e80000                 restore
