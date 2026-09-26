F0053B28: 9de3bf98                 save    %sp, -0x68, %sp
F0053B2C: a0062008                 add     %i0, 8, %l0
F0053B30: d0040000                 ld      [%l0], %o0
F0053B34: 80a22000                 cmp     %o0, 0
F0053B38: 12bffffe                 bne     loc_F0053B30
F0053B3C: 01000000                 nop
F0053B40: 40010cda                 call    _simple_lock_try
F0053B44: 90100010                 mov     %l0, %o0
F0053B48: 80a22000                 cmp     %o0, 0
F0053B4C: 02bffff9                 be      loc_F0053B30
F0053B50: 01000000                 nop
F0053B54: d006200c                 ld      [%i0+0xC], %o0
F0053B58: 80a22000                 cmp     %o0, 0
F0053B5C: 12800005                 bne     loc_F0053B70
F0053B60: 90100018                 mov     %i0, %o0
F0053B64: c0262008                 clr     [%i0+8]
F0053B68: 1080000e                 ba      locret_F0053BA0
F0053B6C: b0102010                 mov     0x10, %i0
F0053B70: 92100019                 mov     %i1, %o1
F0053B74: 7fffffd3                 call    _ipc_entry_get
F0053B78: 9410001a                 mov     %i2, %o2
F0053B7C: 80a22000                 cmp     %o0, 0
F0053B80: 22800008                 be,a    locret_F0053BA0
F0053B84: b0102000                 mov     0, %i0
F0053B88: 40000136                 call    _ipc_entry_grow_table
F0053B8C: 90100018                 mov     %i0, %o0
F0053B90: 80a22000                 cmp     %o0, 0
F0053B94: 22bffff1                 be,a    loc_F0053B58
F0053B98: d006200c                 ld      [%i0+0xC], %o0
F0053B9C: b0100008                 mov     %o0, %i0
F0053BA0: 81c7e008                 ret
F0053BA4: 81e80000                 restore
