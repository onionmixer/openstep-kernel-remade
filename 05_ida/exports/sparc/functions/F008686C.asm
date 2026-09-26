F008686C: 9de3bf98                 save    %sp, -0x68, %sp
F0086870: 80a62000                 cmp     %i0, 0
F0086874: 0280000f                 be      locret_F00868B0
F0086878: a0062010                 add     %i0, 0x10, %l0
F008687C: d0040000                 ld      [%l0], %o0
F0086880: 80a22000                 cmp     %o0, 0
F0086884: 12bffffe                 bne     loc_F008687C
F0086888: 01000000                 nop
F008688C: 40004187                 call    _simple_lock_try
F0086890: 90100010                 mov     %l0, %o0
F0086894: 80a22000                 cmp     %o0, 0
F0086898: 02bffff9                 be      loc_F008687C
F008689C: 01000000                 nop
F00868A0: d0162018                 lduh    [%i0+0x18], %o0
F00868A4: c0262010                 clr     [%i0+0x10]
F00868A8: 90022001                 inc     %o0
F00868AC: d0362018                 sth     %o0, [%i0+0x18]
F00868B0: 81c7e008                 ret
F00868B4: 81e80000                 restore
