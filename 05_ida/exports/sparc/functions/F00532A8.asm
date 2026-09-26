F00532A8: 9de3bf98                 save    %sp, -0x68, %sp
F00532AC: 40005371                 call    _kalloc
F00532B0: 9010200c                 mov     0xC, %o0! void *
F00532B4: a0100008                 mov     %o0, %l0
F00532B8: 400106e8                 call    _bzero
F00532BC: 9210200c                 mov     0xC, %o1
F00532C0: 9010200a                 mov     0xA, %o0
F00532C4: d0340000                 sth     %o0, [%l0]
F00532C8: d0062030                 ld      [%i0+0x30], %o0
F00532CC: d0022048                 ld      [%o0+0x48], %o0
F00532D0: d0242004                 st      %o0, [%l0+4]
F00532D4: d0062030                 ld      [%i0+0x30], %o0
F00532D8: d00220d0                 ld      [%o0+0xD0], %o0
F00532DC: d0242008                 st      %o0, [%l0+8]
F00532E0: e0264000                 st      %l0, [%i1]
F00532E4: 81c7e008                 ret
F00532E8: 91e82000                 restore %g0, 0, %o0
