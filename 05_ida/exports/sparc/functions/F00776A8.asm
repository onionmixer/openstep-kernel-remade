F00776A8: 9de3bf98                 save    %sp, -0x68, %sp
F00776AC: 113c04d0                 sethi   %hi(_active_threads), %o0
F00776B0: 7ffff240                 call    _stack_privilege
F00776B4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00776B8: 7fffffce                 call    sub_F00775F0
F00776BC: 01000000                 nop
F00776C0: 81c7e008                 ret
F00776C4: 81e80000                 restore
