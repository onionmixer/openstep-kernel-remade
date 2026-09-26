F0046180: 9de3bf98                 save    %sp, -0x68, %sp
F0046184: a0100018                 mov     %i0, %l0
F0046188: d0042014                 ld      [%l0+0x14], %o0
F004618C: 90023ffc                 inc     -4, %o0
F0046190: 80a22000                 cmp     %o0, 0
F0046194: 16800004                 bge     loc_F00461A4
F0046198: d0242014                 st      %o0, [%l0+0x14]
F004619C: 10800012                 ba      locret_F00461E4
F00461A0: b0102000                 mov     0, %i0
F00461A4: d204200c                 ld      [%l0+0xC], %o1! void *
F00461A8: 808a6003                 btst    3, %o1
F00461AC: 12800005                 bne     loc_F00461C0
F00461B0: 90100019                 mov     %i1, %o0
F00461B4: 808e6003                 btst    3, %i1
F00461B8: 22800006                 be,a    loc_F00461D0
F00461BC: d0064000                 ld      [%i1], %o0! void *
F00461C0: 40013a54                 call    _bcopy
F00461C4: 94102004                 mov     4, %o2
F00461C8: 10800004                 ba      loc_F00461D8
F00461CC: d004200c                 ld      [%l0+0xC], %o0
F00461D0: d0224000                 st      %o0, [%o1]
F00461D4: d004200c                 ld      [%l0+0xC], %o0
F00461D8: b0102001                 mov     1, %i0
F00461DC: 90022004                 inc     4, %o0
F00461E0: d024200c                 st      %o0, [%l0+0xC]
F00461E4: 81c7e008                 ret
F00461E8: 81e80000                 restore
