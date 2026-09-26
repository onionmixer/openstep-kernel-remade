F008AC74: 9de3bf98                 save    %sp, -0x68, %sp
F008AC78: 113c04f6a0122198         set     _vstruct_lock, %l0
F008AC80: d0040000                 ld      [%l0], %o0
F008AC84: 80a22000                 cmp     %o0, 0
F008AC88: 12bffffe                 bne     loc_F008AC80
F008AC8C: 01000000                 nop
F008AC90: 40003086                 call    _simple_lock_try
F008AC94: 90100010                 mov     %l0, %o0
F008AC98: 80a22000                 cmp     %o0, 0
F008AC9C: 02bffff9                 be      loc_F008AC80
F008ACA0: 01000000                 nop
F008ACA4: d016200e                 lduh    [%i0+0xE], %o0
F008ACA8: 90022001                 inc     %o0
F008ACAC: d036200e                 sth     %o0, [%i0+0xE]
F008ACB0: 113c04f6                 sethi   %hi(_vstruct_lock), %o0
F008ACB4: c0222198                 clr     [%o0+%lo(_vstruct_lock)]
F008ACB8: f0062014                 ld      [%i0+0x14], %i0
F008ACBC: 81c7e008                 ret
F008ACC0: 81e80000                 restore
