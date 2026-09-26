F008AC28: 9de3bf98                 save    %sp, -0x68, %sp
F008AC2C: 113c04f6a0122198         set     _vstruct_lock, %l0
F008AC34: d0040000                 ld      [%l0], %o0
F008AC38: 80a22000                 cmp     %o0, 0
F008AC3C: 12bffffe                 bne     loc_F008AC34
F008AC40: 01000000                 nop
F008AC44: 40003099                 call    _simple_lock_try
F008AC48: 90100010                 mov     %l0, %o0
F008AC4C: 80a22000                 cmp     %o0, 0
F008AC50: 02bffff9                 be      loc_F008AC34
F008AC54: 01000000                 nop
F008AC58: d016200e                 lduh    [%i0+0xE], %o0
F008AC5C: 90023fff                 inc     -1, %o0
F008AC60: d036200e                 sth     %o0, [%i0+0xE]
F008AC64: 113c04f6                 sethi   %hi(_vstruct_lock), %o0
F008AC68: c0222198                 clr     [%o0+%lo(_vstruct_lock)]
F008AC6C: 81c7e008                 ret
F008AC70: 81e80000                 restore
