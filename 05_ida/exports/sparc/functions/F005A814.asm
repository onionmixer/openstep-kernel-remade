F005A814: 9de3bf98                 save    %sp, -0x68, %sp
F005A818: a2100018                 mov     %i0, %l1
F005A81C: d0046030                 ld      [%l1+0x30], %o0
F005A820: 80a22000                 cmp     %o0, 0
F005A824: 0280002e                 be      loc_F005A8DC
F005A828: a0046040                 add     %l1, 0x40, %l0 ! '@'
F005A82C: b0100008                 mov     %o0, %i0
F005A830: d0060000                 ld      [%i0], %o0
F005A834: 80a22000                 cmp     %o0, 0
F005A838: 12bffffe                 bne     loc_F005A830
F005A83C: 01000000                 nop
F005A840: 4000f19a                 call    _simple_lock_try
F005A844: 90100018                 mov     %i0, %o0
F005A848: 80a22000                 cmp     %o0, 0
F005A84C: 02bffff9                 be      loc_F005A830
F005A850: 01000000                 nop
F005A854: d0062008                 ld      [%i0+8], %o0
F005A858: 80a22000                 cmp     %o0, 0
F005A85C: 1680000f                 bge     loc_F005A898
F005A860: 90100018                 mov     %i0, %o0
F005A864: a0062010                 add     %i0, 0x10, %l0
F005A868: d0040000                 ld      [%l0], %o0
F005A86C: 80a22000                 cmp     %o0, 0
F005A870: 12bffffe                 bne     loc_F005A868
F005A874: 01000000                 nop
F005A878: 4000f18c                 call    _simple_lock_try
F005A87C: 90100010                 mov     %l0, %o0
F005A880: 80a22000                 cmp     %o0, 0
F005A884: 02bffff9                 be      loc_F005A868
F005A888: 01000000                 nop
F005A88C: c0260000                 clr     [%i0]
F005A890: 1080001d                 ba      locret_F005A904
F005A894: b0062010                 inc     0x10, %i0
F005A898: 400003ab                 call    _ipc_pset_remove
F005A89C: 92100011                 mov     %l1, %o1
F005A8A0: d0062004                 ld      [%i0+4], %o0
F005A8A4: c0260000                 clr     [%i0]
F005A8A8: 80a22000                 cmp     %o0, 0
F005A8AC: 1280000c                 bne     loc_F005A8DC
F005A8B0: a0046040                 add     %l1, 0x40, %l0 ! '@'
F005A8B4: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005A8B8: d0062008                 ld      [%i0+8], %o0
F005A8BC: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005A8C0: 912a2001                 sll     %o0, 1, %o0
F005A8C4: 91322011                 srl     %o0, 17, %o0
F005A8C8: 912a2002                 sll     %o0, 2, %o0
F005A8CC: d0020009                 ld      [%o0+%o1], %o0
F005A8D0: 40007a40                 call    _zfree
F005A8D4: 92100018                 mov     %i0, %o1
F005A8D8: a0046040                 add     %l1, 0x40, %l0 ! '@'
F005A8DC: d0040000                 ld      [%l0], %o0
F005A8E0: 80a22000                 cmp     %o0, 0
F005A8E4: 12bffffe                 bne     loc_F005A8DC
F005A8E8: 01000000                 nop
F005A8EC: 4000f16f                 call    _simple_lock_try
F005A8F0: 90100010                 mov     %l0, %o0
F005A8F4: 80a22000                 cmp     %o0, 0
F005A8F8: 02bffff9                 be      loc_F005A8DC
F005A8FC: 01000000                 nop
F005A900: b0046040                 add     %l1, 0x40, %i0 ! '@'
F005A904: 81c7e008                 ret
F005A908: 81e80000                 restore
