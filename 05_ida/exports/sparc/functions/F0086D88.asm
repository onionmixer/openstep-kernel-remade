F0086D88: 9de3bf98                 save    %sp, -0x68, %sp
F0086D8C: 113c04f5a0122000         set     _vm_cache_lock, %l0
F0086D94: d0040000                 ld      [%l0], %o0
F0086D98: 80a22000                 cmp     %o0, 0
F0086D9C: 12bffffe                 bne     loc_F0086D94
F0086DA0: 01000000                 nop
F0086DA4: 40004041                 call    _simple_lock_try
F0086DA8: 90100010                 mov     %l0, %o0
F0086DAC: 80a22000                 cmp     %o0, 0
F0086DB0: 02bffff9                 be      loc_F0086D94
F0086DB4: 173c04f5                 sethi   %hi(_vm_object_cached), %o3
F0086DB8: d202e010                 ld      [%o3+%lo(_vm_object_cached)], %o1
F0086DBC: 153c04f5                 sethi   %hi(_vm_cache_max), %o2
F0086DC0: d002a008                 ld      [%o2+%lo(_vm_cache_max)], %o0
F0086DC4: 80a24008                 cmp     %o1, %o0
F0086DC8: 04800023                 ble     loc_F0086E54
F0086DCC: 113c04f5                 sethi   -0xFEC2C00, %o0
F0086DD0: 2d3c04f5                 sethi   %hi(_vm_object_cached_list), %l6
F0086DD4: 233c04f5aa146000         set     _vm_cache_lock, %l5
F0086DDC: 293c0446                 sethi   -0xFEEE800, %l4
F0086DE0: a610000b                 mov     %o3, %l3
F0086DE4: a410000a                 mov     %o2, %l2
F0086DE8: e005a018                 ld      [%l6+%lo(_vm_object_cached_list)], %l0
F0086DEC: c0246000                 clr     [%l1]
F0086DF0: 4000015a                 call    _vm_object_lookup
F0086DF4: d0042028                 ld      [%l0+0x28], %o0
F0086DF8: 80a40008                 cmp     %l0, %o0
F0086DFC: 02800005                 be      loc_F0086E10
F0086E00: 90100010                 mov     %l0, %o0! char *
F0086E04: 7ffe38db                 call    _panic
F0086E08: 901523c0                 or      %l4, 0x3C0, %o0
F0086E0C: 90100010                 mov     %l0, %o0
F0086E10: 40000014                 call    _vm_object_cache_object
F0086E14: 92102000                 mov     0, %o1
F0086E18: a0100015                 mov     %l5, %l0
F0086E1C: d0040000                 ld      [%l0], %o0
F0086E20: 80a22000                 cmp     %o0, 0
F0086E24: 12bffffe                 bne     loc_F0086E1C
F0086E28: 01000000                 nop
F0086E2C: 4000401f                 call    _simple_lock_try
F0086E30: 90100010                 mov     %l0, %o0
F0086E34: 80a22000                 cmp     %o0, 0
F0086E38: 02bffff9                 be      loc_F0086E1C
F0086E3C: d004a008                 ld      [%l2+8], %o0
F0086E40: d204e010                 ld      [%l3+0x10], %o1
F0086E44: 80a24008                 cmp     %o1, %o0
F0086E48: 34bfffe9                 bg,a    loc_F0086DEC
F0086E4C: e005a018                 ld      [%l6+0x18], %l0
F0086E50: 113c04f5                 sethi   -0xFEC2C00, %o0
F0086E54: c0222000                 clr     [%o0]
F0086E58: 81c7e008                 ret
F0086E5C: 81e80000                 restore
