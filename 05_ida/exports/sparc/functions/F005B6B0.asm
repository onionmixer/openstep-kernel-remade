F005B6B0: 9de3bf98                 save    %sp, -0x68, %sp
F005B6B4: f0266030                 st      %i0, [%i1+0x30]
F005B6B8: d0062004                 ld      [%i0+4], %o0
F005B6BC: 90022001                 inc     %o0
F005B6C0: d0262004                 st      %o0, [%i0+4]
F005B6C4: a0066040                 add     %i1, 0x40, %l0 ! '@'
F005B6C8: d0040000                 ld      [%l0], %o0
F005B6CC: 80a22000                 cmp     %o0, 0
F005B6D0: 12bffffe                 bne     loc_F005B6C8
F005B6D4: 01000000                 nop
F005B6D8: 4000edf4                 call    _simple_lock_try
F005B6DC: 90100010                 mov     %l0, %o0
F005B6E0: 80a22000                 cmp     %o0, 0
F005B6E4: 02bffff9                 be      loc_F005B6C8
F005B6E8: 01000000                 nop
F005B6EC: a0062010                 add     %i0, 0x10, %l0
F005B6F0: d0040000                 ld      [%l0], %o0
F005B6F4: 80a22000                 cmp     %o0, 0
F005B6F8: 12bffffe                 bne     loc_F005B6F0
F005B6FC: 01000000                 nop
F005B700: 4000edea                 call    _simple_lock_try
F005B704: 90100010                 mov     %l0, %o0
F005B708: 80a22000                 cmp     %o0, 0
F005B70C: 02bffff9                 be      loc_F005B6F0
F005B710: 90062010                 add     %i0, 0x10, %o0
F005B714: a0066040                 add     %i1, 0x40, %l0 ! '@'
F005B718: 92100010                 mov     %l0, %o1
F005B71C: 7ffff31d                 call    _ipc_mqueue_move
F005B720: 94100019                 mov     %i1, %o2
F005B724: c0262010                 clr     [%i0+0x10]
F005B728: 90100010                 mov     %l0, %o0
F005B72C: 13040010                 sethi   0x10004000, %o1
F005B730: 7ffff348                 call    _ipc_mqueue_changed
F005B734: 92126006                 bset    6, %o1
F005B738: c0266040                 clr     [%i1+0x40]
F005B73C: 81c7e008                 ret
F005B740: 81e80000                 restore
