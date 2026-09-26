F00549E4: 9de3bf98                 save    %sp, -0x68, %sp
F00549E8: 133c04ef                 sethi   %hi(_ipc_hash_global_size), %o1
F00549EC: d00262e8                 ld      [%o1+%lo(_ipc_hash_global_size)], %o0
F00549F0: 80a22000                 cmp     %o0, 0
F00549F4: 1280000b                 bne     loc_F0054A20
F00549F8: 193c04ef                 sethi   -0xFEC4400, %o4
F00549FC: 113c043c                 sethi   %hi(_ipc_tree_entry_max), %o0
F0054A00: d00223b0                 ld      [%o0+%lo(_ipc_tree_entry_max)], %o0
F0054A04: 913a2008                 sra     %o0, 8, %o0
F0054A08: 80a2201f                 cmp     %o0, 0x1F
F0054A0C: 18800005                 bgu     loc_F0054A20
F0054A10: d02262e8                 st      %o0, [%o1+%lo(_ipc_hash_global_size)]
F0054A14: 90102020                 mov     0x20, %o0 ! ' '
F0054A18: d02262e8                 st      %o0, [%o1+%lo(_ipc_hash_global_size)]
F0054A1C: 193c04ef                 sethi   -0xFEC4400, %o4
F0054A20: d00322e8                 ld      [%o4+0x2E8], %o0
F0054A24: 173c04ef                 sethi   %hi(_ipc_hash_global_mask), %o3
F0054A28: 92023fff                 add     %o0, -1, %o1
F0054A2C: 808a0009                 btst    %o1, %o0
F0054A30: 0280000d                 be      loc_F0054A64
F0054A34: d222e2e0                 st      %o1, [%o3+%lo(_ipc_hash_global_mask)]
F0054A38: 94102001                 mov     1, %o2
F0054A3C: 10800005                 ba      loc_F0054A50
F0054A40: 90126001                 or      %o1, 1, %o0
F0054A44: d002e2e0                 ld      [%o3+0x2E0], %o0
F0054A48: 952aa001                 sll     %o2, 1, %o2
F0054A4C: 9012000a                 bset    %o2, %o0
F0054A50: d022e2e0                 st      %o0, [%o3+0x2E0]
F0054A54: 92022001                 add     %o0, 1, %o1
F0054A58: 808a4008                 btst    %o0, %o1
F0054A5C: 12bffffa                 bne     loc_F0054A44
F0054A60: d22322e8                 st      %o1, [%o4+0x2E8]
F0054A64: 213c04ef                 sethi   %hi(_ipc_hash_global_size), %l0
F0054A68: d00422e8                 ld      [%l0+%lo(_ipc_hash_global_size)], %o0
F0054A6C: 40004d81                 call    _kalloc
F0054A70: 912a2003                 sll     %o0, 3, %o0
F0054A74: 94100008                 mov     %o0, %o2
F0054A78: 113c04ef                 sethi   %hi(_ipc_hash_global_table), %o0
F0054A7C: d42222f0                 st      %o2, [%o0+%lo(_ipc_hash_global_table)]
F0054A80: d00422e8                 ld      [%l0+%lo(_ipc_hash_global_size)], %o0
F0054A84: 92102000                 mov     0, %o1
F0054A88: 80a24008                 cmp     %o1, %o0
F0054A8C: 1a80000a                 bcc     locret_F0054AB4
F0054A90: 98100008                 mov     %o0, %o4
F0054A94: 9610000a                 mov     %o2, %o3
F0054A98: 912a6003                 sll     %o1, 3, %o0
F0054A9C: c022c008                 clr     [%o3+%o0]
F0054AA0: c022a004                 clr     [%o2+4]
F0054AA4: 92026001                 inc     %o1
F0054AA8: 80a2400c                 cmp     %o1, %o4
F0054AAC: 0abffffb                 bcs     loc_F0054A98
F0054AB0: 9402a008                 inc     8, %o2
F0054AB4: 81c7e008                 ret
F0054AB8: 81e80000                 restore
