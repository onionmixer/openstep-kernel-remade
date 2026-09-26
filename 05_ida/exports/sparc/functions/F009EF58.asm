F009EF58: 9de3bf98                 save    %sp, -0x68, %sp
F009EF5C: 133c04f792126270         set     _pmap_info, %o1
F009EF64: d0026084                 ld      [%o1+0x84], %o0
F009EF68: a0062018                 add     %i0, 0x18, %l0
F009EF6C: 90022001                 inc     %o0
F009EF70: 7fffdf63                 call    _splvm
F009EF74: d0226084                 st      %o0, [%o1+0x84]
F009EF78: a2100008                 mov     %o0, %l1
F009EF7C: d0040000                 ld      [%l0], %o0
F009EF80: 80a22000                 cmp     %o0, 0
F009EF84: 12bffffe                 bne     loc_F009EF7C
F009EF88: 01000000                 nop
F009EF8C: 7fffdfc7                 call    _simple_lock_try
F009EF90: 90100010                 mov     %l0, %o0
F009EF94: 80a22000                 cmp     %o0, 0
F009EF98: 02bffff9                 be      loc_F009EF7C
F009EF9C: 90100018                 mov     %i0, %o0
F009EFA0: 7fffffb9                 call    _pmap_resident_extract
F009EFA4: 92100019                 mov     %i1, %o1
F009EFA8: c0262018                 clr     [%i0+0x18]
F009EFAC: b0100008                 mov     %o0, %i0
F009EFB0: 7fffdf5d                 call    _splx
F009EFB4: 90100011                 mov     %l1, %o0
F009EFB8: 81c7e008                 ret
F009EFBC: 81e80000                 restore
