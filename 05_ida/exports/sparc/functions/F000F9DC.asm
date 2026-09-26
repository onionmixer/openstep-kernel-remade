F000F9DC: 9de3bf98                 save    %sp, -0x68, %sp
F000F9E0: 400161a4                 call    _kalloc
F000F9E4: 9010202a                 mov     0x2A, %o0! void *
F000F9E8: b0100008                 mov     %o0, %i0
F000F9EC: 4002151b                 call    _bzero
F000F9F0: 9210202a                 mov     0x2A, %o1 ! '*'
F000F9F4: d2160000                 lduh    [%i0], %o1
F000F9F8: 153c042c                 sethi   %hi(_cractive), %o2
F000F9FC: d002a1c8                 ld      [%o2+%lo(_cractive)], %o0
F000FA00: 92026001                 inc     %o1
F000FA04: d2360000                 sth     %o1, [%i0]
F000FA08: 90022001                 inc     %o0
F000FA0C: d022a1c8                 st      %o0, [%o2+%lo(_cractive)]
F000FA10: 81c7e008                 ret
F000FA14: 81e80000                 restore
