F007122C: 9de3bf98                 save    %sp, -0x68, %sp
F0071230: a4100018                 mov     %i0, %l2
F0071234: 90102001                 mov     1, %o0
F0071238: d204a108                 ld      [%l2+0x108], %o1
F007123C: 80a26000                 cmp     %o1, 0
F0071240: 04800009                 ble     loc_F0071264
F0071244: d024a124                 st      %o0, [%l2+0x124]
F0071248: 40000311                 call    _choose_thread
F007124C: 90100012                 mov     %l2, %o0
F0071250: 133c04f0                 sethi   %hi(_min_quantum), %o1
F0071254: d2026290                 ld      [%o1+%lo(_min_quantum)], %o1
F0071258: b0100008                 mov     %o0, %i0
F007125C: 10800061                 ba      locret_F00713E0
F0071260: d224a120                 st      %o1, [%l2+0x120]
F0071264: 113c04d3a21223c0         set     _default_pset, %l1
F007126C: a0046100                 add     %l1, 0x100, %l0
F0071270: d0040000                 ld      [%l0], %o0
F0071274: 80a22000                 cmp     %o0, 0
F0071278: 12bffffe                 bne     loc_F0071270
F007127C: 01000000                 nop
F0071280: 4000970a                 call    _simple_lock_try
F0071284: 90100010                 mov     %l0, %o0
F0071288: 80a22000                 cmp     %o0, 0
F007128C: 02bffff9                 be      loc_F0071270
F0071290: 01000000                 nop
F0071294: d0046108                 ld      [%l1+0x108], %o0
F0071298: 80a22000                 cmp     %o0, 0
F007129C: 32800023                 bne,a   loc_F0071328
F00712A0: d0046104                 ld      [%l1+0x104], %o0
F00712A4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00712A8: f0022260                 ld      [%o0+%lo(_active_threads)], %i0
F00712AC: d006204c                 ld      [%i0+0x4C], %o0
F00712B0: 80a22004                 cmp     %o0, 4
F00712B4: 12800026                 bne     loc_F007134C
F00712B8: 90100012                 mov     %l2, %o0
F00712BC: d0062194                 ld      [%i0+0x194], %o0
F00712C0: 80a22000                 cmp     %o0, 0
F00712C4: 02800004                 be      loc_F00712D4
F00712C8: 80a20012                 cmp     %o0, %l2
F00712CC: 12800020                 bne     loc_F007134C
F00712D0: 90100012                 mov     %l2, %o0
F00712D4: c0246100                 clr     [%l1+0x100]
F00712D8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00712DC: d0040000                 ld      [%l0], %o0
F00712E0: 80a22000                 cmp     %o0, 0
F00712E4: 12bffffe                 bne     loc_F00712DC
F00712E8: 01000000                 nop
F00712EC: 400096ef                 call    _simple_lock_try
F00712F0: 90100010                 mov     %l0, %o0
F00712F4: 80a22000                 cmp     %o0, 0
F00712F8: 02bffff9                 be      loc_F00712DC
F00712FC: 133c04f0                 sethi   %hi(_sched_tick), %o1
F0071300: d0062070                 ld      [%i0+0x70], %o0
F0071304: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F0071308: 80a20009                 cmp     %o0, %o1
F007130C: 02800004                 be      loc_F007131C
F0071310: 01000000                 nop
F0071314: 400001cd                 call    _update_priority
F0071318: 90100018                 mov     %i0, %o0
F007131C: c0262020                 clr     [%i0+0x20]
F0071320: 1080002b                 ba      loc_F00713CC
F0071324: d0062060                 ld      [%i0+0x60], %o0
F0071328: 952a2003                 sll     %o0, 3, %o2
F007132C: f004400a                 ld      [%l1+%o2], %i0
F0071330: 9204400a                 add     %l1, %o2, %o1
F0071334: 80a24018                 cmp     %o1, %i0
F0071338: 12800009                 bne     loc_F007135C
F007133C: 80a60009                 cmp     %i0, %o1
F0071340: 90023fff                 inc     -1, %o0
F0071344: d0246104                 st      %o0, [%l1+0x104]
F0071348: 90100012                 mov     %l2, %o0
F007134C: 4000030f                 call    _choose_pset_thread
F0071350: 92100011                 mov     %l1, %o1
F0071354: 1080001d                 ba      loc_F00713C8
F0071358: b0100008                 mov     %o0, %i0
F007135C: 32800004                 bne,a   loc_F007136C
F0071360: d0060000                 ld      [%i0], %o0
F0071364: 10800005                 ba      loc_F0071378
F0071368: b0102000                 mov     0, %i0
F007136C: d2222004                 st      %o1, [%o0+4]
F0071370: d0060000                 ld      [%i0], %o0
F0071374: d024400a                 st      %o0, [%l1+%o2]
F0071378: c0262008                 clr     [%i0+8]
F007137C: d0046108                 ld      [%l1+0x108], %o0
F0071380: 90023fff                 inc     -1, %o0
F0071384: 80a22000                 cmp     %o0, 0
F0071388: 0480000f                 ble     loc_F00713C4
F007138C: d0246108                 st      %o0, [%l1+0x108]
F0071390: d0046168                 ld      [%l1+0x168], %o0
F0071394: 808a2002                 btst    2, %o0
F0071398: 0280000b                 be      loc_F00713C4
F007139C: 01000000                 nop
F00713A0: 10800006                 ba      loc_F00713B8
F00713A4: d0024000                 ld      [%o1], %o0
F00713A8: 92027ff8                 inc     -8, %o1
F00713AC: 90023fff                 inc     -1, %o0
F00713B0: d0246104                 st      %o0, [%l1+0x104]
F00713B4: d0024000                 ld      [%o1], %o0
F00713B8: 80a24008                 cmp     %o1, %o0
F00713BC: 22bffffb                 be,a    loc_F00713A8
F00713C0: d0046104                 ld      [%l1+0x104], %o0
F00713C4: c0246100                 clr     [%l1+0x100]
F00713C8: d0062060                 ld      [%i0+0x60], %o0
F00713CC: 80a22002                 cmp     %o0, 2
F00713D0: 22800003                 be,a    loc_F00713DC
F00713D4: d006205c                 ld      [%i0+0x5C], %o0
F00713D8: d004616c                 ld      [%l1+0x16C], %o0
F00713DC: d024a120                 st      %o0, [%l2+0x120]
F00713E0: 81c7e008                 ret
F00713E4: 81e80000                 restore
