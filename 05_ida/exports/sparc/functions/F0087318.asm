F0087318: 9de3bf98                 save    %sp, -0x68, %sp
F008731C: a0062010                 add     %i0, 0x10, %l0
F0087320: d0040000                 ld      [%l0], %o0
F0087324: 80a22000                 cmp     %o0, 0
F0087328: 12bffffe                 bne     loc_F0087320
F008732C: 01000000                 nop
F0087330: 40003ede                 call    _simple_lock_try
F0087334: 90100010                 mov     %l0, %o0
F0087338: 80a22000                 cmp     %o0, 0
F008733C: 02bffff9                 be      loc_F0087320
F0087340: 01000000                 nop
F0087344: f2262028                 st      %i1, [%i0+0x28]
F0087348: f426202c                 st      %i2, [%i0+0x2C]
F008734C: c0262010                 clr     [%i0+0x10]
F0087350: 81c7e008                 ret
F0087354: 81e80000                 restore
