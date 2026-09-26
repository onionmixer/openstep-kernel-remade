F0086E60: 9de3bf98                 save    %sp, -0x68, %sp
F0086E64: 80a62000                 cmp     %i0, 0
F0086E68: 12800004                 bne     loc_F0086E78
F0086E6C: 113c04f5                 sethi   -0xFEC2C00, %o0
F0086E70: 10800023                 ba      locret_F0086EFC
F0086E74: b0102004                 mov     4, %i0
F0086E78: a0122000                 or      %o0, 0, %l0
F0086E7C: d0040000                 ld      [%l0], %o0
F0086E80: 80a22000                 cmp     %o0, 0
F0086E84: 12bffffe                 bne     loc_F0086E7C
F0086E88: 01000000                 nop
F0086E8C: 40004007                 call    _simple_lock_try
F0086E90: 90100010                 mov     %l0, %o0
F0086E94: 80a22000                 cmp     %o0, 0
F0086E98: 02bffff9                 be      loc_F0086E7C
F0086E9C: 01000000                 nop
F0086EA0: a0062010                 add     %i0, 0x10, %l0
F0086EA4: d0040000                 ld      [%l0], %o0
F0086EA8: 80a22000                 cmp     %o0, 0
F0086EAC: 12bffffe                 bne     loc_F0086EA4
F0086EB0: 01000000                 nop
F0086EB4: 40003ffd                 call    _simple_lock_try
F0086EB8: 90100010                 mov     %l0, %o0
F0086EBC: 80a22000                 cmp     %o0, 0
F0086EC0: 02bffff9                 be      loc_F0086EA4
F0086EC4: 01000000                 nop
F0086EC8: c0262010                 clr     [%i0+0x10]
F0086ECC: 90100018                 mov     %i0, %o0
F0086ED0: d2062044                 ld      [%i0+0x44], %o1
F0086ED4: 15000004                 sethi   0x1000, %o2
F0086ED8: 942a400a                 andn    %o1, %o2, %o2
F0086EDC: 920e6001                 and     %i1, 1, %o1
F0086EE0: 932a600c                 sll     %o1, 12, %o1
F0086EE4: 94128009                 bset    %o1, %o2
F0086EE8: d4222044                 st      %o2, [%o0+0x44]
F0086EEC: 133c04f5                 sethi   %hi(_vm_cache_lock), %o1
F0086EF0: c0226000                 clr     [%o1+%lo(_vm_cache_lock)]
F0086EF4: 7ffffe71                 call    _vm_object_deallocate
F0086EF8: b0102000                 mov     0, %i0
F0086EFC: 81c7e008                 ret
F0086F00: 81e80000                 restore
