F005A10C: 9de3bf90                 save    %sp, -0x70, %sp
F005A110: 90100018                 mov     %i0, %o0
F005A114: 92100019                 mov     %i1, %o1
F005A118: 40000659                 call    _ipc_right_lookup_write
F005A11C: 9407bff4                 add     %fp, var_C, %o2
F005A120: 80a22000                 cmp     %o0, 0
F005A124: 12800008                 bne     locret_F005A144
F005A128: 92100019                 mov     %i1, %o1
F005A12C: 90100018                 mov     %i0, %o0
F005A130: d407bff4                 ld      [%fp+var_C], %o2
F005A134: 9610001a                 mov     %i2, %o3
F005A138: 9810001b                 mov     %i3, %o4
F005A13C: 40000dd1                 call    _ipc_right_copyin_compat
F005A140: 9a10001c                 mov     %i4, %o5
F005A144: 81c7e008                 ret
F005A148: 91e80008                 restore %g0, %o0, %o0
