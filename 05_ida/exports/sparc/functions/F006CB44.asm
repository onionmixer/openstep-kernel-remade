F006CB44: 9de3bf98                 save    %sp, -0x68, %sp
F006CB48: 113c04f0a0122210         set     _vm_info_lock_data, %l0
F006CB50: d0040000                 ld      [%l0], %o0
F006CB54: 80a22000                 cmp     %o0, 0
F006CB58: 12bffffe                 bne     loc_F006CB50
F006CB5C: 01000000                 nop
F006CB60: 4000a8d2                 call    _simple_lock_try
F006CB64: 90100010                 mov     %l0, %o0
F006CB68: 80a22000                 cmp     %o0, 0
F006CB6C: 02bffff9                 be      loc_F006CB50
F006CB70: 153c043f                 sethi   %hi(_vm_info_version), %o2
F006CB74: 113c04f0                 sethi   %hi(_vm_info_queue), %o0
F006CB78: e2022218                 ld      [%o0+%lo(_vm_info_queue)], %l1
F006CB7C: 92122218                 or      %o0, %lo(_vm_info_queue), %o1
F006CB80: 80a44009                 cmp     %l1, %o1
F006CB84: 02800021                 be      loc_F006CC08
F006CB88: e402a118                 ld      [%o2+%lo(_vm_info_version)], %l2
F006CB8C: 273c04f0                 sethi   -0xFEC4000, %l3
F006CB90: ac10000a                 mov     %o2, %l6
F006CB94: aa100008                 mov     %o0, %l5
F006CB98: a8100009                 mov     %o1, %l4
F006CB9C: d0546004                 ldsh    [%l1+4], %o0
F006CBA0: 80a22000                 cmp     %o0, 0
F006CBA4: 12800010                 bne     loc_F006CBE4
F006CBA8: d005a118                 ld      [%l6+0x118], %o0
F006CBAC: c024e210                 clr     [%l3+0x210]
F006CBB0: 90100011                 mov     %l1, %o0
F006CBB4: 7fffff8b                 call    _mfs_memfree
F006CBB8: 92102001                 mov     1, %o1
F006CBBC: a014e210                 or      %l3, 0x210, %l0
F006CBC0: d0040000                 ld      [%l0], %o0
F006CBC4: 80a22000                 cmp     %o0, 0
F006CBC8: 12bffffe                 bne     loc_F006CBC0
F006CBCC: 01000000                 nop
F006CBD0: 4000a8b6                 call    _simple_lock_try
F006CBD4: 90100010                 mov     %l0, %o0
F006CBD8: 80a22000                 cmp     %o0, 0
F006CBDC: 02bffff9                 be      loc_F006CBC0
F006CBE0: d005a118                 ld      [%l6+0x118], %o0
F006CBE4: 80a48008                 cmp     %l2, %o0
F006CBE8: 32800004                 bne,a   loc_F006CBF8
F006CBEC: e2056218                 ld      [%l5+0x218], %l1
F006CBF0: 10800003                 ba      loc_F006CBFC
F006CBF4: e2046028                 ld      [%l1+0x28], %l1
F006CBF8: a4100008                 mov     %o0, %l2
F006CBFC: 80a44014                 cmp     %l1, %l4
F006CC00: 32bfffe8                 bne,a   loc_F006CBA0
F006CC04: d0546004                 ldsh    [%l1+4], %o0
F006CC08: 113c04f0                 sethi   %hi(_vm_info_lock_data), %o0
F006CC0C: c0222210                 clr     [%o0+%lo(_vm_info_lock_data)]
F006CC10: 81c7e008                 ret
F006CC14: 81e80000                 restore
