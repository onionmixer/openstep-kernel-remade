F0065010: 9de3bf98                 save    %sp, -0x68, %sp
F0065014: 113c04d4                 sethi   %hi(_realhost), %o0
F0065018: 7fffd7f3                 call    _ipc_port_make_send
F006501C: d0022170                 ld      [%o0+%lo(_realhost)], %o0
F0065020: 133c04d0                 sethi   %hi(_active_threads), %o1
F0065024: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0065028: d202600c                 ld      [%o1+0xC], %o1
F006502C: 7fffd822                 call    _ipc_port_copyout_send
F0065030: d2026088                 ld      [%o1+0x88], %o1
F0065034: 81c7e008                 ret
F0065038: 91e80008                 restore %g0, %o0, %o0
