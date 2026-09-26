F00C9D50: 9de3bf90                 save    %sp, -0x70, %sp
F00C9D54: d0062004                 ld      [%i0+4], %o0
F00C9D58: e0020000                 ld      [%o0], %l0
F00C9D5C: d0040000                 ld      [%l0], %o0
F00C9D60: 80a22000                 cmp     %o0, 0
F00C9D64: 12bffffe                 bne     loc_F00C9D5C
F00C9D68: 01000000                 nop
F00C9D6C: 7fff344f                 call    _simple_lock_try
F00C9D70: 90100010                 mov     %l0, %o0
F00C9D74: 80a22000                 cmp     %o0, 0
F00C9D78: 02bffff9                 be      loc_F00C9D5C
F00C9D7C: 01000000                 nop
F00C9D80: 81c7e008                 ret
F00C9D84: 81e80000                 restore
