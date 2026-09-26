F0070B9C: 9de3bf98                 save    %sp, -0x68, %sp
F0070BA0: 113c04f190122040         set     _recompute_priorities_timer, %o0
F0070BA8: 133c01c6921261c8         set     _recompute_priorities, %o1! int
F0070BB0: d2222028                 st      %o1, [%o0+0x28]
F0070BB4: 7fffe37f                 call    _init_timeout_element
F0070BB8: c022202c                 clr     [%o0+0x2C]
F0070BBC: 113c043e                 sethi   %hi(_hz), %o0
F0070BC0: d00223e0                 ld      [%o0+%lo(_hz)], %o0! int
F0070BC4: 7ffe5691                 call    _div
F0070BC8: 9210200a                 mov     0xA, %o1
F0070BCC: 133c04f0                 sethi   %hi(_min_quantum), %o1
F0070BD0: 7fffffe2                 call    _wait_queue_init
F0070BD4: d0226290                 st      %o0, [%o1+%lo(_min_quantum)]
F0070BD8: 7ffff836                 call    _pset_sys_bootstrap
F0070BDC: 01000000                 nop
F0070BE0: 133c04f0901261b0         set     _action_queue, %o0
F0070BE8: d0222004                 st      %o0, [%o0+4]
F0070BEC: d02261b0                 st      %o0, [%o1+0x1B0]
F0070BF0: 113c04f0                 sethi   %hi(_action_lock), %o0
F0070BF4: c02221a8                 clr     [%o0+%lo(_action_lock)]
F0070BF8: 113c04f0                 sethi   %hi(_sched_tick), %o0
F0070BFC: c0222298                 clr     [%o0+%lo(_sched_tick)]
F0070C00: 113c04f1                 sethi   %hi(_sched_usec), %o0
F0070C04: 7fffcb2e                 call    _ast_init
F0070C08: c0222080                 clr     [%o0+%lo(_sched_usec)]
F0070C0C: 81c7e008                 ret
F0070C10: 81e80000                 restore
