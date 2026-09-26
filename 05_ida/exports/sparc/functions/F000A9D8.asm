F000A9D8: 9de3bf98                 save    %sp, -0x68, %sp
F000A9DC: 113c04d0                 sethi   %hi(_active_threads), %o0
F000A9E0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000A9E4: d002200c                 ld      [%o0+0xC], %o0
F000A9E8: d0022038                 ld      [%o0+0x38], %o0
F000A9EC: 40000363                 call    _expand_fdlist
F000A9F0: 92100018                 mov     %i0, %o1
F000A9F4: 153c04cf                 sethi   %hi(_active_u), %o2
F000A9F8: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000A9FC: d202214c                 ld      [%o0+0x14C], %o1
F000AA00: 912e2002                 sll     %i0, 2, %o0
F000AA04: f2224008                 st      %i1, [%o1+%o0]
F000AA08: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000AA0C: d0022150                 ld      [%o0+0x150], %o0
F000AA10: b40ebffe                 and     %i2, -2, %i2
F000AA14: f42a0018                 stb     %i2, [%o0+%i0]
F000AA18: d016600e                 lduh    [%i1+0xE], %o0
F000AA1C: 90022001                 inc     %o0
F000AA20: d036600e                 sth     %o0, [%i1+0xE]
F000AA24: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F000AA28: d0026154                 ld      [%o1+0x154], %o0
F000AA2C: 80a60008                 cmp     %i0, %o0
F000AA30: 34800002                 bg,a    locret_F000AA38
F000AA34: f0226154                 st      %i0, [%o1+0x154]
F000AA38: 81c7e008                 ret
F000AA3C: 81e80000                 restore
