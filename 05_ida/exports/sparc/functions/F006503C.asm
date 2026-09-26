F006503C: 9de3bf98                 save    %sp, -0x68, %sp
F0065040: 113c04d4                 sethi   %hi(_realhost), %o0
F0065044: 7fffd7e8                 call    _ipc_port_make_send
F0065048: d0022170                 ld      [%o0+%lo(_realhost)], %o0
F006504C: 133c04d0                 sethi   %hi(_active_threads), %o1
F0065050: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0065054: d202600c                 ld      [%o1+0xC], %o1
F0065058: 7fffd92e                 call    _ipc_port_copyout_send_compat
F006505C: d2026088                 ld      [%o1+0x88], %o1
F0065060: 81c7e008                 ret
F0065064: 91e80008                 restore %g0, %o0, %o0
