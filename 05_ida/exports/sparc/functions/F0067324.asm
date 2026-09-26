F0067324: 9de3bf98                 save    %sp, -0x68, %sp
F0067328: 113c04d0                 sethi   %hi(_active_threads), %o0
F006732C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067330: 7fffffc5                 call    _retrieve_thread_reply
F0067334: e002200c                 ld      [%o0+0xC], %l0
F0067338: 7fffd08b                 call    _ipc_port_copyout_receiver
F006733C: d2042088                 ld      [%l0+0x88], %o1
F0067340: 81c7e008                 ret
F0067344: 91e80008                 restore %g0, %o0, %o0
