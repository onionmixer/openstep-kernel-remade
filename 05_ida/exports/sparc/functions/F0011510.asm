F0011510: 9de3bf98                 save    %sp, -0x68, %sp
F0011514: 80a62000                 cmp     %i0, 0
F0011518: 02800015                 be      locret_F001156C
F001151C: 01000000                 nop
F0011520: f0062004                 ld      [%i0+4], %i0
F0011524: 80a62000                 cmp     %i0, 0
F0011528: 02800011                 be      locret_F001156C
F001152C: 21100000                 sethi   0x40000000, %l0
F0011530: 80a6a000                 cmp     %i2, 0
F0011534: 02800006                 be      loc_F001154C
F0011538: 90100018                 mov     %i0, %o0
F001153C: d0062028                 ld      [%i0+0x28], %o0
F0011540: 808a0010                 btst    %l0, %o0
F0011544: 02800004                 be      loc_F0011554
F0011548: 90100018                 mov     %i0, %o0! unsigned int
F001154C: 4000000a                 call    _psignal
F0011550: 92100019                 mov     %i1, %o1
F0011554: 7ffff573                 call    _get_posix_proc
F0011558: d0562030                 ldsh    [%i0+0x30], %o0
F001155C: f002200c                 ld      [%o0+0xC], %i0
F0011560: 80a62000                 cmp     %i0, 0
F0011564: 12bffff4                 bne     loc_F0011534
F0011568: 80a6a000                 cmp     %i2, 0
F001156C: 81c7e008                 ret
F0011570: 81e80000                 restore
