F0075A8C: 9de3bf98                 save    %sp, -0x68, %sp
F0075A90: 293c04f2a6152168         set     _reaper_lock, %l3
F0075A98: 2b3c04d4                 sethi   -0xFECB000, %l5
F0075A9C: 4000843b                 call    _splusclock
F0075AA0: 01000000                 nop
F0075AA4: a2100008                 mov     %o0, %l1
F0075AA8: d004c000                 ld      [%l3], %o0
F0075AAC: 80a22000                 cmp     %o0, 0
F0075AB0: 12bffffe                 bne     loc_F0075AA8
F0075AB4: 01000000                 nop
F0075AB8: 400084fc                 call    _simple_lock_try
F0075ABC: 90100013                 mov     %l3, %o0
F0075AC0: 80a22000                 cmp     %o0, 0
F0075AC4: 02bffff9                 be      loc_F0075AA8
F0075AC8: 113c04d4                 sethi   %hi(_reaper_queue), %o0
F0075ACC: a4122150                 or      %o0, %lo(_reaper_queue), %l2
F0075AD0: d2056150                 ld      [%l5+0x150], %o1
F0075AD4: 80a24012                 cmp     %o1, %l2
F0075AD8: 32800004                 bne,a   loc_F0075AE8
F0075ADC: d0024000                 ld      [%o1], %o0
F0075AE0: 10800006                 ba      loc_F0075AF8
F0075AE4: a0102000                 mov     0, %l0
F0075AE8: e4222004                 st      %l2, [%o0+4]
F0075AEC: d0024000                 ld      [%o1], %o0
F0075AF0: a0100009                 mov     %o1, %l0
F0075AF4: d0256150                 st      %o0, [%l5+0x150]
F0075AF8: 80a42000                 cmp     %l0, 0
F0075AFC: 22800017                 be,a    loc_F0075B58
F0075B00: 90156150                 or      %l5, 0x150, %o0
F0075B04: c0252168                 clr     [%l4+0x168]
F0075B08: 40008487                 call    _splx
F0075B0C: 90100011                 mov     %l1, %o0
F0075B10: 90100010                 mov     %l0, %o0
F0075B14: 7ffffdea                 call    _thread_dowait
F0075B18: 92102001                 mov     1, %o1
F0075B1C: 7ffffa24                 call    _thread_deallocate
F0075B20: 90100010                 mov     %l0, %o0
F0075B24: 40008419                 call    _splusclock
F0075B28: a0152168                 or      %l4, 0x168, %l0
F0075B2C: a2100008                 mov     %o0, %l1
F0075B30: d0040000                 ld      [%l0], %o0
F0075B34: 80a22000                 cmp     %o0, 0
F0075B38: 12bffffe                 bne     loc_F0075B30
F0075B3C: 01000000                 nop
F0075B40: 400084da                 call    _simple_lock_try
F0075B44: 90100010                 mov     %l0, %o0
F0075B48: 80a22000                 cmp     %o0, 0
F0075B4C: 02bffff9                 be      loc_F0075B30
F0075B50: d2056150                 ld      [%l5+0x150], %o1
F0075B54: 30bfffe0                 ba,a    loc_F0075AD4
F0075B58: 7fffec5f                 call    _assert_wait
F0075B5C: 92102000                 mov     0, %o1
F0075B60: c0252168                 clr     [%l4+0x168]
F0075B64: 40008470                 call    _splx
F0075B68: 90100011                 mov     %l1, %o0
F0075B6C: 113c01d6                 sethi   %hi(_reaper_thread_continue), %o0
F0075B70: 7fffeef4                 call    _thread_block_with_continuation
F0075B74: 9012228c                 bset    %lo(_reaper_thread_continue), %o0
F0075B78: 30bfffc9                 ba,a    loc_F0075A9C
