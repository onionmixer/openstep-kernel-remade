F0067AFC: 9de3bf98                 save    %sp, -0x68, %sp
F0067B00: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F0067B04: d0040000                 ld      [%l0], %o0
F0067B08: 80a22000                 cmp     %o0, 0
F0067B0C: 12bffffe                 bne     loc_F0067B04
F0067B10: 01000000                 nop
F0067B14: 4000bce5                 call    _simple_lock_try
F0067B18: 90100010                 mov     %l0, %o0
F0067B1C: 80a22000                 cmp     %o0, 0
F0067B20: 02bffff9                 be      loc_F0067B04
F0067B24: 01000000                 nop
F0067B28: d0062068                 ld      [%i0+0x68], %o0
F0067B2C: 80a22000                 cmp     %o0, 0
F0067B30: 02800005                 be      loc_F0067B44
F0067B34: a0102000                 mov     0, %l0
F0067B38: 7fffcd2b                 call    _ipc_port_make_send
F0067B3C: 01000000                 nop
F0067B40: a0100008                 mov     %o0, %l0
F0067B44: c0262064                 clr     [%i0+0x64]
F0067B48: 40002d58                 call    _task_deallocate
F0067B4C: 90100018                 mov     %i0, %o0
F0067B50: 81c7e008                 ret
F0067B54: 91e80010                 restore %g0, %l0, %o0
