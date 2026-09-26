F0067144: 9de3bf98                 save    %sp, -0x68, %sp
F0067148: 113c04d0                 sethi   %hi(_active_threads), %o0
F006714C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067150: e002200c                 ld      [%o0+0xC], %l0
F0067154: 7fffffac                 call    _retrieve_task_self_fast
F0067158: 90100010                 mov     %l0, %o0
F006715C: 7fffcfd6                 call    _ipc_port_copyout_send
F0067160: d2042088                 ld      [%l0+0x88], %o1
F0067164: 81c7e008                 ret
F0067168: 91e80008                 restore %g0, %o0, %o0
