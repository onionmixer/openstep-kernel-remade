F005B744: 9de3bf98                 save    %sp, -0x68, %sp
F005B748: c0266030                 clr     [%i1+0x30]
F005B74C: d0062004                 ld      [%i0+4], %o0
F005B750: 90023fff                 inc     -1, %o0
F005B754: d0262004                 st      %o0, [%i0+4]
F005B758: a0066040                 add     %i1, 0x40, %l0 ! '@'
F005B75C: d0040000                 ld      [%l0], %o0
F005B760: 80a22000                 cmp     %o0, 0
F005B764: 12bffffe                 bne     loc_F005B75C
F005B768: 01000000                 nop
F005B76C: 4000edcf                 call    _simple_lock_try
F005B770: 90100010                 mov     %l0, %o0
F005B774: 80a22000                 cmp     %o0, 0
F005B778: 02bffff9                 be      loc_F005B75C
F005B77C: 01000000                 nop
F005B780: a0062010                 add     %i0, 0x10, %l0
F005B784: d0040000                 ld      [%l0], %o0
F005B788: 80a22000                 cmp     %o0, 0
F005B78C: 12bffffe                 bne     loc_F005B784
F005B790: 01000000                 nop
F005B794: 4000edc5                 call    _simple_lock_try
F005B798: 90100010                 mov     %l0, %o0
F005B79C: 80a22000                 cmp     %o0, 0
F005B7A0: 02bffff9                 be      loc_F005B784
F005B7A4: 90066040                 add     %i1, 0x40, %o0 ! '@'
F005B7A8: 92062010                 add     %i0, 0x10, %o1
F005B7AC: 7ffff2f9                 call    _ipc_mqueue_move
F005B7B0: 94100019                 mov     %i1, %o2
F005B7B4: c0262010                 clr     [%i0+0x10]
F005B7B8: c0266040                 clr     [%i1+0x40]
F005B7BC: 81c7e008                 ret
F005B7C0: 81e80000                 restore
