F0074AC8: 9de3bf98                 save    %sp, -0x68, %sp
F0074ACC: 7fffc8e2                 call    _ipc_thread_disable
F0074AD0: 90100018                 mov     %i0, %o0
F0074AD4: 4000882d                 call    _splusclock
F0074AD8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074ADC: a2100008                 mov     %o0, %l1
F0074AE0: d0040000                 ld      [%l0], %o0
F0074AE4: 80a22000                 cmp     %o0, 0
F0074AE8: 12bffffe                 bne     loc_F0074AE0
F0074AEC: 01000000                 nop
F0074AF0: 400088ee                 call    _simple_lock_try
F0074AF4: 90100010                 mov     %l0, %o0
F0074AF8: 80a22000                 cmp     %o0, 0
F0074AFC: 02bffff9                 be      loc_F0074AE0
F0074B00: 01000000                 nop
F0074B04: c0262020                 clr     [%i0+0x20]
F0074B08: e0062188                 ld      [%i0+0x188], %l0
F0074B0C: 90100011                 mov     %l1, %o0
F0074B10: 40008885                 call    _splx
F0074B14: c0262188                 clr     [%i0+0x188]
F0074B18: 90100018                 mov     %i0, %o0
F0074B1C: 4000000b                 call    _thread_halt
F0074B20: 92102001                 mov     1, %o1
F0074B24: 7fffc8e0                 call    _ipc_thread_terminate
F0074B28: 90100018                 mov     %i0, %o0
F0074B2C: 80a42000                 cmp     %l0, 0
F0074B30: 02800004                 be      locret_F0074B40
F0074B34: 01000000                 nop
F0074B38: 7ffffe1d                 call    _thread_deallocate
F0074B3C: 90100018                 mov     %i0, %o0
F0074B40: 81c7e008                 ret
F0074B44: 81e80000                 restore
