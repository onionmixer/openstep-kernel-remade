F00672B0: 9de3bf98                 save    %sp, -0x68, %sp
F00672B4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00672B8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00672BC: e002200c                 ld      [%o0+0xC], %l0
F00672C0: 7fffff51                 call    _retrieve_task_self_fast
F00672C4: 90100010                 mov     %l0, %o0
F00672C8: 7fffd092                 call    _ipc_port_copyout_send_compat
F00672CC: d2042088                 ld      [%l0+0x88], %o1
F00672D0: 81c7e008                 ret
F00672D4: 91e80008                 restore %g0, %o0, %o0
