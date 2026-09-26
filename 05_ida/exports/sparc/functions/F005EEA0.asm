F005EEA0: 9de3bf90                 save    %sp, -0x70, %sp
F005EEA4: 80a62000                 cmp     %i0, 0
F005EEA8: 12800004                 bne     loc_F005EEB8
F005EEAC: a2102000                 mov     0, %l1
F005EEB0: 10800047                 ba      locret_F005EFCC
F005EEB4: b0102016                 mov     0x16, %i0
F005EEB8: 273c04ef                 sethi   -0xFEC4400, %l3
F005EEBC: e0064000                 ld      [%i1], %l0
F005EEC0: 293c04d0                 sethi   -0xFECC000, %l4
F005EEC4: f0068000                 ld      [%i2], %i0
F005EEC8: 90100010                 mov     %l0, %o0
F005EECC: 7fffd6fc                 call    _ipc_hash_info
F005EED0: 92100018                 mov     %i0, %o1
F005EED4: a4100008                 mov     %o0, %l2
F005EED8: 80a48018                 cmp     %l2, %i0
F005EEDC: 08800015                 bleu    loc_F005EF30
F005EEE0: d0064000                 ld      [%i1], %o0
F005EEE4: 80a40008                 cmp     %l0, %o0
F005EEE8: 02800005                 be      loc_F005EEFC
F005EEEC: d004e2f8                 ld      [%l3+0x2F8], %o0
F005EEF0: d207bff4                 ld      [%fp+var_C], %o1
F005EEF4: 40009264                 call    _kmem_free
F005EEF8: 94100011                 mov     %l1, %o2
F005EEFC: 9207bff4                 add     %fp, var_C, %o1
F005EF00: d60520d8                 ld      [%l4+0xD8], %o3
F005EF04: 952ca002                 sll     %l2, 2, %o2
F005EF08: d004e2f8                 ld      [%l3+0x2F8], %o0
F005EF0C: 9402800b                 add     %o2, %o3, %o2
F005EF10: a22a800b                 andn    %o2, %o3, %l1
F005EF14: 40009247                 call    _kmem_alloc_pageable
F005EF18: 94100011                 mov     %l1, %o2
F005EF1C: 80a22000                 cmp     %o0, 0
F005EF20: 12800010                 bne     loc_F005EF60
F005EF24: e007bff4                 ld      [%fp+var_C], %l0
F005EF28: 10bfffe8                 ba      loc_F005EEC8
F005EF2C: b1346002                 srl     %l1, 2, %i0
F005EF30: 80a40008                 cmp     %l0, %o0
F005EF34: 02800024                 be      loc_F005EFC4
F005EF38: 80a4a000                 cmp     %l2, 0
F005EF3C: 1280000b                 bne     loc_F005EF68
F005EF40: 113c04d0                 sethi   -0xFECC000, %o0
F005EF44: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005EF48: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005EF4C: d207bff4                 ld      [%fp+var_C], %o1
F005EF50: 4000924d                 call    _kmem_free
F005EF54: 94100011                 mov     %l1, %o2
F005EF58: 1080001c                 ba      loc_F005EFC8
F005EF5C: c0268000                 clr     [%i2]
F005EF60: 1080001b                 ba      locret_F005EFCC
F005EF64: b0102006                 mov     6, %i0
F005EF68: d20220d8                 ld      [%o0+0xD8], %o1
F005EF6C: 912ca002                 sll     %l2, 2, %o0
F005EF70: 90020009                 add     %o0, %o1, %o0
F005EF74: a02a0009                 andn    %o0, %o1, %l0
F005EF78: 80a40011                 cmp     %l0, %l1
F005EF7C: 02800007                 be      loc_F005EF98
F005EF80: 94244010                 sub     %l1, %l0, %o2
F005EF84: d207bff4                 ld      [%fp+var_C], %o1
F005EF88: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005EF8C: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005EF90: 4000923d                 call    _kmem_free
F005EF94: 92024010                 add     %o1, %l0, %o1
F005EF98: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005EF9C: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F005EFA0: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005EFA4: 96100010                 mov     %l0, %o3
F005EFA8: d207bff4                 ld      [%fp+var_C], %o1
F005EFAC: 98102001                 mov     1, %o4
F005EFB0: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F005EFB4: 40009cb1                 call    _vm_move
F005EFB8: 9a07bff0                 add     %fp, var_10, %o5
F005EFBC: d007bff0                 ld      [%fp+var_10], %o0
F005EFC0: d0264000                 st      %o0, [%i1]
F005EFC4: e4268000                 st      %l2, [%i2]
F005EFC8: b0102000                 mov     0, %i0
F005EFCC: 81c7e008                 ret
F005EFD0: 81e80000                 restore
