F0067B58: 9de3bf98                 save    %sp, -0x68, %sp
F0067B5C: a00620a8                 add     %i0, 0xA8, %l0
F0067B60: d0040000                 ld      [%l0], %o0
F0067B64: 80a22000                 cmp     %o0, 0
F0067B68: 12bffffe                 bne     loc_F0067B60
F0067B6C: 01000000                 nop
F0067B70: 4000bcce                 call    _simple_lock_try
F0067B74: 90100010                 mov     %l0, %o0
F0067B78: 80a22000                 cmp     %o0, 0
F0067B7C: 02bffff9                 be      loc_F0067B60
F0067B80: 01000000                 nop
F0067B84: d00620ac                 ld      [%i0+0xAC], %o0
F0067B88: 80a22000                 cmp     %o0, 0
F0067B8C: 02800005                 be      loc_F0067BA0
F0067B90: a0102000                 mov     0, %l0
F0067B94: 7fffcd14                 call    _ipc_port_make_send
F0067B98: 01000000                 nop
F0067B9C: a0100008                 mov     %o0, %l0
F0067BA0: c02620a8                 clr     [%i0+0xA8]
F0067BA4: 40003202                 call    _thread_deallocate
F0067BA8: 90100018                 mov     %i0, %o0
F0067BAC: 81c7e008                 ret
F0067BB0: 91e80010                 restore %g0, %l0, %o0
