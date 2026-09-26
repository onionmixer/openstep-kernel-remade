F006D460: 9de3bf98                 save    %sp, -0x68, %sp
F006D464: e4062024                 ld      [%i0+0x24], %l2
F006D468: 80a4a000                 cmp     %l2, 0
F006D46C: 02800063                 be      locret_F006D5F8
F006D470: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F006D474: a0122230                 or      %o0, %lo(_vm_page_queue_lock), %l0
F006D478: d0040000                 ld      [%l0], %o0
F006D47C: 80a22000                 cmp     %o0, 0
F006D480: 12bffffe                 bne     loc_F006D478
F006D484: 01000000                 nop
F006D488: 4000a688                 call    _simple_lock_try
F006D48C: 90100010                 mov     %l0, %o0
F006D490: 80a22000                 cmp     %o0, 0
F006D494: 02bffff9                 be      loc_F006D478
F006D498: 01000000                 nop
F006D49C: a004a010                 add     %l2, 0x10, %l0
F006D4A0: d0040000                 ld      [%l0], %o0
F006D4A4: 80a22000                 cmp     %o0, 0
F006D4A8: 12bffffe                 bne     loc_F006D4A0
F006D4AC: 01000000                 nop
F006D4B0: 4000a67e                 call    _simple_lock_try
F006D4B4: 90100010                 mov     %l0, %o0
F006D4B8: 80a22000                 cmp     %o0, 0
F006D4BC: 02bffff9                 be      loc_F006D4A0
F006D4C0: 01000000                 nop
F006D4C4: d0062024                 ld      [%i0+0x24], %o0
F006D4C8: 80a20012                 cmp     %o0, %l2
F006D4CC: 1280004b                 bne     locret_F006D5F8
F006D4D0: 01000000                 nop
F006D4D4: e2048000                 ld      [%l2], %l1
F006D4D8: 80a48011                 cmp     %l2, %l1
F006D4DC: 02800044                 be      loc_F006D5EC
F006D4E0: 01000000                 nop
F006D4E4: 2b3c04f0                 sethi   -0xFEC4000, %l5
F006D4E8: 293c04f0                 sethi   -0xFEC4000, %l4
F006D4EC: 273c04f0                 sethi   -0xFEC4000, %l3
F006D4F0: d2046020                 ld      [%l1+0x20], %o1
F006D4F4: 91326014                 srl     %o1, 20, %o0
F006D4F8: 808a2001                 btst    1, %o0
F006D4FC: 12800038                 bne     loc_F006D5DC
F006D500: e0046008                 ld      [%l1+8], %l0
F006D504: 80a26000                 cmp     %o1, 0
F006D508: 3680001f                 bge,a   loc_F006D584
F006D50C: d014601c                 lduh    [%l1+0x1C], %o0
F006D510: 1110000090124008         set     0x40000000, %o0
F006D518: d0246020                 st      %o0, [%l1+0x20]
F006D51C: 90100011                 mov     %l1, %o0
F006D520: 40000ded                 call    _assert_wait
F006D524: 92102000                 mov     0, %o1
F006D528: c024a010                 clr     [%l2+0x10]
F006D52C: c0256230                 clr     [%l5+0x230]
F006D530: 40001464                 call    _thread_block
F006D534: a0156230                 or      %l5, 0x230, %l0
F006D538: d0040000                 ld      [%l0], %o0
F006D53C: 80a22000                 cmp     %o0, 0
F006D540: 12bffffe                 bne     loc_F006D538
F006D544: 01000000                 nop
F006D548: 4000a658                 call    _simple_lock_try
F006D54C: 90100010                 mov     %l0, %o0
F006D550: 80a22000                 cmp     %o0, 0
F006D554: 02bffff9                 be      loc_F006D538
F006D558: b004a010                 add     %l2, 0x10, %i0
F006D55C: d0060000                 ld      [%i0], %o0
F006D560: 80a22000                 cmp     %o0, 0
F006D564: 12bffffe                 bne     loc_F006D55C
F006D568: 01000000                 nop
F006D56C: 4000a64f                 call    _simple_lock_try
F006D570: 90100018                 mov     %i0, %o0
F006D574: 80a22000                 cmp     %o0, 0
F006D578: 02bffff9                 be      loc_F006D55C
F006D57C: 80a48011                 cmp     %l2, %l1
F006D580: 30800019                 ba,a    loc_F006D5E4
F006D584: 80a22000                 cmp     %o0, 0
F006D588: 32800016                 bne,a   loc_F006D5E0
F006D58C: a2100010                 mov     %l0, %l1
F006D590: 4000c09a                 call    _pmap_remove_all
F006D594: d0046024                 ld      [%l1+0x24], %o0
F006D598: d004601c                 ld      [%l1+0x1C], %o0
F006D59C: 808a2400                 btst    0x400, %o0
F006D5A0: 02800007                 be      loc_F006D5BC
F006D5A4: d00521e8                 ld      [%l4+0x1E8], %o0
F006D5A8: 4000c7d1                 call    _pmap_is_modified
F006D5AC: d0046024                 ld      [%l1+0x24], %o0
F006D5B0: 80a22000                 cmp     %o0, 0
F006D5B4: 02800005                 be      loc_F006D5C8
F006D5B8: d00521e8                 ld      [%l4+0x1E8], %o0
F006D5BC: 90022001                 inc     %o0
F006D5C0: 10800007                 ba      loc_F006D5DC
F006D5C4: d02521e8                 st      %o0, [%l4+0x1E8]
F006D5C8: d204e1e0                 ld      [%l3+0x1E0], %o1
F006D5CC: 90100011                 mov     %l1, %o0
F006D5D0: 92026001                 inc     %o1
F006D5D4: 40006f69                 call    _vm_page_free
F006D5D8: d224e1e0                 st      %o1, [%l3+0x1E0]
F006D5DC: a2100010                 mov     %l0, %l1
F006D5E0: 80a48011                 cmp     %l2, %l1
F006D5E4: 32bfffc4                 bne,a   loc_F006D4F4
F006D5E8: d2046020                 ld      [%l1+0x20], %o1
F006D5EC: c024a010                 clr     [%l2+0x10]
F006D5F0: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F006D5F4: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F006D5F8: 81c7e008                 ret
F006D5FC: 81e80000                 restore
