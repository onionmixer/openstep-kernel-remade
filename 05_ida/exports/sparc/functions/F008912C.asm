F008912C: 9de3bf98                 save    %sp, -0x68, %sp
F0089130: 400036a2                 call    _spltty
F0089134: a2100018                 mov     %i0, %l1
F0089138: a4100008                 mov     %o0, %l2
F008913C: 113c04f6a01220f8         set     _vm_page_queue_free_lock, %l0
F0089144: d0040000                 ld      [%l0], %o0
F0089148: 80a22000                 cmp     %o0, 0
F008914C: 12bffffe                 bne     loc_F0089144
F0089150: 01000000                 nop
F0089154: 40003755                 call    _simple_lock_try
F0089158: 90100010                 mov     %l0, %o0
F008915C: 80a22000                 cmp     %o0, 0
F0089160: 02bffff9                 be      loc_F0089144
F0089164: 113c04f3                 sethi   %hi(_vm_page_queue_free), %o0
F0089168: d2022010                 ld      [%o0+%lo(_vm_page_queue_free)], %o1
F008916C: 90122010                 bset    %lo(_vm_page_queue_free), %o0
F0089170: 80a24008                 cmp     %o1, %o0
F0089174: 0280000e                 be      loc_F00891AC
F0089178: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F008917C: d2022000                 ld      [%o0+%lo(_vm_page_free_count)], %o1
F0089180: 113c0447                 sethi   %hi(_vm_page_free_reserved), %o0
F0089184: d002214c                 ld      [%o0+%lo(_vm_page_free_reserved)], %o0
F0089188: 80a24008                 cmp     %o1, %o0
F008918C: 1680000e                 bge     loc_F00891C4
F0089190: 113c04f3                 sethi   -0xFEC3400, %o0
F0089194: 113c04d0                 sethi   %hi(_active_threads), %o0
F0089198: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008919C: d0022078                 ld      [%o0+0x78], %o0
F00891A0: 80a22000                 cmp     %o0, 0
F00891A4: 12800008                 bne     loc_F00891C4
F00891A8: 113c04f3                 sethi   -0xFEC3400, %o0
F00891AC: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F00891B0: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F00891B4: 400036dc                 call    _splx
F00891B8: 90100012                 mov     %l2, %o0
F00891BC: 1080006d                 ba      locret_F0089370
F00891C0: b0102000                 mov     0, %i0
F00891C4: f0022010                 ld      [%o0+0x10], %i0
F00891C8: d2060000                 ld      [%i0], %o1
F00891CC: 90122010                 bset    0x10, %o0
F00891D0: 80a24008                 cmp     %o1, %o0
F00891D4: 32800003                 bne,a   loc_F00891E0
F00891D8: d0226004                 st      %o0, [%o1+4]
F00891DC: d2226004                 st      %o1, [%o1+4]
F00891E0: 113c04f3                 sethi   %hi(_vm_page_queue_free), %o0
F00891E4: d2222010                 st      %o1, [%o0+%lo(_vm_page_queue_free)]
F00891E8: d206201c                 ld      [%i0+0x1C], %o1
F00891EC: 11000004                 sethi   0x1000, %o0
F00891F0: 902a4008                 andn    %o1, %o0, %o0
F00891F4: d026201c                 st      %o0, [%i0+0x1C]
F00891F8: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F00891FC: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F0089200: 213c04f3                 sethi   %hi(_vm_page_free_count), %l0
F0089204: d2042000                 ld      [%l0+%lo(_vm_page_free_count)], %o1
F0089208: 90100012                 mov     %l2, %o0
F008920C: 92027fff                 inc     -1, %o1
F0089210: 400036c5                 call    _splx
F0089214: d2242000                 st      %o1, [%l0+%lo(_vm_page_free_count)]
F0089218: 7fffff1c                 call    _vm_page_remove
F008921C: 90100018                 mov     %i0, %o0
F0089220: 153c04f6                 sethi   %hi(_vm_page_template), %o2
F0089224: d002a150                 ld      [%o2+%lo(_vm_page_template)], %o0
F0089228: d0260000                 st      %o0, [%i0]
F008922C: 9412a150                 bset    %lo(_vm_page_template), %o2
F0089230: d002a004                 ld      [%o2+4], %o0
F0089234: d0262004                 st      %o0, [%i0+4]
F0089238: d002a008                 ld      [%o2+8], %o0
F008923C: d0262008                 st      %o0, [%i0+8]
F0089240: d002a00c                 ld      [%o2+0xC], %o0
F0089244: d026200c                 st      %o0, [%i0+0xC]
F0089248: d002a010                 ld      [%o2+0x10], %o0
F008924C: d0262010                 st      %o0, [%i0+0x10]
F0089250: d002a014                 ld      [%o2+0x14], %o0
F0089254: d0262014                 st      %o0, [%i0+0x14]
F0089258: d002a018                 ld      [%o2+0x18], %o0
F008925C: d0262018                 st      %o0, [%i0+0x18]
F0089260: d002a01c                 ld      [%o2+0x1C], %o0
F0089264: d026201c                 st      %o0, [%i0+0x1C]
F0089268: d002a020                 ld      [%o2+0x20], %o0
F008926C: d8062024                 ld      [%i0+0x24], %o4
F0089270: d0262020                 st      %o0, [%i0+0x20]
F0089274: d202a024                 ld      [%o2+0x24], %o1
F0089278: d2262024                 st      %o1, [%i0+0x24]
F008927C: d602a028                 ld      [%o2+0x28], %o3
F0089280: 90100018                 mov     %i0, %o0
F0089284: d6262028                 st      %o3, [%i0+0x28]
F0089288: d602a02c                 ld      [%o2+0x2C], %o3
F008928C: 92100011                 mov     %l1, %o1
F0089290: 94100019                 mov     %i1, %o2
F0089294: d626202c                 st      %o3, [%i0+0x2C]
F0089298: 7ffffec5                 call    _vm_page_insert
F008929C: d8262024                 st      %o4, [%i0+0x24]
F00892A0: d2042000                 ld      [%l0], %o1
F00892A4: 113c0447                 sethi   %hi(_vm_page_free_min), %o0
F00892A8: d0022144                 ld      [%o0+%lo(_vm_page_free_min)], %o0
F00892AC: 80a24008                 cmp     %o1, %o0
F00892B0: 0680000d                 bl      loc_F00892E4
F00892B4: 113c0447                 sethi   %hi(_vm_page_free_target), %o0
F00892B8: d0022140                 ld      [%o0+%lo(_vm_page_free_target)], %o0
F00892BC: 80a24008                 cmp     %o1, %o0
F00892C0: 3680000f                 bge,a   loc_F00892FC
F00892C4: d0146048                 lduh    [%l1+0x48], %o0
F00892C8: 113c04f0                 sethi   %hi(_vm_page_inactive_count), %o0
F00892CC: d2022220                 ld      [%o0+%lo(_vm_page_inactive_count)], %o1
F00892D0: 113c0447                 sethi   %hi(_vm_page_inactive_target), %o0
F00892D4: d0022148                 ld      [%o0+%lo(_vm_page_inactive_target)], %o0
F00892D8: 80a24008                 cmp     %o1, %o0
F00892DC: 36800008                 bge,a   loc_F00892FC
F00892E0: d0146048                 lduh    [%l1+0x48], %o0
F00892E4: 113c04f390122018         set     _vm_pages_needed, %o0
F00892EC: 92102000                 mov     0, %o1
F00892F0: 7fff9f43                 call    _thread_wakeup_prim
F00892F4: 94102000                 mov     0, %o2
F00892F8: d0146048                 lduh    [%l1+0x48], %o0
F00892FC: 808a2003                 btst    3, %o0
F0089300: 0280001b                 be      loc_F008936C
F0089304: 80a6a000                 cmp     %i2, 0
F0089308: 2280001a                 be,a    locret_F0089370
F008930C: f2246054                 st      %i1, [%l1+0x54]
F0089310: d2046054                 ld      [%l1+0x54], %o1
F0089314: 94a64009                 subcc   %i1, %o1, %o2
F0089318: 2c800002                 bneg,a  loc_F0089320
F008931C: 9420000a                 neg     %o2
F0089320: 113c0447                 sethi   %hi(_page_size), %o0
F0089324: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F0089328: 80a28008                 cmp     %o2, %o0
F008932C: 32800011                 bne,a   locret_F0089370
F0089330: f2246054                 st      %i1, [%l1+0x54]
F0089334: 7fffff19                 call    _vm_page_lookup
F0089338: 90100011                 mov     %l1, %o0
F008933C: 92920000                 orcc    %o0, %g0, %o1
F0089340: 2280000c                 be,a    locret_F0089370
F0089344: f2246054                 st      %i1, [%l1+0x54]
F0089348: d0146048                 lduh    [%l1+0x48], %o0
F008934C: 80a22001                 cmp     %o0, 1
F0089350: 02800005                 be      loc_F0089364
F0089354: 94102000                 mov     0, %o2
F0089358: 901a2002                 btog    2, %o0
F008935C: 80a00008                 cmp     %g0, %o0
F0089360: 94603fff                 subc    %g0, -1, %o2
F0089364: 7ffffc44                 call    _vm_policy_apply
F0089368: 90100011                 mov     %l1, %o0
F008936C: f2246054                 st      %i1, [%l1+0x54]
F0089370: 81c7e008                 ret
F0089374: 81e80000                 restore
