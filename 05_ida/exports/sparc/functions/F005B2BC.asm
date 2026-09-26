F005B2BC: 9de3bf98                 save    %sp, -0x68, %sp
F005B2C0: d0060000                 ld      [%i0], %o0
F005B2C4: 80a22000                 cmp     %o0, 0
F005B2C8: 12bffffe                 bne     loc_F005B2C0
F005B2CC: 01000000                 nop
F005B2D0: 4000eef6                 call    _simple_lock_try
F005B2D4: 90100018                 mov     %i0, %o0
F005B2D8: 80a22000                 cmp     %o0, 0
F005B2DC: 02bffff9                 be      loc_F005B2C0
F005B2E0: 01000000                 nop
F005B2E4: e006200c                 ld      [%i0+0xC], %l0
F005B2E8: 7ffffe2b                 call    _ipc_port_destroy
F005B2EC: 90100018                 mov     %i0, %o0
F005B2F0: 80a42000                 cmp     %l0, 0
F005B2F4: 02800004                 be      locret_F005B304
F005B2F8: 01000000                 nop
F005B2FC: 7ffff8dd                 call    _ipc_object_release
F005B300: 90100010                 mov     %l0, %o0
F005B304: 81c7e008                 ret
F005B308: 81e80000                 restore
