F005BAF4: 9de3bf98                 save    %sp, -0x68, %sp
F005BAF8: d0064000                 ld      [%i1], %o0
F005BAFC: 80a22000                 cmp     %o0, 0
F005BB00: 12bffffe                 bne     loc_F005BAF8
F005BB04: 01000000                 nop
F005BB08: 4000ece8                 call    _simple_lock_try
F005BB0C: 90100019                 mov     %i1, %o0
F005BB10: 80a22000                 cmp     %o0, 0
F005BB14: 02bffff9                 be      loc_F005BAF8
F005BB18: 01000000                 nop
F005BB1C: d0066008                 ld      [%i1+8], %o0
F005BB20: 80a22000                 cmp     %o0, 0
F005BB24: 16800013                 bge     loc_F005BB70
F005BB28: 01000000                 nop
F005BB2C: d006600c                 ld      [%i1+0xC], %o0
F005BB30: 80a20018                 cmp     %o0, %i0
F005BB34: 12800008                 bne     loc_F005BB54
F005BB38: 90100018                 mov     %i0, %o0
F005BB3C: e0066010                 ld      [%i1+0x10], %l0
F005BB40: 7fffdfbf                 call    _ipc_entry_lookup
F005BB44: 92100010                 mov     %l0, %o1
F005BB48: e0268000                 st      %l0, [%i2]
F005BB4C: 1080000c                 ba      loc_F005BB7C
F005BB50: d026c000                 st      %o0, [%i3]
F005BB54: 92100019                 mov     %i1, %o1
F005BB58: 9410001a                 mov     %i2, %o2
F005BB5C: 7fffe269                 call    _ipc_hash_lookup
F005BB60: 9610001b                 mov     %i3, %o3
F005BB64: 80a22000                 cmp     %o0, 0
F005BB68: 12800006                 bne     locret_F005BB80
F005BB6C: b0102001                 mov     1, %i0
F005BB70: c0264000                 clr     [%i1]
F005BB74: 10800003                 ba      locret_F005BB80
F005BB78: b0102000                 mov     0, %i0
F005BB7C: b0102001                 mov     1, %i0
F005BB80: 81c7e008                 ret
F005BB84: 81e80000                 restore
