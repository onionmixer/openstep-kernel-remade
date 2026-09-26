F0066E54: 9de3bf98                 save    %sp, -0x68, %sp
F0066E58: a00620a8                 add     %i0, 0xA8, %l0
F0066E5C: d0040000                 ld      [%l0], %o0
F0066E60: 80a22000                 cmp     %o0, 0
F0066E64: 12bffffe                 bne     loc_F0066E5C
F0066E68: 01000000                 nop
F0066E6C: 4000c00f                 call    _simple_lock_try
F0066E70: 90100010                 mov     %l0, %o0
F0066E74: 80a22000                 cmp     %o0, 0
F0066E78: 02bffff9                 be      loc_F0066E5C
F0066E7C: 01000000                 nop
F0066E80: d00620ac                 ld      [%i0+0xAC], %o0
F0066E84: 80a22000                 cmp     %o0, 0
F0066E88: 02800004                 be      loc_F0066E98
F0066E8C: 92102000                 mov     0, %o1
F0066E90: 7ffffa64                 call    _ipc_kobject_set
F0066E94: 94102000                 mov     0, %o2
F0066E98: c02620a8                 clr     [%i0+0xA8]
F0066E9C: 81c7e008                 ret
F0066EA0: 81e80000                 restore
