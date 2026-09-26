F006716C: 9de3bf98                 save    %sp, -0x68, %sp
F0067170: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067174: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067178: 7fffffcb                 call    _retrieve_thread_self_fast
F006717C: e002200c                 ld      [%o0+0xC], %l0
F0067180: 7fffcfcd                 call    _ipc_port_copyout_send
F0067184: d2042088                 ld      [%l0+0x88], %o1
F0067188: 81c7e008                 ret
F006718C: 91e80008                 restore %g0, %o0, %o0
