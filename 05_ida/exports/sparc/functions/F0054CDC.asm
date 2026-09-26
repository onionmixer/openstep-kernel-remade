F0054CDC: 9de3bf90                 save    %sp, -0x70, %sp
F0054CE0: 90102000                 mov     0, %o0! target_task
F0054CE4: 92102000                 mov     0, %o1! ledgers
F0054CE8: 213c04ef                 sethi   %hi(_ipc_soft_task), %l0
F0054CEC: 4000787b                 call    _task_create
F0054CF0: 94142328                 or      %l0, %lo(_ipc_soft_task), %o2
F0054CF4: 80a22000                 cmp     %o0, 0
F0054CF8: 02800004                 be      loc_F0054D08
F0054CFC: 113c043d                 sethi   %hi(aIpcInit), %o0! "ipc_init"
F0054D00: 7fff011c                 call    _panic
F0054D04: 90122008                 bset    %lo(aIpcInit), %o0! "ipc_init"
F0054D08: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0054D0C: d6042328                 ld      [%l0+0x328], %o3
F0054D10: 9207bff4                 add     %fp, var_C, %o1
F0054D14: d802e00c                 ld      [%o3+0xC], %o4
F0054D18: 9407bff0                 add     %fp, var_10, %o2
F0054D1C: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0054D20: 173c04ef                 sethi   %hi(_ipc_soft_map), %o3
F0054D24: d822e320                 st      %o4, [%o3+%lo(_ipc_soft_map)]
F0054D28: 173c043c                 sethi   %hi(_ipc_kernel_map_size), %o3
F0054D2C: d602e3a8                 ld      [%o3+%lo(_ipc_kernel_map_size)], %o3
F0054D30: 4000bb28                 call    _kmem_suballoc
F0054D34: 98102001                 mov     1, %o4
F0054D38: 133c04ef                 sethi   %hi(_ipc_kernel_map), %o1
F0054D3C: 4000408c                 call    _ipc_host_init
F0054D40: d02262f8                 st      %o0, [%o1+%lo(_ipc_kernel_map)]
F0054D44: 81c7e008                 ret
F0054D48: 81e80000                 restore
