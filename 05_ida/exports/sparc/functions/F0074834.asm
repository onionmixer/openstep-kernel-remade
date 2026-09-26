F0074834: 9de3bf98                 save    %sp, -0x68, %sp
F0074838: 80a62000                 cmp     %i0, 0
F007483C: 02800014                 be      locret_F007488C
F0074840: 01000000                 nop
F0074844: 400088d1                 call    _splusclock
F0074848: a0062020                 add     %i0, 0x20, %l0 ! ' '
F007484C: a2100008                 mov     %o0, %l1
F0074850: d0040000                 ld      [%l0], %o0
F0074854: 80a22000                 cmp     %o0, 0
F0074858: 12bffffe                 bne     loc_F0074850
F007485C: 01000000                 nop
F0074860: 40008992                 call    _simple_lock_try
F0074864: 90100010                 mov     %l0, %o0
F0074868: 80a22000                 cmp     %o0, 0
F007486C: 02bffff9                 be      loc_F0074850
F0074870: 01000000                 nop
F0074874: c0262020                 clr     [%i0+0x20]
F0074878: d2062024                 ld      [%i0+0x24], %o1
F007487C: 90100011                 mov     %l1, %o0
F0074880: 92026001                 inc     %o1
F0074884: 40008928                 call    _splx
F0074888: d2262024                 st      %o1, [%i0+0x24]
F007488C: 81c7e008                 ret
F0074890: 81e80000                 restore
