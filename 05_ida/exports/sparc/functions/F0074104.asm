F0074104: 9de3bf98                 save    %sp, -0x68, %sp
F0074108: 80a62000                 cmp     %i0, 0
F007410C: 12800004                 bne     loc_F007411C
F0074110: 113c04f2                 sethi   -0xFEC3800, %o0
F0074114: 108000a4                 ba      locret_F00743A4
F0074118: b0102004                 mov     4, %i0
F007411C: 400013ec                 call    _zalloc
F0074120: d0022320                 ld      [%o0+0x320], %o0
F0074124: a2920000                 orcc    %o0, %g0, %l1
F0074128: 12800004                 bne     loc_F0074138
F007412C: 90100011                 mov     %l1, %o0! __dst
F0074130: 1080009d                 ba      locret_F00743A4
F0074134: b0102006                 mov     6, %i0
F0074138: 133c04f292126180         set     _thread_template, %o1! __src
F0074140: 7ffe4c58                 call    _memcpy
F0074144: 941021a0                 mov     0x1A0, %o2
F0074148: f024600c                 st      %i0, [%l1+0xC]
F007414C: 113c04f0                 sethi   %hi(_sched_tick), %o0
F0074150: d2022298                 ld      [%o0+%lo(_sched_tick)], %o1
F0074154: c0246020                 clr     [%l1+0x20]
F0074158: 90100011                 mov     %l1, %o0
F007415C: 7ffff2cf                 call    _thread_timeout_setup
F0074160: d2246070                 st      %o1, [%l1+0x70]
F0074164: 40009e2a                 call    _pcb_init
F0074168: 90100011                 mov     %l1, %o0
F007416C: 7fffcafc                 call    _ipc_thread_init
F0074170: 90100011                 mov     %l1, %o0
F0074174: 113c04d3                 sethi   %hi(_u_thread_zone), %o0
F0074178: 400013d5                 call    _zalloc
F007417C: d0022290                 ld      [%o0+%lo(_u_thread_zone)], %o0
F0074180: d0246084                 st      %o0, [%l1+0x84]
F0074184: 7ffe6713                 call    _uarea_zero
F0074188: 90100011                 mov     %l1, %o0
F007418C: 7ffe670b                 call    _uarea_init
F0074190: 90100011                 mov     %l1, %o0
F0074194: d0060000                 ld      [%i0], %o0
F0074198: 80a22000                 cmp     %o0, 0
F007419C: 12bffffe                 bne     loc_F0074194
F00741A0: 01000000                 nop
F00741A4: 40008b41                 call    _simple_lock_try
F00741A8: 90100018                 mov     %i0, %o0
F00741AC: 80a22000                 cmp     %o0, 0
F00741B0: 02bffff9                 be      loc_F0074194
F00741B4: 01000000                 nop
F00741B8: e406202c                 ld      [%i0+0x2C], %l2
F00741BC: 7fffebf8                 call    _pset_reference
F00741C0: 90100012                 mov     %l2, %o0
F00741C4: c0260000                 clr     [%i0]
F00741C8: a004a158                 add     %l2, 0x158, %l0
F00741CC: d0040000                 ld      [%l0], %o0
F00741D0: 80a22000                 cmp     %o0, 0
F00741D4: 12bffffe                 bne     loc_F00741CC
F00741D8: 01000000                 nop
F00741DC: 40008b33                 call    _simple_lock_try
F00741E0: 90100010                 mov     %l0, %o0
F00741E4: 80a22000                 cmp     %o0, 0
F00741E8: 02bffff9                 be      loc_F00741CC
F00741EC: 01000000                 nop
F00741F0: d0060000                 ld      [%i0], %o0
F00741F4: 80a22000                 cmp     %o0, 0
F00741F8: 12bffffe                 bne     loc_F00741F0
F00741FC: 01000000                 nop
F0074200: 40008b2a                 call    _simple_lock_try
F0074204: 90100018                 mov     %i0, %o0
F0074208: 80a22000                 cmp     %o0, 0
F007420C: 02bffff9                 be      loc_F00741F0
F0074210: 01000000                 nop
F0074214: e006202c                 ld      [%i0+0x2C], %l0
F0074218: d0042154                 ld      [%l0+0x154], %o0
F007421C: 80a22000                 cmp     %o0, 0
F0074220: 12800005                 bne     loc_F0074234
F0074224: 80a40012                 cmp     %l0, %l2
F0074228: 113c04d3a01223c0         set     _default_pset, %l0
F0074230: 80a40012                 cmp     %l0, %l2
F0074234: 2280000a                 be,a    loc_F007425C
F0074238: d0062048                 ld      [%i0+0x48], %o0
F007423C: 7fffebd8                 call    _pset_reference
F0074240: 90100010                 mov     %l0, %o0
F0074244: c0260000                 clr     [%i0]
F0074248: c024a158                 clr     [%l2+0x158]
F007424C: 7fffebbb                 call    _pset_deallocate
F0074250: 90100012                 mov     %l2, %o0
F0074254: 10bfffdd                 ba      loc_F00741C8
F0074258: a4100010                 mov     %l0, %l2
F007425C: d0246050                 st      %o0, [%l1+0x50]
F0074260: d204a164                 ld      [%l2+0x164], %o1
F0074264: d0046054                 ld      [%l1+0x54], %o0
F0074268: 80a24008                 cmp     %o1, %o0
F007426C: 26800002                 bl,a    loc_F0074274
F0074270: d2246054                 st      %o1, [%l1+0x54]
F0074274: d2046054                 ld      [%l1+0x54], %o1
F0074278: d0046050                 ld      [%l1+0x50], %o0
F007427C: 80a24008                 cmp     %o1, %o0
F0074280: 26800002                 bl,a    loc_F0074288
F0074284: d2246050                 st      %o1, [%l1+0x50]
F0074288: 90100011                 mov     %l1, %o0
F007428C: 7ffff5ae                 call    _compute_priority
F0074290: 92102001                 mov     1, %o1
F0074294: 90100012                 mov     %l2, %o0
F0074298: d4062018                 ld      [%i0+0x18], %o2
F007429C: 92100011                 mov     %l1, %o1
F00742A0: 9402a001                 inc     %o2
F00742A4: 7fffeb73                 call    _pset_add_thread
F00742A8: d4246040                 st      %o2, [%l1+0x40]
F00742AC: d004a128                 ld      [%l2+0x128], %o0
F00742B0: 80a22000                 cmp     %o0, 0
F00742B4: 22800006                 be,a    loc_F00742CC
F00742B8: d0062004                 ld      [%i0+4], %o0
F00742BC: d0046040                 ld      [%l1+0x40], %o0
F00742C0: 90022001                 inc     %o0
F00742C4: d0246040                 st      %o0, [%l1+0x40]
F00742C8: d0062004                 ld      [%i0+4], %o0
F00742CC: a0062028                 add     %i0, 0x28, %l0 ! '('
F00742D0: 90022001                 inc     %o0
F00742D4: 40008a2d                 call    _splusclock
F00742D8: d0262004                 st      %o0, [%i0+4]
F00742DC: a6100008                 mov     %o0, %l3
F00742E0: d0040000                 ld      [%l0], %o0
F00742E4: 80a22000                 cmp     %o0, 0
F00742E8: 12bffffe                 bne     loc_F00742E0
F00742EC: 01000000                 nop
F00742F0: 40008aee                 call    _simple_lock_try
F00742F4: 90100010                 mov     %l0, %o0
F00742F8: 80a22000                 cmp     %o0, 0
F00742FC: 02bffff9                 be      loc_F00742E0
F0074300: 01000000                 nop
F0074304: d0062024                 ld      [%i0+0x24], %o0
F0074308: 90022001                 inc     %o0
F007430C: d0262024                 st      %o0, [%i0+0x24]
F0074310: d2062020                 ld      [%i0+0x20], %o1
F0074314: 9006201c                 add     %i0, 0x1C, %o0
F0074318: 80a20009                 cmp     %o0, %o1
F007431C: 32800003                 bne,a   loc_F0074328
F0074320: e2226010                 st      %l1, [%o1+0x10]
F0074324: e226201c                 st      %l1, [%i0+0x1C]
F0074328: d2246014                 st      %o1, [%l1+0x14]
F007432C: 9006201c                 add     %i0, 0x1C, %o0
F0074330: d0246010                 st      %o0, [%l1+0x10]
F0074334: e2262020                 st      %l1, [%i0+0x20]
F0074338: c0262028                 clr     [%i0+0x28]
F007433C: 40008a7a                 call    _splx
F0074340: 90100013                 mov     %l3, %o0
F0074344: 90102001                 mov     1, %o0
F0074348: d0246188                 st      %o0, [%l1+0x188]
F007434C: d0062008                 ld      [%i0+8], %o0
F0074350: 80a22000                 cmp     %o0, 0
F0074354: 0280000d                 be      loc_F0074388
F0074358: 01000000                 nop
F007435C: c0260000                 clr     [%i0]
F0074360: c024a158                 clr     [%l2+0x158]
F0074364: 7fffcaa8                 call    _ipc_thread_enable
F0074368: 90100011                 mov     %l1, %o0
F007436C: 133c04f2                 sethi   %hi(_nthreads), %o1
F0074370: d0026160                 ld      [%o1+%lo(_nthreads)], %o0! target_act
F0074374: b0102000                 mov     0, %i0
F0074378: 90022001                 inc     %o0
F007437C: d0226160                 st      %o0, [%o1+%lo(_nthreads)]
F0074380: 10800009                 ba      locret_F00743A4
F0074384: e2264000                 st      %l1, [%i1]
F0074388: c0260000                 clr     [%i0]
F007438C: c024a158                 clr     [%l2+0x158]
F0074390: 40000141                 call    _thread_terminate
F0074394: 90100011                 mov     %l1, %o0
F0074398: 40000005                 call    _thread_deallocate
F007439C: 90100011                 mov     %l1, %o0
F00743A0: b0102005                 mov     5, %i0
F00743A4: 81c7e008                 ret
F00743A8: 81e80000                 restore
