F005BDB4: 9de3bf98                 save    %sp, -0x68, %sp
F005BDB8: e4068000                 ld      [%i2], %l2
F005BDBC: 110007c0                 sethi   0x1F0000, %o0
F005BDC0: 928c8008                 andcc   %l2, %o0, %o1
F005BDC4: 02800035                 be      loc_F005BE98
F005BDC8: 11001000                 sethi   0x400000, %o0
F005BDCC: 808c8008                 btst    %o0, %l2
F005BDD0: 0280002f                 be      loc_F005BE8C
F005BDD4: a2100009                 mov     %o1, %l1
F005BDD8: 11000040                 sethi   0x10000, %o0
F005BDDC: 80a44008                 cmp     %l1, %o0
F005BDE0: 02800005                 be      loc_F005BDF4
F005BDE4: 11000100                 sethi   0x40000, %o0
F005BDE8: 80a44008                 cmp     %l1, %o0
F005BDEC: 12800028                 bne     loc_F005BE8C
F005BDF0: 01000000                 nop
F005BDF4: e006a004                 ld      [%i2+4], %l0
F005BDF8: d0040000                 ld      [%l0], %o0
F005BDFC: 80a22000                 cmp     %o0, 0
F005BE00: 12bffffe                 bne     loc_F005BDF8
F005BE04: 01000000                 nop
F005BE08: 4000ec28                 call    _simple_lock_try
F005BE0C: 90100010                 mov     %l0, %o0
F005BE10: 80a22000                 cmp     %o0, 0
F005BE14: 02bffff9                 be      loc_F005BDF8
F005BE18: 01000000                 nop
F005BE1C: d0042008                 ld      [%l0+8], %o0
F005BE20: c0240000                 clr     [%l0]
F005BE24: 80a22000                 cmp     %o0, 0
F005BE28: 06800019                 bl      loc_F005BE8C
F005BE2C: 11000040                 sethi   0x10000, %o0
F005BE30: 80a44008                 cmp     %l1, %o0
F005BE34: 1280000c                 bne     loc_F005BE64
F005BE38: 11000800                 sethi   0x200000, %o0
F005BE3C: 808c8008                 btst    %o0, %l2
F005BE40: 02800004                 be      loc_F005BE50
F005BE44: 90100018                 mov     %i0, %o0
F005BE48: 7ffff04a                 call    _ipc_marequest_cancel
F005BE4C: 92100019                 mov     %i1, %o1
F005BE50: 90100018                 mov     %i0, %o0
F005BE54: 92100010                 mov     %l0, %o1
F005BE58: 94100019                 mov     %i1, %o2
F005BE5C: 7fffe1d5                 call    _ipc_hash_delete
F005BE60: 9610001a                 mov     %i2, %o3
F005BE64: 7ffff603                 call    _ipc_object_release
F005BE68: 90100010                 mov     %l0, %o0
F005BE6C: c026a008                 clr     [%i2+8]
F005BE70: c026a004                 clr     [%i2+4]
F005BE74: b0102000                 mov     0, %i0
F005BE78: d0068000                 ld      [%i2], %o0
F005BE7C: 133fe000                 sethi   -0x800000, %o1
F005BE80: 900a0009                 and     %o0, %o1, %o0
F005BE84: 10800006                 ba      locret_F005BE9C
F005BE88: d0268000                 st      %o0, [%i2]
F005BE8C: c0262008                 clr     [%i0+8]
F005BE90: 10800003                 ba      locret_F005BE9C
F005BE94: b0102001                 mov     1, %i0
F005BE98: b0102000                 mov     0, %i0
F005BE9C: 81c7e008                 ret
F005BEA0: 81e80000                 restore
