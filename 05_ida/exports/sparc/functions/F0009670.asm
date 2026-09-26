F0009670: 9de3bf98                 save    %sp, -0x68, %sp
F0009674: 113c042a                 sethi   %hi(aInit), %o0! "init"
F0009678: 7ffffeb9                 call    _task_name
F000967C: 90122000                 bset    %lo(aInit), %o0! "init"
F0009680: 113c04d0                 sethi   %hi(_active_threads), %o0
F0009684: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0009688: d0022028                 ld      [%o0+0x28], %o0
F000968C: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0009690: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0009694: 90022234                 inc     0x234, %o0
F0009698: 40000b56                 call    _load_init_program
F000969C: d0224000                 st      %o0, [%o1]
F00096A0: 40024a51                 call    _thread_exception_return
F00096A4: 01000000                 nop
F00096A8: 81c7e008                 ret
F00096AC: 81e80000                 restore
