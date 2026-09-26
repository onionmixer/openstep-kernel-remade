F00672D8: 9de3bf98                 save    %sp, -0x68, %sp
F00672DC: 113c04d0                 sethi   %hi(_active_threads), %o0
F00672E0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00672E4: e002200c                 ld      [%o0+0xC], %l0
F00672E8: 7fffffbc                 call    _retrieve_task_notify
F00672EC: 90100010                 mov     %l0, %o0
F00672F0: 7fffd09d                 call    _ipc_port_copyout_receiver
F00672F4: d2042088                 ld      [%l0+0x88], %o1
F00672F8: 81c7e008                 ret
F00672FC: 91e80008                 restore %g0, %o0, %o0
