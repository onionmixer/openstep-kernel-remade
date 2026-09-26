F0068D70: 9de3bf98                 save    %sp, -0x68, %sp
F0068D74: a0062008                 add     %i0, 8, %l0
F0068D78: d0040000                 ld      [%l0], %o0
F0068D7C: 80a22000                 cmp     %o0, 0
F0068D80: 12bffffe                 bne     loc_F0068D78
F0068D84: 01000000                 nop
F0068D88: 4000b848                 call    _simple_lock_try
F0068D8C: 90100010                 mov     %l0, %o0
F0068D90: 80a22000                 cmp     %o0, 0
F0068D94: 02bffff9                 be      loc_F0068D78
F0068D98: 01000000                 nop
F0068D9C: c0262008                 clr     [%i0+8]
F0068DA0: d0062004                 ld      [%i0+4], %o0
F0068DA4: 13000004                 sethi   0x1000, %o1
F0068DA8: 922a0009                 andn    %o0, %o1, %o1
F0068DAC: 900e6001                 and     %i1, 1, %o0
F0068DB0: 912a200c                 sll     %o0, 12, %o0
F0068DB4: 92124008                 bset    %o0, %o1
F0068DB8: d2262004                 st      %o1, [%i0+4]
F0068DBC: 81c7e008                 ret
F0068DC0: 81e80000                 restore
