F009C948: 9de3bf98                 save    %sp, -0x68, %sp
F009C94C: 133c04f792126270         set     _pmap_info, %o1
F009C954: d0026044                 ld      [%o1+0x44], %o0
F009C958: 80a62000                 cmp     %i0, 0
F009C95C: 90022001                 inc     %o0
F009C960: 02800014                 be      locret_F009C9B0
F009C964: d0226044                 st      %o0, [%o1+0x44]
F009C968: 7fffe8e5                 call    _splvm
F009C96C: a0062018                 add     %i0, 0x18, %l0
F009C970: a2100008                 mov     %o0, %l1
F009C974: d0040000                 ld      [%l0], %o0
F009C978: 80a22000                 cmp     %o0, 0
F009C97C: 12bffffe                 bne     loc_F009C974
F009C980: 01000000                 nop
F009C984: 7fffe949                 call    _simple_lock_try
F009C988: 90100010                 mov     %l0, %o0
F009C98C: 80a22000                 cmp     %o0, 0
F009C990: 02bffff9                 be      loc_F009C974
F009C994: 01000000                 nop
F009C998: c0262018                 clr     [%i0+0x18]
F009C99C: d206201c                 ld      [%i0+0x1C], %o1
F009C9A0: 90100011                 mov     %l1, %o0
F009C9A4: 92026001                 inc     %o1
F009C9A8: 7fffe8df                 call    _splx
F009C9AC: d226201c                 st      %o1, [%i0+0x1C]
F009C9B0: 81c7e008                 ret
F009C9B4: 81e80000                 restore
