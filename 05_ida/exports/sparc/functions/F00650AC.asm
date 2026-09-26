F00650AC: 9de3bf98                 save    %sp, -0x68, %sp
F00650B0: 233c04ef                 sethi   %hi(_ipc_space_kernel), %l1
F00650B4: 7fffd896                 call    _ipc_port_alloc_special
F00650B8: d0046330                 ld      [%l1+%lo(_ipc_space_kernel)], %o0
F00650BC: a0920000                 orcc    %o0, %g0, %l0
F00650C0: 32800006                 bne,a   loc_F00650D8
F00650C4: d0046330                 ld      [%l1+%lo(_ipc_space_kernel)], %o0
F00650C8: 113c043e                 sethi   %hi(aIpcPsetInit), %o0! "ipc_pset_init"
F00650CC: 7ffec029                 call    _panic
F00650D0: 90122140                 bset    %lo(aIpcPsetInit), %o0! "ipc_pset_init"
F00650D4: d0046330                 ld      [%l1+%lo(_ipc_space_kernel)], %o0
F00650D8: 7fffd88d                 call    _ipc_port_alloc_special
F00650DC: e026215c                 st      %l0, [%i0+0x15C]
F00650E0: a0920000                 orcc    %o0, %g0, %l0
F00650E4: 32800006                 bne,a   locret_F00650FC
F00650E8: e0262160                 st      %l0, [%i0+0x160]
F00650EC: 113c043e                 sethi   %hi(aIpcPsetInit_0), %o0! "ipc_pset_init"
F00650F0: 7ffec020                 call    _panic
F00650F4: 90122150                 bset    %lo(aIpcPsetInit_0), %o0! "ipc_pset_init"
F00650F8: e0262160                 st      %l0, [%i0+0x160]
F00650FC: 81c7e008                 ret
F0065100: 81e80000                 restore
