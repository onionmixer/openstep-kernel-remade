F0072428: 9de3bf98                 save    %sp, -0x68, %sp
F007242C: 133c04d0                 sethi   %hi(_active_threads), %o1
F0072430: d4026260                 ld      [%o1+%lo(_active_threads)], %o2
F0072434: 90102000                 mov     0, %o0
F0072438: 133c04f1                 sethi   %hi(_sched_thread_id), %o1
F007243C: d4226078                 st      %o2, [%o1+%lo(_sched_thread_id)]
F0072440: 7ffffa25                 call    _assert_wait
F0072444: 92102000                 mov     0, %o1
F0072448: 113c01c8                 sethi   %hi(_sched_thread_continue), %o0
F007244C: 7ffffcbd                 call    _thread_block_with_continuation
F0072450: 901223dc                 bset    %lo(_sched_thread_continue), %o0
F0072454: 7fffffe2                 call    _sched_thread_continue
F0072458: 01000000                 nop
F007245C: 81c7e008                 ret
F0072460: 81e80000                 restore
