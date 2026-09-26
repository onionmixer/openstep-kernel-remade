F009C00C: 9de3bf98                 save    %sp, -0x68, %sp
F009C010: 113c04d0                 sethi   %hi(_active_threads), %o0
F009C014: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F009C018: d0022028                 ld      [%o0+0x28], %o0
F009C01C: f0222260                 st      %i0, [%o0+0x260]
F009C020: 40003810                 call    _check_for_ast
F009C024: 90022234                 inc     0x234, %o0
F009C028: 7ffd9c47                 call    _return_with_state
F009C02C: 01000000                 nop
F009C030: 81c7e008                 ret
F009C034: 81e80000                 restore
