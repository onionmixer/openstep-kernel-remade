F005EC38: 9de3bf98                 save    %sp, -0x68, %sp
F005EC3C: 213c043d                 sethi   %hi(_ipc_table_entries_size), %l0
F005EC40: d00423e8                 ld      [%l0+%lo(_ipc_table_entries_size)], %o0
F005EC44: 4000250b                 call    _kalloc
F005EC48: 912a2002                 sll     %o0, 2, %o0
F005EC4C: 233c04f0                 sethi   %hi(_ipc_table_entries), %l1
F005EC50: d0246030                 st      %o0, [%l1+%lo(_ipc_table_entries)]
F005EC54: 94102004                 mov     4, %o2
F005EC58: d20423e8                 ld      [%l0+%lo(_ipc_table_entries_size)], %o1
F005EC5C: 96102010                 mov     0x10, %o3
F005EC60: 7fffffc2                 call    _ipc_table_fill
F005EC64: 92027fff                 inc     -1, %o1
F005EC68: d20423e8                 ld      [%l0+%lo(_ipc_table_entries_size)], %o1
F005EC6C: d4046030                 ld      [%l1+%lo(_ipc_table_entries)], %o2
F005EC70: 932a6002                 sll     %o1, 2, %o1
F005EC74: 213c043d                 sethi   %hi(_ipc_table_dnrequests_size), %l0
F005EC78: d00423ec                 ld      [%l0+%lo(_ipc_table_dnrequests_size)], %o0
F005EC7C: 9202400a                 add     %o1, %o2, %o1
F005EC80: d4027ff8                 ld      [%o1-8], %o2
F005EC84: 912a2002                 sll     %o0, 2, %o0
F005EC88: 400024fa                 call    _kalloc
F005EC8C: d4227ffc                 st      %o2, [%o1-4]
F005EC90: 233c04f0                 sethi   %hi(_ipc_table_dnrequests), %l1
F005EC94: d0246028                 st      %o0, [%l1+%lo(_ipc_table_dnrequests)]
F005EC98: 94102002                 mov     2, %o2
F005EC9C: d20423ec                 ld      [%l0+%lo(_ipc_table_dnrequests_size)], %o1
F005ECA0: 96102008                 mov     8, %o3
F005ECA4: 7fffffb1                 call    _ipc_table_fill
F005ECA8: 92027fff                 inc     -1, %o1
F005ECAC: d00423ec                 ld      [%l0+%lo(_ipc_table_dnrequests_size)], %o0
F005ECB0: d2046028                 ld      [%l1+%lo(_ipc_table_dnrequests)], %o1
F005ECB4: 912a2002                 sll     %o0, 2, %o0
F005ECB8: 90020009                 add     %o0, %o1, %o0
F005ECBC: c0223ffc                 clr     [%o0-4]
F005ECC0: 81c7e008                 ret
F005ECC4: 81e80000                 restore
