F0054B68: 9de3bf98                 save    %sp, -0x68, %sp
F0054B6C: 113c04ef                 sethi   %hi(_ipc_port_multiple_lock_data), %o0
F0054B70: c0222308                 clr     [%o0+%lo(_ipc_port_multiple_lock_data)]
F0054B74: 113c04ef                 sethi   %hi(_ipc_port_timestamp_lock_data), %o0
F0054B78: c0222318                 clr     [%o0+%lo(_ipc_port_timestamp_lock_data)]
F0054B7C: 113c04ef                 sethi   %hi(_ipc_port_timestamp_data), %o0
F0054B80: c0222310                 clr     [%o0+%lo(_ipc_port_timestamp_data)]
F0054B84: 90102048                 mov     0x48, %o0 ! 'H'
F0054B88: 94102048                 mov     0x48, %o2 ! 'H'
F0054B8C: 96102000                 mov     0, %o3
F0054B90: 133c043c                 sethi   %hi(_ipc_space_max), %o1
F0054B94: 193c043c                 sethi   %hi(aIpcSpaces), %o4! "ipc spaces"
F0054B98: da0263ac                 ld      [%o1+%lo(_ipc_space_max)], %o5
F0054B9C: 981323c0                 bset    %lo(aIpcSpaces), %o4! "ipc spaces"
F0054BA0: 932b6003                 sll     %o5, 3, %o1
F0054BA4: 9202400d                 add     %o1, %o5, %o1
F0054BA8: 40008ce4                 call    _zinit
F0054BAC: 932a6003                 sll     %o1, 3, %o1
F0054BB0: 133c04ef                 sethi   %hi(_ipc_space_zone), %o1
F0054BB4: d0226340                 st      %o0, [%o1+%lo(_ipc_space_zone)]
F0054BB8: 92102000                 mov     0, %o1
F0054BBC: 94102000                 mov     0, %o2
F0054BC0: 96102001                 mov     1, %o3
F0054BC4: 400091cf                 call    _zchange
F0054BC8: 98102000                 mov     0, %o4
F0054BCC: 90102020                 mov     0x20, %o0 ! ' '
F0054BD0: 94102020                 mov     0x20, %o2 ! ' '
F0054BD4: 96102000                 mov     0, %o3
F0054BD8: 133c043c                 sethi   %hi(_ipc_tree_entry_max), %o1
F0054BDC: 193c043c                 sethi   %hi(aIpcTreeEntries), %o4! "ipc tree entries"
F0054BE0: d20263b0                 ld      [%o1+%lo(_ipc_tree_entry_max)], %o1
F0054BE4: 981323d0                 bset    %lo(aIpcTreeEntries), %o4! "ipc tree entries"
F0054BE8: 40008cd4                 call    _zinit
F0054BEC: 932a6005                 sll     %o1, 5, %o1
F0054BF0: 133c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o1
F0054BF4: d02262d8                 st      %o0, [%o1+%lo(_ipc_tree_entry_zone)]
F0054BF8: 92102000                 mov     0, %o1
F0054BFC: 94102000                 mov     0, %o2
F0054C00: 96102001                 mov     1, %o3
F0054C04: 400091bf                 call    _zchange
F0054C08: 98102000                 mov     0, %o4
F0054C0C: 90102050                 mov     0x50, %o0 ! 'P'
F0054C10: 94102050                 mov     0x50, %o2 ! 'P'
F0054C14: 96102000                 mov     0, %o3
F0054C18: 133c043c                 sethi   %hi(_ipc_port_max), %o1
F0054C1C: 193c043c                 sethi   %hi(aIpcPorts), %o4! "ipc ports"
F0054C20: da0263b4                 ld      [%o1+%lo(_ipc_port_max)], %o5
F0054C24: 981323e8                 bset    %lo(aIpcPorts), %o4! "ipc ports"
F0054C28: 932b6002                 sll     %o5, 2, %o1
F0054C2C: 9202400d                 add     %o1, %o5, %o1
F0054C30: 40008cc2                 call    _zinit
F0054C34: 932a6004                 sll     %o1, 4, %o1
F0054C38: 213c04ef                 sethi   %hi(_ipc_object_zones), %l0
F0054C3C: d0242300                 st      %o0, [%l0+%lo(_ipc_object_zones)]
F0054C40: 92102000                 mov     0, %o1
F0054C44: 94102000                 mov     0, %o2
F0054C48: 96102001                 mov     1, %o3
F0054C4C: 98102000                 mov     0, %o4
F0054C50: 400091ac                 call    _zchange
F0054C54: a0142300                 bset    %lo(_ipc_object_zones), %l0
F0054C58: 9010201c                 mov     0x1C, %o0
F0054C5C: 9410201c                 mov     0x1C, %o2
F0054C60: 96102000                 mov     0, %o3
F0054C64: 133c043c                 sethi   %hi(_ipc_pset_max), %o1
F0054C68: 193c043c                 sethi   %hi(aIpcPortSets), %o4! "ipc port sets"
F0054C6C: da0263b8                 ld      [%o1+%lo(_ipc_pset_max)], %o5
F0054C70: 981323f8                 bset    %lo(aIpcPortSets), %o4! "ipc port sets"
F0054C74: 932b6003                 sll     %o5, 3, %o1
F0054C78: 9222400d                 sub     %o1, %o5, %o1
F0054C7C: 40008caf                 call    _zinit
F0054C80: 932a6002                 sll     %o1, 2, %o1
F0054C84: d0242004                 st      %o0, [%l0+4]
F0054C88: 92102000                 mov     0, %o1
F0054C8C: 94102000                 mov     0, %o2
F0054C90: 96102001                 mov     1, %o3
F0054C94: 4000919b                 call    _zchange
F0054C98: 98102000                 mov     0, %o4
F0054C9C: 113c04ef                 sethi   %hi(_ipc_space_kernel), %o0
F0054CA0: 400024b9                 call    _ipc_space_create_special
F0054CA4: 90122330                 bset    %lo(_ipc_space_kernel), %o0
F0054CA8: 113c04ef                 sethi   %hi(_ipc_space_reply), %o0
F0054CAC: 400024b6                 call    _ipc_space_create_special
F0054CB0: 90122338                 bset    %lo(_ipc_space_reply), %o0
F0054CB4: 400027e1                 call    _ipc_table_init
F0054CB8: 01000000                 nop
F0054CBC: 400010b7                 call    _ipc_notify_init
F0054CC0: 01000000                 nop
F0054CC4: 7fffff48                 call    _ipc_hash_init
F0054CC8: 01000000                 nop
F0054CCC: 40000bf0                 call    _ipc_marequest_init
F0054CD0: 01000000                 nop
F0054CD4: 81c7e008                 ret
F0054CD8: 81e80000                 restore
