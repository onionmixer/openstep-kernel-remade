F0064F6C: 9de3bf98                 save    %sp, -0x68, %sp
F0064F70: 273c04ef                 sethi   %hi(_ipc_space_kernel), %l3
F0064F74: 7fffd8e6                 call    _ipc_port_alloc_special
F0064F78: d004e330                 ld      [%l3+%lo(_ipc_space_kernel)], %o0
F0064F7C: a2920000                 orcc    %o0, %g0, %l1
F0064F80: 32800006                 bne,a   loc_F0064F98
F0064F84: 90100011                 mov     %l1, %o0
F0064F88: 113c043e                 sethi   %hi(aIpcHostInit), %o0! "ipc_host_init"
F0064F8C: 7ffec079                 call    _panic
F0064F90: 90122108                 bset    %lo(aIpcHostInit), %o0! "ipc_host_init"
F0064F94: 90100011                 mov     %l1, %o0
F0064F98: 213c04d4a4142170         set     _realhost, %l2
F0064FA0: 92100012                 mov     %l2, %o1
F0064FA4: 4000021f                 call    _ipc_kobject_set
F0064FA8: 94102003                 mov     3, %o2
F0064FAC: d004e330                 ld      [%l3+0x330], %o0
F0064FB0: 7fffd8d7                 call    _ipc_port_alloc_special
F0064FB4: e2242170                 st      %l1, [%l0+0x170]
F0064FB8: a2920000                 orcc    %o0, %g0, %l1
F0064FBC: 32800006                 bne,a   loc_F0064FD4
F0064FC0: 90100011                 mov     %l1, %o0
F0064FC4: 113c043e                 sethi   %hi(aIpcHostInit_0), %o0! "ipc_host_init"
F0064FC8: 7ffec06a                 call    _panic
F0064FCC: 90122118                 bset    %lo(aIpcHostInit_0), %o0! "ipc_host_init"
F0064FD0: 90100011                 mov     %l1, %o0
F0064FD4: 92100012                 mov     %l2, %o1
F0064FD8: 40000212                 call    _ipc_kobject_set
F0064FDC: 94102004                 mov     4, %o2
F0064FE0: e224a004                 st      %l1, [%l2+4]
F0064FE4: 213c04d3a01423c0         set     _default_pset, %l0
F0064FEC: 40000030                 call    _ipc_pset_init
F0064FF0: 90100010                 mov     %l0, %o0
F0064FF4: 40000044                 call    _ipc_pset_enable
F0064FF8: 90100010                 mov     %l0, %o0
F0064FFC: 113c04d8                 sethi   %hi(_master_processor), %o0
F0065000: 4000001a                 call    _ipc_processor_init
F0065004: d00223d0                 ld      [%o0+%lo(_master_processor)], %o0
F0065008: 81c7e008                 ret
F006500C: 81e80000                 restore
