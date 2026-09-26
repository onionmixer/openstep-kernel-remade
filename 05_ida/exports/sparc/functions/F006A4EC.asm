F006A4EC: 9de3bf98                 save    %sp, -0x68, %sp
F006A4F0: 4000b4e6                 call    _clock_timer_init
F006A4F4: 213c04f0                 sethi   -0xFEC4000, %l0
F006A4F8: 7ffea254                 call    _rqinit
F006A4FC: 01000000                 nop
F006A500: 400019a7                 call    _sched_init
F006A504: 01000000                 nop
F006A508: 400063ea                 call    _vm_mem_init
F006A50C: 01000000                 nop
F006A510: 7ffffdf0                 call    _mach_clock_bootstrap
F006A514: 01000000                 nop
F006A518: 400034f8                 call    _init_timers
F006A51C: 01000000                 nop
F006A520: 7ffffd70                 call    _init_timeout
F006A524: 01000000                 nop
F006A528: 113c04f0                 sethi   %hi(_virtual_avail), %o0
F006A52C: 40010172                 call    _startup
F006A530: d0022110                 ld      [%o0+%lo(_virtual_avail)], %o0
F006A534: 133c04f094126040         set     _machine_info, %o2
F006A53C: 90102001                 mov     1, %o0
F006A540: d022a008                 st      %o0, [%o2+8]
F006A544: c022a00c                 clr     [%o2+0xC]
F006A548: 90102004                 mov     4, %o0
F006A54C: d0226040                 st      %o0, [%o1+0x40]
F006A550: c022a004                 clr     [%o2+4]
F006A554: 113c04f0                 sethi   %hi(_mem_size), %o0
F006A558: 130003ff                 sethi   0xFFC00, %o1
F006A55C: d0022108                 ld      [%o0+%lo(_mem_size)], %o0
F006A560: 921263ff                 bset    0x3FF, %o1! child_act
F006A564: 90020009                 add     %o0, %o1, %o0
F006A568: 91322014                 srl     %o0, 20, %o0
F006A56C: 912a2014                 sll     %o0, 20, %o0
F006A570: 7ffe8de2                 call    _uzone_init
F006A574: d022a010                 st      %o0, [%o2+0x10]
F006A578: 7fffa97c                 call    _ipc_bootstrap
F006A57C: 01000000                 nop
F006A580: 113c04d0                 sethi   %hi(_master_cpu), %o0
F006A584: 4000066b                 call    _cpu_up
F006A588: d00220c8                 ld      [%o0+%lo(_master_cpu)], %o0
F006A58C: 40000587                 call    _mach_net_init
F006A590: 01000000                 nop
F006A594: 4000221c                 call    _task_init
F006A598: 01000000                 nop
F006A59C: 40002695                 call    _thread_init
F006A5A0: 01000000                 nop
F006A5A4: 40002fa4                 call    _swapper_init
F006A5A8: 01000000                 nop
F006A5AC: 7fffa9cc                 call    _ipc_init
F006A5B0: 01000000                 nop
F006A5B4: 40008749                 call    _vnode_pager_init
F006A5B8: 01000000                 nop
F006A5BC: 113c0442                 sethi   %hi(_kernel_task), %o0
F006A5C0: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0! parent_task
F006A5C4: 400026d0                 call    _thread_create
F006A5C8: 921420f8                 or      %l0, 0xF8, %o1
F006A5CC: 40002778                 call    _thread_deallocate
F006A5D0: d00420f8                 ld      [%l0+0xF8], %o0
F006A5D4: 133c0024                 sethi   %hi(_main), %o1
F006A5D8: d00420f8                 ld      [%l0+0xF8], %o0
F006A5DC: 40002d12                 call    _thread_start
F006A5E0: 921261a0                 bset    %lo(_main), %o1
F006A5E4: 40002fc4                 call    _thread_doswapin
F006A5E8: d00420f8                 ld      [%l0+0xF8], %o0
F006A5EC: d00420f8                 ld      [%l0+0xF8], %o0! target_act
F006A5F0: d202204c                 ld      [%o0+0x4C], %o1
F006A5F4: 92126004                 bset    4, %o1
F006A5F8: 40002be8                 call    _thread_resume
F006A5FC: d222204c                 st      %o1, [%o0+0x4C]
F006A600: 4000b1bf                 call    _splvm
F006A604: 01000000                 nop
F006A608: a2100008                 mov     %o0, %l1
F006A60C: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F006A610: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F006A614: d20420f8                 ld      [%l0+0xF8], %o1
F006A618: 4000d3fa                 call    _pmap_activate
F006A61C: 94102000                 mov     0, %o2
F006A620: 4000b1c1                 call    _splx
F006A624: 90100011                 mov     %l1, %o0
F006A628: 40009719                 call    _dev_server_init
F006A62C: 01000000                 nop
F006A630: 40000e06                 call    _miniMonInit
F006A634: 01000000                 nop
F006A638: f00420f8                 ld      [%l0+0xF8], %i0
F006A63C: 81c7e008                 ret
F006A640: 81e80000                 restore
