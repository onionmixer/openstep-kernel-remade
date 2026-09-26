F0066E04: 9de3bf98                 save    %sp, -0x68, %sp
F0066E08: a00620a8                 add     %i0, 0xA8, %l0
F0066E0C: d0040000                 ld      [%l0], %o0
F0066E10: 80a22000                 cmp     %o0, 0
F0066E14: 12bffffe                 bne     loc_F0066E0C
F0066E18: 01000000                 nop
F0066E1C: 4000c023                 call    _simple_lock_try
F0066E20: 90100010                 mov     %l0, %o0
F0066E24: 80a22000                 cmp     %o0, 0
F0066E28: 02bffff9                 be      loc_F0066E0C
F0066E2C: 01000000                 nop
F0066E30: d00620ac                 ld      [%i0+0xAC], %o0
F0066E34: 80a22000                 cmp     %o0, 0
F0066E38: 02800004                 be      loc_F0066E48
F0066E3C: 92100018                 mov     %i0, %o1
F0066E40: 7ffffa78                 call    _ipc_kobject_set
F0066E44: 94102001                 mov     1, %o2
F0066E48: c02620a8                 clr     [%i0+0xA8]
F0066E4C: 81c7e008                 ret
F0066E50: 81e80000                 restore
