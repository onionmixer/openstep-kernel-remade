F000D8A4: 9de3bf98                 save    %sp, -0x68, %sp
F000D8A8: 400004b9                 call    _alloc_posix_proc
F000D8AC: 01000000                 nop
F000D8B0: 133c04cf                 sethi   %hi(_active_u), %o1
F000D8B4: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F000D8B8: 94100008                 mov     %o0, %o2
F000D8BC: d0024000                 ld      [%o1], %o0
F000D8C0: 40000004                 call    _cloneproc
F000D8C4: 92100018                 mov     %i0, %o1
F000D8C8: 81c7e008                 ret
F000D8CC: 91e80008                 restore %g0, %o0, %o0
