F0076658: 9de3bf98                 save    %sp, -0x68, %sp
F007665C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0076660: 7ffff654                 call    _stack_privilege
F0076664: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0076668: 7fffffc1                 call    _swapin_thread_continue
F007666C: 01000000                 nop
F0076670: 81c7e008                 ret
F0076674: 81e80000                 restore
