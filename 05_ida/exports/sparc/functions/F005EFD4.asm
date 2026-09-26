F005EFD4: 9de3bf90                 save    %sp, -0x70, %sp
F005EFD8: 80a62000                 cmp     %i0, 0
F005EFDC: 12800004                 bne     loc_F005EFEC
F005EFE0: a2102000                 mov     0, %l1
F005EFE4: 10800048                 ba      locret_F005F104
F005EFE8: b0102016                 mov     0x16, %i0
F005EFEC: 273c04ef                 sethi   -0xFEC4400, %l3
F005EFF0: e0068000                 ld      [%i2], %l0
F005EFF4: 293c04d0                 sethi   -0xFECC000, %l4
F005EFF8: f006c000                 ld      [%i3], %i0
F005EFFC: 90100019                 mov     %i1, %o0
F005F000: 92100010                 mov     %l0, %o1
F005F004: 7fffe4af                 call    _ipc_marequest_info
F005F008: 94100018                 mov     %i0, %o2
F005F00C: a4100008                 mov     %o0, %l2
F005F010: 80a48018                 cmp     %l2, %i0
F005F014: 08800015                 bleu    loc_F005F068
F005F018: d0068000                 ld      [%i2], %o0
F005F01C: 80a40008                 cmp     %l0, %o0
F005F020: 02800005                 be      loc_F005F034
F005F024: d004e2f8                 ld      [%l3+0x2F8], %o0
F005F028: d207bff4                 ld      [%fp+var_C], %o1
F005F02C: 40009216                 call    _kmem_free
F005F030: 94100011                 mov     %l1, %o2
F005F034: 9207bff4                 add     %fp, var_C, %o1
F005F038: d60520d8                 ld      [%l4+0xD8], %o3
F005F03C: 952ca002                 sll     %l2, 2, %o2
F005F040: d004e2f8                 ld      [%l3+0x2F8], %o0
F005F044: 9402800b                 add     %o2, %o3, %o2
F005F048: a22a800b                 andn    %o2, %o3, %l1
F005F04C: 400091f9                 call    _kmem_alloc_pageable
F005F050: 94100011                 mov     %l1, %o2
F005F054: 80a22000                 cmp     %o0, 0
F005F058: 12800010                 bne     loc_F005F098
F005F05C: e007bff4                 ld      [%fp+var_C], %l0
F005F060: 10bfffe7                 ba      loc_F005EFFC
F005F064: b1346002                 srl     %l1, 2, %i0
F005F068: 80a40008                 cmp     %l0, %o0
F005F06C: 02800024                 be      loc_F005F0FC
F005F070: 80a4a000                 cmp     %l2, 0
F005F074: 1280000b                 bne     loc_F005F0A0
F005F078: 113c04d0                 sethi   -0xFECC000, %o0
F005F07C: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F080: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F084: d207bff4                 ld      [%fp+var_C], %o1
F005F088: 400091ff                 call    _kmem_free
F005F08C: 94100011                 mov     %l1, %o2
F005F090: 1080001c                 ba      loc_F005F100
F005F094: c026c000                 clr     [%i3]
F005F098: 1080001b                 ba      locret_F005F104
F005F09C: b0102006                 mov     6, %i0
F005F0A0: d20220d8                 ld      [%o0+0xD8], %o1
F005F0A4: 912ca002                 sll     %l2, 2, %o0
F005F0A8: 90020009                 add     %o0, %o1, %o0
F005F0AC: a02a0009                 andn    %o0, %o1, %l0
F005F0B0: 80a40011                 cmp     %l0, %l1
F005F0B4: 02800007                 be      loc_F005F0D0
F005F0B8: 94244010                 sub     %l1, %l0, %o2
F005F0BC: d207bff4                 ld      [%fp+var_C], %o1
F005F0C0: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F0C4: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F0C8: 400091ef                 call    _kmem_free
F005F0CC: 92024010                 add     %o1, %l0, %o1
F005F0D0: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F005F0D4: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F005F0D8: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F005F0DC: 96100010                 mov     %l0, %o3
F005F0E0: d207bff4                 ld      [%fp+var_C], %o1
F005F0E4: 98102001                 mov     1, %o4
F005F0E8: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F005F0EC: 40009c63                 call    _vm_move
F005F0F0: 9a07bff0                 add     %fp, var_10, %o5
F005F0F4: d007bff0                 ld      [%fp+var_10], %o0
F005F0F8: d0268000                 st      %o0, [%i2]
F005F0FC: e426c000                 st      %l2, [%i3]
F005F100: b0102000                 mov     0, %i0
F005F104: 81c7e008                 ret
F005F108: 81e80000                 restore
