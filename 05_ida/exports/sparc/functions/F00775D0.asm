F00775D0: 9de3bf98                 save    %sp, -0x68, %sp
F00775D4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00775D8: 7ffff276                 call    _stack_privilege
F00775DC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00775E0: 7fffff8d                 call    sub_F0077414
F00775E4: 01000000                 nop
F00775E8: 81c7e008                 ret
F00775EC: 81e80000                 restore
