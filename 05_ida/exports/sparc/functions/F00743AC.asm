F00743AC: 9de3bf88                 save    %sp, -0x78, %sp
F00743B0: 80a62000                 cmp     %i0, 0
F00743B4: 028000e6                 be      locret_F007474C
F00743B8: 01000000                 nop
F00743BC: 400089f3                 call    _splusclock
F00743C0: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00743C4: a6100008                 mov     %o0, %l3
F00743C8: d0040000                 ld      [%l0], %o0
F00743CC: 80a22000                 cmp     %o0, 0
F00743D0: 12bffffe                 bne     loc_F00743C8
F00743D4: 01000000                 nop
F00743D8: 40008ab4                 call    _simple_lock_try
F00743DC: 90100010                 mov     %l0, %o0
F00743E0: 80a22000                 cmp     %o0, 0
F00743E4: 02bffff9                 be      loc_F00743C8
F00743E8: 01000000                 nop
F00743EC: d0062024                 ld      [%i0+0x24], %o0
F00743F0: 90023fff                 inc     -1, %o0
F00743F4: 80a22000                 cmp     %o0, 0
F00743F8: 04800006                 ble     loc_F0074410
F00743FC: d0262024                 st      %o0, [%i0+0x24]
F0074400: c0262020                 clr     [%i0+0x20]
F0074404: 40008a48                 call    _splx
F0074408: 90100013                 mov     %l3, %o0
F007440C: 308000d0                 ba,a    locret_F007474C
F0074410: 90102001                 mov     1, %o0
F0074414: d0262024                 st      %o0, [%i0+0x24]
F0074418: c0262020                 clr     [%i0+0x20]
F007441C: 40008a42                 call    _splx
F0074420: 90100013                 mov     %l3, %o0
F0074424: e4062190                 ld      [%i0+0x190], %l2
F0074428: a004a158                 add     %l2, 0x158, %l0
F007442C: d0040000                 ld      [%l0], %o0
F0074430: 80a22000                 cmp     %o0, 0
F0074434: 12bffffe                 bne     loc_F007442C
F0074438: 01000000                 nop
F007443C: 40008a9b                 call    _simple_lock_try
F0074440: 90100010                 mov     %l0, %o0
F0074444: 80a22000                 cmp     %o0, 0
F0074448: 02bffff9                 be      loc_F007442C
F007444C: 01000000                 nop
F0074450: e206200c                 ld      [%i0+0xC], %l1
F0074454: d0044000                 ld      [%l1], %o0
F0074458: 80a22000                 cmp     %o0, 0
F007445C: 12bffffe                 bne     loc_F0074454
F0074460: 01000000                 nop
F0074464: 40008a91                 call    _simple_lock_try
F0074468: 90100011                 mov     %l1, %o0
F007446C: 80a22000                 cmp     %o0, 0
F0074470: 02bffff9                 be      loc_F0074454
F0074474: 01000000                 nop
F0074478: 400089c4                 call    _splusclock
F007447C: a0046028                 add     %l1, 0x28, %l0 ! '('
F0074480: a6100008                 mov     %o0, %l3
F0074484: d0040000                 ld      [%l0], %o0
F0074488: 80a22000                 cmp     %o0, 0
F007448C: 12bffffe                 bne     loc_F0074484
F0074490: 01000000                 nop
F0074494: 40008a85                 call    _simple_lock_try
F0074498: 90100010                 mov     %l0, %o0
F007449C: 80a22000                 cmp     %o0, 0
F00744A0: 02bffff9                 be      loc_F0074484
F00744A4: 01000000                 nop
F00744A8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00744AC: d0040000                 ld      [%l0], %o0
F00744B0: 80a22000                 cmp     %o0, 0
F00744B4: 12bffffe                 bne     loc_F00744AC
F00744B8: 01000000                 nop
F00744BC: 40008a7b                 call    _simple_lock_try
F00744C0: 90100010                 mov     %l0, %o0
F00744C4: 80a22000                 cmp     %o0, 0
F00744C8: 02bffff9                 be      loc_F00744AC
F00744CC: 01000000                 nop
F00744D0: d0062024                 ld      [%i0+0x24], %o0
F00744D4: 90023fff                 inc     -1, %o0
F00744D8: 80a22000                 cmp     %o0, 0
F00744DC: 04800009                 ble     loc_F0074500
F00744E0: d0262024                 st      %o0, [%i0+0x24]
F00744E4: c0262020                 clr     [%i0+0x20]
F00744E8: c0246028                 clr     [%l1+0x28]
F00744EC: 40008a0e                 call    _splx
F00744F0: 90100013                 mov     %l3, %o0
F00744F4: c0244000                 clr     [%l1]
F00744F8: c024a158                 clr     [%l2+0x158]
F00744FC: 30800094                 ba,a    locret_F007474C
F0074500: d006214c                 ld      [%i0+0x14C], %o0
F0074504: 80a22000                 cmp     %o0, 0
F0074508: 22800005                 be,a    loc_F007451C
F007450C: d0062184                 ld      [%i0+0x184], %o0
F0074510: 7fffd551                 call    _reset_timeout
F0074514: 90062118                 add     %i0, 0x118, %o0
F0074518: d0062184                 ld      [%i0+0x184], %o0
F007451C: 80a22000                 cmp     %o0, 0
F0074520: 02800005                 be      loc_F0074534
F0074524: 90103fff                 mov     -1, %o0
F0074528: 7fffd54b                 call    _reset_timeout
F007452C: 90062150                 add     %i0, 0x150, %o0
F0074530: 90103fff                 mov     -1, %o0
F0074534: d0262064                 st      %o0, [%i0+0x64]
F0074538: 90100018                 mov     %i0, %o0
F007453C: 9207bff0                 add     %fp, var_10, %o1
F0074540: 40000d2d                 call    _thread_read_times
F0074544: 9407bfe8                 add     %fp, var_18, %o2
F0074548: d0046058                 ld      [%l1+0x58], %o0
F007454C: d207bff4                 ld      [%fp+var_C], %o1
F0074550: 90020009                 add     %o0, %o1, %o0
F0074554: d2046054                 ld      [%l1+0x54], %o1
F0074558: d0246058                 st      %o0, [%l1+0x58]
F007455C: d007bff0                 ld      [%fp+var_10], %o0
F0074560: 92024008                 add     %o1, %o0, %o1
F0074564: d2246054                 st      %o1, [%l1+0x54]
F0074568: 110003d0                 sethi   0xF4000, %o0
F007456C: d2046058                 ld      [%l1+0x58], %o1
F0074570: 9612223f                 or      %o0, 0x23F, %o3
F0074574: 80a2400b                 cmp     %o1, %o3
F0074578: 04800008                 ble     loc_F0074598
F007457C: 113ffc2f                 sethi   -0xF4400, %o0
F0074580: 901221c0                 bset    0x1C0, %o0
F0074584: 90024008                 add     %o1, %o0, %o0
F0074588: d2046054                 ld      [%l1+0x54], %o1
F007458C: d0246058                 st      %o0, [%l1+0x58]
F0074590: 92026001                 inc     %o1
F0074594: d2246054                 st      %o1, [%l1+0x54]
F0074598: d0046060                 ld      [%l1+0x60], %o0
F007459C: d207bfec                 ld      [%fp+var_14], %o1
F00745A0: 90020009                 add     %o0, %o1, %o0
F00745A4: d204605c                 ld      [%l1+0x5C], %o1
F00745A8: d0246060                 st      %o0, [%l1+0x60]
F00745AC: d007bfe8                 ld      [%fp+var_18], %o0
F00745B0: d4046060                 ld      [%l1+0x60], %o2
F00745B4: 92024008                 add     %o1, %o0, %o1
F00745B8: 80a2800b                 cmp     %o2, %o3
F00745BC: 04800009                 ble     loc_F00745E0
F00745C0: d224605c                 st      %o1, [%l1+0x5C]
F00745C4: 113ffc2f901221c0         set     -0xF4240, %o0
F00745CC: 90028008                 add     %o2, %o0, %o0
F00745D0: d204605c                 ld      [%l1+0x5C], %o1
F00745D4: d0246060                 st      %o0, [%l1+0x60]
F00745D8: 92026001                 inc     %o1
F00745DC: d224605c                 st      %o1, [%l1+0x5C]
F00745E0: d0046024                 ld      [%l1+0x24], %o0
F00745E4: 90023fff                 inc     -1, %o0
F00745E8: d0246024                 st      %o0, [%l1+0x24]
F00745EC: d4062010                 ld      [%i0+0x10], %o2
F00745F0: 9004601c                 add     %l1, 0x1C, %o0
F00745F4: 80a2000a                 cmp     %o0, %o2
F00745F8: 12800004                 bne     loc_F0074608
F00745FC: d2062014                 ld      [%i0+0x14], %o1
F0074600: 10800004                 ba      loc_F0074610
F0074604: d2246020                 st      %o1, [%l1+0x20]
F0074608: d222a014                 st      %o1, [%o2+0x14]
F007460C: 9004601c                 add     %l1, 0x1C, %o0
F0074610: 80a20009                 cmp     %o0, %o1
F0074614: 22800003                 be,a    loc_F0074620
F0074618: d424601c                 st      %o2, [%l1+0x1C]
F007461C: d4226010                 st      %o2, [%o1+0x10]
F0074620: 90100012                 mov     %l2, %o0
F0074624: 7fffea7f                 call    _pset_remove_thread
F0074628: 92100018                 mov     %i0, %o1
F007462C: c0262020                 clr     [%i0+0x20]
F0074630: c0246028                 clr     [%l1+0x28]
F0074634: 400089bc                 call    _splx
F0074638: 90100013                 mov     %l3, %o0
F007463C: c0244000                 clr     [%l1]
F0074640: c024a158                 clr     [%l2+0x158]
F0074644: 7fffeabd                 call    _pset_deallocate
F0074648: 90100012                 mov     %l2, %o0
F007464C: d606207c                 ld      [%i0+0x7C], %o3
F0074650: 80a2e000                 cmp     %o3, 0
F0074654: 02800007                 be      loc_F0074670
F0074658: 113c04d1                 sethi   %hi(_kernel_map), %o0
F007465C: 133c0447                 sethi   %hi(_page_size), %o1
F0074660: d402613c                 ld      [%o1+%lo(_page_size)], %o2
F0074664: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0074668: 40003c87                 call    _kmem_free
F007466C: 9210000b                 mov     %o3, %o1
F0074670: d0062080                 ld      [%i0+0x80], %o0
F0074674: 80a22000                 cmp     %o0, 0
F0074678: 22800005                 be,a    loc_F007468C
F007467C: 113c04d0                 sethi   -0xFECC000, %o0
F0074680: 4000488e                 call    _vm_object_deallocate
F0074684: 01000000                 nop
F0074688: 113c04d0                 sethi   -0xFECC000, %o0
F007468C: d0022260                 ld      [%o0+0x260], %o0
F0074690: 80a60008                 cmp     %i0, %o0
F0074694: 32800006                 bne,a   loc_F00746AC
F0074698: d006204c                 ld      [%i0+0x4C], %o0
F007469C: 113c0442                 sethi   %hi(aThreadDealloca), %o0! "thread deallocating itself"
F00746A0: 7ffe82b4                 call    _panic
F00746A4: 901222b8                 bset    %lo(aThreadDealloca), %o0! "thread deallocating itself"
F00746A8: d006204c                 ld      [%i0+0x4C], %o0
F00746AC: 900a3eeb                 and     %o0, -0x115, %o0
F00746B0: 80a22002                 cmp     %o0, 2
F00746B4: 02800004                 be      loc_F00746C4
F00746B8: 113c0442                 sethi   %hi(aUnstoppedThrea), %o0! "unstopped thread destroyed!"
F00746BC: 7ffe82ad                 call    _panic
F00746C0: 901222d8                 bset    %lo(aUnstoppedThrea), %o0! "unstopped thread destroyed!"
F00746C4: 7ffffa79                 call    _task_deallocate
F00746C8: d006200c                 ld      [%i0+0xC], %o0
F00746CC: d006204c                 ld      [%i0+0x4C], %o0
F00746D0: 808a2100                 btst    0x100, %o0
F00746D4: 3280000d                 bne,a   loc_F0074708
F00746D8: d0062030                 ld      [%i0+0x30], %o0
F00746DC: 4000892b                 call    _splusclock
F00746E0: 01000000                 nop
F00746E4: 7fffd144                 call    _stack_free
F00746E8: 90100018                 mov     %i0, %o0
F00746EC: 4000898e                 call    _splx
F00746F0: 90100013                 mov     %l3, %o0
F00746F4: 133c0442                 sethi   %hi(_thread_deallocate_stack), %o1
F00746F8: d00262b0                 ld      [%o1+%lo(_thread_deallocate_stack)], %o0
F00746FC: 90022001                 inc     %o0
F0074700: d02262b0                 st      %o0, [%o1+%lo(_thread_deallocate_stack)]
F0074704: d0062030                 ld      [%i0+0x30], %o0
F0074708: 80a22000                 cmp     %o0, 0
F007470C: 02800004                 be      loc_F007471C
F0074710: 01000000                 nop
F0074714: 7fffcf85                 call    _freeStack
F0074718: 01000000                 nop
F007471C: 40009db1                 call    _pcb_terminate
F0074720: 90100018                 mov     %i0, %o0
F0074724: 133c04f2                 sethi   %hi(_nthreads), %o1
F0074728: d4026160                 ld      [%o1+%lo(_nthreads)], %o2
F007472C: d0062084                 ld      [%i0+0x84], %o0
F0074730: 9402bfff                 inc     -1, %o2
F0074734: 7ffe659a                 call    _uthread_free
F0074738: d4226160                 st      %o2, [%o1+%lo(_nthreads)]
F007473C: 113c04f2                 sethi   %hi(_thread_zone), %o0
F0074740: d0022320                 ld      [%o0+%lo(_thread_zone)], %o0
F0074744: 400012a3                 call    _zfree
F0074748: 92100018                 mov     %i0, %o1
F007474C: 81c7e008                 ret
F0074750: 81e80000                 restore
