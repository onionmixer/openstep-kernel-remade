F009BFE4: 9de3bf98                 save    %sp, -0x68, %sp
F009BFE8: 113c04d0                 sethi   %hi(_active_threads), %o0
F009BFEC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F009BFF0: d0022028                 ld      [%o0+0x28], %o0
F009BFF4: 4000381b                 call    _check_for_ast
F009BFF8: 90022234                 inc     0x234, %o0
F009BFFC: 7ffd9c52                 call    _return_with_state
F009C000: 01000000                 nop
F009C004: 81c7e008                 ret
F009C008: 81e80000                 restore
