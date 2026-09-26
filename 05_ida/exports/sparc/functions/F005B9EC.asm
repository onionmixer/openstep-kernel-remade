F005B9EC: 9de3bf98                 save    %sp, -0x68, %sp
F005B9F0: a0062010                 add     %i0, 0x10, %l0
F005B9F4: d2062008                 ld      [%i0+8], %o1
F005B9F8: 11200000                 sethi   0x80000000, %o0
F005B9FC: 902a4008                 andn    %o1, %o0, %o0
F005BA00: d0262008                 st      %o0, [%i0+8]
F005BA04: d0040000                 ld      [%l0], %o0
F005BA08: 80a22000                 cmp     %o0, 0
F005BA0C: 12bffffe                 bne     loc_F005BA04
F005BA10: 01000000                 nop
F005BA14: 4000ed25                 call    _simple_lock_try
F005BA18: 90100010                 mov     %l0, %o0
F005BA1C: 80a22000                 cmp     %o0, 0
F005BA20: 02bffff9                 be      loc_F005BA04
F005BA24: 90062010                 add     %i0, 0x10, %o0
F005BA28: 13040010                 sethi   0x10004000, %o1
F005BA2C: 7ffff289                 call    _ipc_mqueue_changed
F005BA30: 92126009                 bset    9, %o1
F005BA34: c0262010                 clr     [%i0+0x10]
F005BA38: d0062004                 ld      [%i0+4], %o0
F005BA3C: 90023fff                 inc     -1, %o0
F005BA40: d0262004                 st      %o0, [%i0+4]
F005BA44: c0260000                 clr     [%i0]
F005BA48: 80a22000                 cmp     %o0, 0
F005BA4C: 1280000a                 bne     locret_F005BA74
F005BA50: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005BA54: d0062008                 ld      [%i0+8], %o0
F005BA58: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005BA5C: 912a2001                 sll     %o0, 1, %o0
F005BA60: 91322011                 srl     %o0, 17, %o0
F005BA64: 912a2002                 sll     %o0, 2, %o0
F005BA68: d0020009                 ld      [%o0+%o1], %o0
F005BA6C: 400075d9                 call    _zfree
F005BA70: 92100018                 mov     %i0, %o1
F005BA74: 81c7e008                 ret
F005BA78: 81e80000                 restore
