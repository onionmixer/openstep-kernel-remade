F0066854: 9de3bf98                 save    %sp, -0x68, %sp
F0066858: 4000c0cc                 call    _splusclock
F006685C: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0066860: a2100008                 mov     %o0, %l1
F0066864: d0040000                 ld      [%l0], %o0
F0066868: 80a22000                 cmp     %o0, 0
F006686C: 12bffffe                 bne     loc_F0066864
F0066870: 01000000                 nop
F0066874: 4000c18d                 call    _simple_lock_try
F0066878: 90100010                 mov     %l0, %o0
F006687C: 80a22000                 cmp     %o0, 0
F0066880: 02bffff9                 be      loc_F0066864
F0066884: 01000000                 nop
F0066888: c0262020                 clr     [%i0+0x20]
F006688C: d206204c                 ld      [%i0+0x4C], %o1
F0066890: 90100011                 mov     %l1, %o0
F0066894: 92126001                 bset    1, %o1
F0066898: 4000c123                 call    _splx
F006689C: d226204c                 st      %o1, [%i0+0x4C]
F00668A0: 81c7e008                 ret
F00668A4: 81e80000                 restore
