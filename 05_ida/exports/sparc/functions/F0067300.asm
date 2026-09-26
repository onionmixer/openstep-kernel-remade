F0067300: 9de3bf98                 save    %sp, -0x68, %sp
F0067304: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067308: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F006730C: 7fffff66                 call    _retrieve_thread_self_fast
F0067310: e002200c                 ld      [%o0+0xC], %l0
F0067314: 7fffd07f                 call    _ipc_port_copyout_send_compat
F0067318: d2042088                 ld      [%l0+0x88], %o1
F006731C: 81c7e008                 ret
F0067320: 91e80008                 restore %g0, %o0, %o0
