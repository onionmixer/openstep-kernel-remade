F0065204: 9de3bf98                 save    %sp, -0x68, %sp
F0065208: d006215c                 ld      [%i0+0x15C], %o0
F006520C: 213c04ef                 sethi   %hi(_ipc_space_kernel), %l0
F0065210: 7fffd853                 call    _ipc_port_dealloc_special
F0065214: d2042330                 ld      [%l0+%lo(_ipc_space_kernel)], %o1
F0065218: d0062160                 ld      [%i0+0x160], %o0
F006521C: 7fffd850                 call    _ipc_port_dealloc_special
F0065220: d2042330                 ld      [%l0+%lo(_ipc_space_kernel)], %o1
F0065224: 81c7e008                 ret
F0065228: 81e80000                 restore
