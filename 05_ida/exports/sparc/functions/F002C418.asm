F002C418: 9de3bf98                 save    %sp, -0x68, %sp
F002C41C: 113c04d0                 sethi   %hi(_active_threads), %o0
F002C420: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F002C424: 40011ee3                 call    _stack_privilege
F002C428: 90100010                 mov     %l0, %o0
F002C42C: 113c04d8                 sethi   %hi(_master_processor), %o0
F002C430: d20223d0                 ld      [%o0+%lo(_master_processor)], %o1
F002C434: 4001136b                 call    _thread_bind
F002C438: 90100010                 mov     %l0, %o0
F002C43C: 113c00b0                 sethi   %hi(_netisr_thread_continue), %o0
F002C440: 400114c0                 call    _thread_block_with_continuation
F002C444: 9012238c                 bset    %lo(_netisr_thread_continue), %o0
F002C448: 81c7e008                 ret
F002C44C: 81e80000                 restore
