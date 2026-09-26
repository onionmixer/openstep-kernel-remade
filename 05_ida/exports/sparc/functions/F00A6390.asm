F00A6390: 9de3bf88                 save    %sp, -0x78, %sp
F00A6394: 7fffbce1                 call    _mmu_chk_wdreset
F00A6398: a4102000                 mov     0, %l2
F00A639C: 80a22000                 cmp     %o0, 0
F00A63A0: a6102000                 mov     0, %l3
F00A63A4: 02800004                 be      loc_F00A63B4
F00A63A8: a8102000                 mov     0, %l4
F00A63AC: 4000262a                 call    _prom_stopcpu
F00A63B0: 90102000                 mov     0, %o0
F00A63B4: 7fffbcd5                 call    _mmu_getasyncflt
F00A63B8: 9007bfe8                 add     %fp, var_18, %o0
F00A63BC: 113c044a                 sethi   %hi(_mod_info), %o0
F00A63C0: d0022264                 ld      [%o0+%lo(_mod_info)], %o0
F00A63C4: 80a22040                 cmp     %o0, 0x40 ! '@'
F00A63C8: 02800059                 be      loc_F00A652C
F00A63CC: 92102001                 mov     1, %o1
F00A63D0: 80a22041                 cmp     %o0, 0x41 ! 'A'
F00A63D4: 12800024                 bne     loc_F00A6464
F00A63D8: e007bfe8                 ld      [%fp+var_18], %l0
F00A63DC: e007bff0                 ld      [%fp+var_10], %l0
F00A63E0: 80a43fff                 cmp     %l0, -1
F00A63E4: 02800053                 be      loc_F00A6530
F00A63E8: 11008000                 sethi   0x2000000, %o0
F00A63EC: 808c0008                 btst    %o0, %l0
F00A63F0: 02800050                 be      loc_F00A6530
F00A63F4: e207bff4                 ld      [%fp+var_C], %l1
F00A63F8: d007bfe8                 ld      [%fp+var_18], %o0
F00A63FC: 7fffbd7d                 call    _vac_parity_chk_dis
F00A6400: 92100010                 mov     %l0, %o1
F00A6404: 133c0466                 sethi   %hi(_nofault), %o1
F00A6408: d2026144                 ld      [%o1+%lo(_nofault)], %o1
F00A640C: 80a26000                 cmp     %o1, 0
F00A6410: 02800004                 be      loc_F00A6420
F00A6414: 80a22000                 cmp     %o0, 0
F00A6418: 02800046                 be      loc_F00A6530
F00A641C: 92102000                 mov     0, %o1
F00A6420: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A6424: 7fffc2a1                 call    _simple_lock_try
F00A6428: 90122150                 bset    %lo(_system_fatal), %o0
F00A642C: 80a22000                 cmp     %o0, 0
F00A6430: 12800040                 bne     loc_F00A6530
F00A6434: 92102000                 mov     0, %o1
F00A6438: 113c04fb                 sethi   %hi(_sys_fatal_flt), %o0
F00A643C: 92102001                 mov     1, %o1
F00A6440: d2322070                 sth     %o1, [%o0+%lo(_sys_fatal_flt)]
F00A6444: 90122070                 bset    %lo(_sys_fatal_flt), %o0
F00A6448: c0322002                 clrh    [%o0+2]
F00A644C: e0222004                 st      %l0, [%o0+4]
F00A6450: e2222008                 st      %l1, [%o0+8]
F00A6454: c022200c                 clr     [%o0+0xC]
F00A6458: c0222010                 clr     [%o0+0x10]
F00A645C: 10800034                 ba      loc_F00A652C
F00A6460: c0222014                 clr     [%o0+0x14]
F00A6464: 808c2001                 btst    1, %l0
F00A6468: 02800017                 be      loc_F00A64C4
F00A646C: 113c0466                 sethi   %hi(_nofault), %o0
F00A6470: d0022144                 ld      [%o0+%lo(_nofault)], %o0
F00A6474: 80a22000                 cmp     %o0, 0
F00A6478: 12800012                 bne     loc_F00A64C0
F00A647C: e207bfec                 ld      [%fp+var_14], %l1
F00A6480: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A6484: 7fffc289                 call    _simple_lock_try
F00A6488: 90122150                 bset    %lo(_system_fatal), %o0
F00A648C: 80a22000                 cmp     %o0, 0
F00A6490: 1280000d                 bne     loc_F00A64C4
F00A6494: 92102000                 mov     0, %o1
F00A6498: 113c04fb                 sethi   %hi(_sys_fatal_flt), %o0
F00A649C: 92102001                 mov     1, %o1
F00A64A0: d2322070                 sth     %o1, [%o0+%lo(_sys_fatal_flt)]
F00A64A4: 90122070                 bset    %lo(_sys_fatal_flt), %o0
F00A64A8: c0322002                 clrh    [%o0+2]
F00A64AC: e0222004                 st      %l0, [%o0+4]
F00A64B0: e2222008                 st      %l1, [%o0+8]
F00A64B4: e422200c                 st      %l2, [%o0+0xC]
F00A64B8: e6222010                 st      %l3, [%o0+0x10]
F00A64BC: e8222014                 st      %l4, [%o0+0x14]
F00A64C0: 92102000                 mov     0, %o1
F00A64C4: e007bff0                 ld      [%fp+var_10], %l0
F00A64C8: 80a43fff                 cmp     %l0, -1
F00A64CC: 02800019                 be      loc_F00A6530
F00A64D0: 808c2001                 btst    1, %l0
F00A64D4: 02800017                 be      loc_F00A6530
F00A64D8: 113c0466                 sethi   %hi(_nofault), %o0
F00A64DC: d0022144                 ld      [%o0+%lo(_nofault)], %o0
F00A64E0: 80a22000                 cmp     %o0, 0
F00A64E4: 12800012                 bne     loc_F00A652C
F00A64E8: e207bff4                 ld      [%fp+var_C], %l1
F00A64EC: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A64F0: 7fffc26e                 call    _simple_lock_try
F00A64F4: 90122150                 bset    %lo(_system_fatal), %o0
F00A64F8: 80a22000                 cmp     %o0, 0
F00A64FC: 1280000d                 bne     loc_F00A6530
F00A6500: 92102000                 mov     0, %o1
F00A6504: 113c04fb                 sethi   %hi(_sys_fatal_flt), %o0
F00A6508: 92102001                 mov     1, %o1
F00A650C: d2322070                 sth     %o1, [%o0+%lo(_sys_fatal_flt)]
F00A6510: 90122070                 bset    %lo(_sys_fatal_flt), %o0
F00A6514: d2322002                 sth     %o1, [%o0+2]
F00A6518: e0222004                 st      %l0, [%o0+4]
F00A651C: e2222008                 st      %l1, [%o0+8]
F00A6520: e422200c                 st      %l2, [%o0+0xC]
F00A6524: e6222010                 st      %l3, [%o0+0x10]
F00A6528: e8222014                 st      %l4, [%o0+0x14]
F00A652C: 92102000                 mov     0, %o1
F00A6530: 80a26000                 cmp     %o1, 0
F00A6534: 02800004                 be      locret_F00A6544
F00A6538: 01000000                 nop
F00A653C: 400025c6                 call    _prom_stopcpu
F00A6540: 90102000                 mov     0, %o0
F00A6544: 81c7e008                 ret
F00A6548: 81e80000                 restore
